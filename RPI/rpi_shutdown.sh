#!/bin/bash
# This script is intented 
# to shut down the rpi after use

# Requirements are:
RPI_IP=192.168.0.159 # RPI ip adress


echo "-> initialize connection to: "$RPI_IP
## initialize connection
ssh pi@$RPI_IP 'bash -s' < ./rpi_shut_down_now.sh

