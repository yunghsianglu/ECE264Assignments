#!/bin/bash

(( $# == 0 )) && echo "Usage: $(basename $0) <valgrind-output-file>" && exit 0

FILE="$1"
ERROR=1
cat "$FILE" | grep -q "All heap blocks were freed -- no leaks are possible" && ERROR=0
cat "$FILE" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts" && ERROR=0

(( $ERROR == 1 )) && echo "Valgrind detected problems" 
(( $ERROR == 0 )) && echo "Okay"

exit $ERROR

