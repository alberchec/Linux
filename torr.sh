#! /bin/bash

transmission-cli $(cat $1) -w /home/janci/Downloads/ &> /home/janci/Downloads/logTorr &

while :
do
	sleep 30

	if cat /home/janci/Downloads/logTorr | grep -q Complete
	then
		printf "\nTransmission Completed!\n"
		pgrep -f transmission-cli | xargs kill
		rm /home/janci/.config/transmission/torrents/*
		rm /home/janci/.config/transmission/resume/*
		break
	else
		cat /home/janci/Downloads/logTorr | grep Progress | tail -1
		printf "\n"
	fi

done
