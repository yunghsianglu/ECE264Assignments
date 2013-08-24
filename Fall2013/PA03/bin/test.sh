#!/bin/bash

cd "$(cd "$(dirname "$0")" ; pwd)/.."

EXEC="$1"
INF="$2"
OUTF="$3"
VALGF="$4"

TMPF=$(mktemp /tmp/$USER.$EXEC.XXXXX)
trap cleanup EXIT
cleanup()
{
    rm -f $TMPF
}

echo
echo "./$EXEC $INF > $OUTF"
./$EXEC $INF > $OUTF
PASS=$?
echo "cat $OUTF"
echo
cat $OUTF | sed 's/^/   /'
echo


# -- Check valgrind output -- #

VALG_OKAY=0

if (( $PASS == 0 )) ; then
    echo -n "Performing memory-check with valgrind: - "

    valgrind --tool=memcheck --leak-check=full --verbose \
	--log-file=$VALGF ./$EXEC $INF > $OUTF

    cat "$VALGF" | grep -q "All heap blocks were freed -- no leaks are possible" && VALG_OKAY=1
    cat "$VALGF" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts" && VALG_OKAY=1

    (( $VALG_OKAY == 1 )) && echo "okay"
    (( $VALG_OKAY != 1 )) \
	&& echo "FAIL!" \
	&& echo "Examine the file '$VALGF' to diagnose the problem."
fi

# -- Check program output -- #
OUT_OKAY=0
(( $PASS != 0 )) && OUT_OKAY=0 && echo "Testcase FAILED because of incorrect output."
(( $PASS == 0 )) && OUT_OKAY=1 && echo "Program produced the correct output"

echo

(( $OUT_OKAY == 1 )) && (( $VALG_OKAY == 1 )) && exit 0
exit 1

