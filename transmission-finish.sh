#! /bin/bash

while :
do
	sleep 30

	if cat /home/janci/Downloads/logTorr | grep -q Complete
	then
		printf "\nTransmission has finished!\n"
		break
	else
		cat /home/janci/Downloads/logTorr | tail -1
	fi

done
