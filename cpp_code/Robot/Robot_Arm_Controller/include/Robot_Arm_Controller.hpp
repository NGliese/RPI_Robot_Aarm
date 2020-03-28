/*
 * Robot_Arm_Controller.hpp
 *
 *  Created on: Mar 28, 2020
 *      Author: nikolaj
 */

#ifndef ROBOT_ARM_CONTROLLER_ROBOT_ARM_CONTROLLER_HPP_
#define ROBOT_ARM_CONTROLLER_ROBOT_ARM_CONTROLLER_HPP_


#include "MG966/include/MG966_API.hpp"
#include "ACS712/include/ACS712_API.hpp"
#include "General_Error.hpp"
#include <wiringPi.h> /* include wiringPi library */
#include <string>
#include <iostream>
#include <stdint.h>

#define MAX_NUMBER_OF_MOTOR (6)


class Robot_Arm_Controller {
public:
	Robot_Arm_Controller();
	~Robot_Arm_Controller();
	general_err_t Test();

private:
	// create a private structure of
	// motor and current sensor
	typedef struct{
	std::string name;
	MG966_API * mg966_motor;
	ACS712_API * current_sensor;
	}Stepping_Motor;

	Stepping_Motor m_motor_array[MAX_NUMBER_OF_MOTOR];


};

#endif /* ROBOT_ARM_CONTROLLER_ROBOT_ARM_CONTROLLER_HPP_ */
