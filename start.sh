#!/bin/bash
# Change OVFM directory if .fd file has different location


qemu-system-x86_64 -cpu qemu64 -bios /usr/share/edk2/x64/OVMF.fd -drive file=image.img,if=ide,format=raw
