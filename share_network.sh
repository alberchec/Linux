#!/bin/bash

ip link set dev enp3s0 up
ip address add 192.168.2.1/24 dev enp3s0 broadcast 192.168.2.255
#ip route add 192.168.2.0/24 dev enp3s0

#iptables --flush
#iptables --table nat --flush
#iptables --delete-chain
#iptables --table nat --delete-chain

#iptables --table nat --append POSTROUTING --out-interface wlp2s0 -j MASQUERADE
#iptables --append FORWARD --in-interface enp3s0 -j ACCEPT

/etc/init.d/networking restart
