#!/bin/bash

cd "$(cd "$(dirname "$0")" ; pwd)/.."

EXEC="$1"
RUN_N="$2"

TMPF=$(mktemp /tmp/$USER.$EXEC.XXXXX)
trap cleanup EXIT
cleanup()
{
    rm -f $TMPF
}

# ------------------------------------------------- Bytes Allocated -- #
# These are the number of bytes that should be allocated
BYTES_ALLOC="2519,2799,3035,3287,3547,3790,6861,3548,3207,2971"
EXP_N_BYTES="$(echo "$BYTES_ALLOC" | awk -F',' "{ print \$$RUN_N }")"

# ------------------------------------------------- Parameters -- #
INPUT_F="$(printf inputs/input%02d $RUN_N)"

OUT_ID_F="$(printf outputs/output%02dID $RUN_N)"
OUT_NAME_F="$(printf outputs/output%02dName $RUN_N)"

# Expected
EXP_ID_F="$(printf expected/expected%02dID $RUN_N)"
EXP_NAME_F="$(printf expected/expected%02dName $RUN_N)"

# Valgrind log-file
VALGF="$(printf outputs/valgrind-log%02d $RUN_N)"

# ------------------------------------------------- Run the program -- #
# Assume that we pass the testcase unless otherwise noted
OKAY="true"

echo
echo "./$EXEC $INPUT_F $OUT_ID_F $OUT_NAME_F"
./$EXEC $INPUT_F $OUT_ID_F $OUT_NAME_F
PASS=$?
echo "Printing $INPUT_F sorted by id (i.e., cat $OUT_ID_F)"
echo
cat $OUT_ID_F | sed 's/^/   /'
echo
if ! diff -w $OUT_ID_F $EXP_ID_F 1>/dev/null ; then
    OKAY="false"
    echo "FAILED!"
else
    echo "(Sort is okay.)"
fi

echo
echo "Printing $INPUT_F sorted by Name (i.e., cat $OUT_NAME_F)"
echo
cat $OUT_NAME_F | sed 's/^/   /'
echo
if ! diff -w $OUT_NAME_F $EXP_NAME_F 1>/dev/null ; then
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
	--log-file=$VALGF ./$EXEC $INPUT_F $OUT_ID_F $OUT_NAME_F

    cat "$VALGF" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts" && VALG_OKAY=1

    (( $VALG_OKAY == 1 )) && echo "okay"
    (( $VALG_OKAY != 1 )) \
	&& echo "FAIL!" \
	&& echo "Examine the file '$VALGF' to diagnose the problem."
fi

SUP_MALLOC_OKAY=0
if (( $VALG_OKAY == 1 )) ; then
    echo -n "Checking for superfluous mallocs: - "
    NBYTES=$(cat "$VALGF" | grep "total heap usage" | sed 's,bytes allocated,,' | awk '{ print $NF }' | sed 's/,//')

    [ "$NBYTES" = "$EXP_N_BYTES" ] && SUP_MALLOC_OKAY=1
    (( $SUP_MALLOC_OKAY == 1 )) && echo "okay"
    (( $SUP_MALLOC_OKAY != 1 )) \
	&& echo "FAIL!" \
	&& echo "Your program allocated extra memory than necessary, please revisit and remove all superfluous mallocs"
    
fi

# ------------------------------------------------- Calculate exit value -- #
[ "$OKAY" = "true" ] && (( $VALG_OKAY == 1 )) && exit 0
exit 1


