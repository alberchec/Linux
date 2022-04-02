#! /bin/bash

transmission-cli $(cat $1) -w /home/alberto/downloads/ &> /home/alberto/downloads/logTorr &

while :
do
	sleep 30

	if cat /home/alberto/downloads/logTorr | grep -q Complete
	then
		printf "\nTransmission Completed!\n"
		pgrep -f transmission-cli | xargs kill
		rm /home/alberto/.config/transmission/torrents/*
		rm /home/alberto/.config/transmission/resume/*
		rm /home/alberto/downloads/logTorr
		break
	else
		cat /home/alberto/downloads/logTorr | grep Progress | tail -1
		printf "\n"
	fi

done
