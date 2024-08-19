#!/bin/bash

ovmfDir=/usr/share/edk2/x64/OVMF.fd  # Replace with the path of your OVMF.fd 
imageFile=image.img                  # Replace with the name of your disk image


qemu-system-x86_64 -cpu qemu64 -bios $ovmfDir -drive file=$imageFile,if=ide,format=raw
