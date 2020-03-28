#!/bin/bash
# This script is intented 
# to load code from project folder Work_Folder
# to the RPI project folder RPI_Work_Folder
# Requirements are:
RPI_IP=192.168.0.159 # RPI ip adress
RPI_Work_Folder=/home/pi/Project/Robot_Arm/cpp_code/  # Destination of project content
Work_Folder=~/Project/Robot_Arm/cpp_code/   # Source of project content

echo "-> Work_Folder :: "$Work_Folder ", RPI_Work_Folder :: "$RPI_Work_Folder
# copy the code to the rpi:
scp -r  $Work_Folder/* pi@$RPI_IP:$RPI_Work_Folder


echo "-> initialize connection to: "$RPI_IP
## initialize connection
ssh pi@$RPI_IP 'bash -s' < ./rpi_make_flash_run.sh

## GoTo work folder
#cd $RPI_Work_Folder; 
## list directory
#ls -l
