#! /bin/bash

#argument $1 is the disk location (/dev/sdg)
parted $1 --script -- mklabel msdos && \
parted $1 --script -- mkpart primary fat32 1MiB 100% && \
mkfs.vfat -F32 $1\1 && \
parted $1 --script print
