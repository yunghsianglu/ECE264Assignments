echo "98 700 823 4905 23" | ./client 8000 127.0.0.1 &
echo "32 43 146 75 323" | ./client 8000 127.0.0.1 &
killall -13 client
