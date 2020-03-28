/*
 * Robot_Arm_Controller.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: nikolaj
 */


#include "Robot_Arm_Controller.hpp"


uint8_t device_list[6][2] = { {1,1}, //GPIO18
		                      {2,7}, //GPIO4
							  {3,0}, //GPIO17
							  {4,2}, //GPIO27
							  {5,3}, //GPIO22
							  {6,4}  //GPIO23
                            };

Robot_Arm_Controller::Robot_Arm_Controller() {


	for(int i = 0; i < MAX_NUMBER_OF_MOTOR; i++)
	{
		printf("device list :: i -> [%d]( 0 -> [%d], 1 -> [%d]) \n",i,device_list[i][0],device_list[i][1]);
		m_motor_array[i].current_sensor = new ACS712_API(device_list[i][0]);
		m_motor_array[i].mg966_motor    = new MG966_API(device_list[i][1]);
		m_motor_array[i].name           = "Stepping_Motor";
		// initialize
		m_motor_array[i].mg966_motor->initialize();
	}


}

Robot_Arm_Controller::~Robot_Arm_Controller() {
}

// simple test to increment each motor
general_err_t Robot_Arm_Controller::Test() {

   	for(int pos = 0; pos < 120; pos++)
   {

        for(int i = 0; i < MAX_NUMBER_OF_MOTOR; i++)
        {
        	m_motor_array[i].mg966_motor->set_position(pos);

    	}
        delay(10);
    }
	return GE_OK;
}
