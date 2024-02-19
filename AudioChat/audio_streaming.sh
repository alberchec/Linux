rec -c 1 -p | nc -l -p 23123
nc ip port | play -c 1 -b 16 -e signed -p -r 48k
rec -c 1 -p | nc -l -p 23123 | play -c 1 -b 16 -e signed -p -r 48k
rec -c 1 -p | nc ip port | play -c 1 -b 16 -e signed -p -r 48k
