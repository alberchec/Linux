rec -c 1 -p | nc $1 $2 | play -c 1 -b 16 -e signed -r 48k -p
