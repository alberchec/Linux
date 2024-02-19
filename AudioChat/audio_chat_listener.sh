rec -c 1 -t mp3 - | nc -l -p 23123 | play -c 1 -b 16 -e signed -r 48k -t 
mp3 -
