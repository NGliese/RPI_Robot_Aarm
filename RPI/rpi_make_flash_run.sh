#!/bin/bash
# This script is intented 
# to load code from project folder Work_Folder
# to the RPI project folder RPI_Work_Folder
# Requirements are:
RPI_Work_Folder=/home/pi/Project/Robot_Arm/cpp_code/Robot/   # Destination of project content
echo "-> RPI_Work_Folder :: "$RPI_Work_Folder

## go to work folder
cd $RPI_Work_Folder;
make depend_rpi
./ROBOT

