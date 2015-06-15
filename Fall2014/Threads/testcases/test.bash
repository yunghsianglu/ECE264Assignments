#!/bin/bash

(( tot = 0 ))
./server 8000 > outputs/serverMessage.txt &
#testcase 0
./testFiles/test0.bash > outputs/output0.txt
if [[ !$(diff outputs/output0.txt expectedOutputs/expected0.txt) ]] 
	then 
	echo testcase0 passed!!!
	(( tot=$tot+20 ))
else
	echo testcase0 failed!!!
fi
#testcase 1
./testFiles/test1.bash > outputs/output1.txt
if [[ !$(diff outputs/output1.txt expectedOutputs/expected1.txt) ]]
	then 
	echo testcase1 passed!!!
	(( tot=$tot+20 ))
else
	echo testcase1 failed!!!
fi
#testcase 2
./testFiles/test2.bash > outputs/output2.txt
if [[ !$(diff outputs/output3.txt expectedOutputs/expected3.txt) ]]
	then 
	echo testcase2 passed!!!
	(( tot=$tot+20 ))
else
	echo testcase2 failed!!!
fi
#testcase 3
./testFiles/test3.bash > outputs/output3.txt
if [[ !$(diff outputs/output3.txt expectedOutputs/expected3.txt) ]] 
	then 
	echo testcase3 passed!!!
	(( tot=$tot+20 ))
else
	echo testcase3 failed!!!
fi
#testcase 4
./testFiles/test4.bash > outputs/output4.txt
if [[ !$(diff outputs/output4.txt expectedOutputs/expected4.txt) ]] 
	then 
	echo testcase4 passed!!!
	(( tot=$tot+20 ))
else
	echo testcase4 failed!!!
fi

echo Total score = $tot
killall -13 server

