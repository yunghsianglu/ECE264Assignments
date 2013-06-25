#!/bin/bash

COMMAND="$1"
INFILE1="$2"
INFILE2="$3"
OUTFILE="$4"
MESSAGE="$5"

SIZE1=$(stat -c%s "$INFILE1")
BIGFILE=0
(( $SIZE1 > 1000000 )) && BIGFILE=1

BADOKAY=0
[ "$(basename $OUTFILE)" = "corrupt.ppm" ] && BADOKAY=1

[ "$MESSAGE" != "" ] && echo "$MESSAGE"
[ "$MESSAGE" == "" ] && echo "Searching for '$(basename $INFILE2 .ee264)' in '$(basename $INFILE1 .ee264)'" \
    && (( $BIGFILE )) \
    && echo "This make take some time. Fast convolutions can be done with the fourier transform."

rm -f $OUTFILE

if (( $BIGFILE )) ; then
    $COMMAND "$INFILE1" "$INFILE2" "$OUTFILE"
else
    rm -f outputs/memoutput
    valgrind --tool=memcheck --leak-check=full --verbose --log-file=outputs/memoutput \
	$COMMAND "$INFILE1" "$INFILE2" "$OUTFILE"
    RET="$?"
    (( $RET == 0 && $BADOKAY == 1 )) && echo "You are meant to return NULL when reading a corrupt image" && exit 1
    (( $RET != 0 && $BADOKAY == 0 )) && echo "Failed to read a non-corrupt image" && exit 1
    (( $RET != 0 && $BADOKAY == 1 )) && echo "Failure is okay, because we are testing a corrupt file"
    MEMOKAY=0
    $(cd "$(dirname $0)" ; pwd)/valgrind-checker.sh outputs/memoutput \
	&& MEMOKAY=1
    (( $MEMOKAY == 0 )) && exit 1
fi

check_output()
{
    FILE="$1"
    # Corrupt file testcase
    (( $BADOKAY )) && return 0 

    # File was never created
    ! [ -e "$OUTFILE" ] && return 1

    MD1=$(md5sum $OUTFILE | awk '{ print $1 }')
    MD2=$(md5sum expected/$(basename $OUTFILE) | awk '{ print $1 }')

    [ "$MD1" != "$MD2" ] \
	&& echo "Failed to find the expected output, perhaps your convolution function doesn't work" \
	&& return 1

    echo "You can use gthumb to view the result file: $OUTFILE" && \
    [ "$(hostname)" = "blakes-7" ] && feh -Z -F --force-alias $OUTFILE
    return 0
}

check_output "$OUTFILE" && echo && exit 0
exit 1

