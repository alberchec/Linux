#! /bin/bash

if cat /home/janci/Downloads/logTorr | grep -q Complete
then
	printf "\nTransmission has finished!\n"
	printf "Transmission has finished!\n"
	printf "Transmission has finished!\n"
	printf "Transmission has finished!\n"
	printf "Transmission has finished!\n"
	printf "Transmission has finished!\n"
	printf "Transmission has finished!\n"
else
	cat /home/janci/Downloads/logTorr | tail -1 > /dev/tty1
	#printf "Not finished\n" > /dev/tty1
fi
