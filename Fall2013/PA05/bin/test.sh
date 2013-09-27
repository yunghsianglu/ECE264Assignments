#!/bin/bash

cd "$(cd "$(dirname "$0")" ; pwd)/.."

EXEC="$1"
RUN_N="$2"

[ "$RUN_N" -ne "$RUN_N" 2>/dev/null ] && echo "Run-number not an integer, aborting" && exit 1

TMPF=$(mktemp /tmp/test.sh.$USER.XXXXXXX)
trap cleanup EXIT
cleanup()
{
    rm -f $TMPF
}

# ------------------------------------------------- Parameters -- #
INPUT_F="$(find . | grep ./inputs/$(printf %02d $RUN_N))"
OUTPUT_F="outputs/$(basename $INPUT_F).out"
EXP_F="expected/$(printf %02d $RUN_N)-expected"
VALGF="$(printf outputs/valgrind-log%02d $RUN_N)"
OPTION=i
(( $RUN_N >= 14 )) && OPTION=s

# ------------------------------------------------- Sanity check -- #
! [ -e "$INPUT_F" ] && echo "Input file not found: '$INPUT_F', aborting" && exit 1
! [ -e "$EXP_F" ] && echo "Expected file not found: '$EXP_F', aborting" && exit 1

# ------------------------------------------------- Run the program -- #
# Assume that we pass the testcase unless otherwise noted
OKAY="true"

echo
echo "./$EXEC $OPTION $INPUT_F $OUTPUT_F"
./$EXEC $OPTION $INPUT_F $OUTPUT_F
PASS=$?
echo
cat $EXP_F | sed '/^ *$/d' > $TMPF
if ! cat $OUTPUT_F | sed '/^ *$/d' | diff -w $TMPF - 1>/dev/null ; then
    OKAY="false"
    echo "FAILED!"
else
    echo "(Sort is okay.)"
fi

# ------------------------------------------------- Run through valgrind -- #
VALG_OKAY=0
if [ "$OKAY" = "true" ] ; then
    echo
    echo -n "Performing memory-check with valgrind: - "

    valgrind --tool=memcheck --leak-check=full --verbose \
	--log-file=$VALGF ./$EXEC $OPTION $INPUT_F $OUTPUT_F 1>/dev/null 2>/dev/null

    cat "$VALGF" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts" && VALG_OKAY=1

    (( $VALG_OKAY == 1 )) && echo "okay"
    (( $VALG_OKAY != 1 )) \
	&& echo "FAIL!" \
	&& echo "Examine the file '$VALGF' to diagnose the problem."
fi

# ------------------------------------------------- Calculate exit value -- #
[ "$OKAY" = "true" ] && (( $VALG_OKAY == 1 )) && exit 0
exit 1


