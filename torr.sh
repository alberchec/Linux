#! /bin/bash

transmission-cli $(cat $1) -w /home/alberto/Downloads/ &> /home/alberto/Downloads/logTorr &

while :
do
	sleep 30

	if cat /home/alberto/Downloads/logTorr | grep -q Complete
	then
		printf "\nTransmission Completed!\n"
		pgrep -f transmission-cli | xargs kill
		rm /home/alberto/.config/transmission/torrents/*
		rm /home/alberto/.config/transmission/resume/*
		rm /home/alberto/Downloads/logTorr
		break
	else
		cat /home/alberto/Downloads/logTorr | grep Progress | tail -1
		printf "\n"
	fi

done
