/*
 * Robot_Arm_Controller.hpp
 *
 *  Created on: Mar 28, 2020
 *      Author: nikolaj
 */

#ifndef ROBOT_ARM_CONTROLLER_ROBOT_ARM_CONTROLLER_HPP_
#define ROBOT_ARM_CONTROLLER_ROBOT_ARM_CONTROLLER_HPP_

#include "General_Error.hpp"
#include "Stepping_Motor.hpp"
#include "i2c_API.hpp"
#include <string>
#include <iostream>
#include <stdint.h>

#define MAX_NUMBER_OF_MOTOR (6)


class Robot_Arm_Controller {
public:
	Robot_Arm_Controller();
	~Robot_Arm_Controller();
	general_err_t set_Default();
	general_err_t Test();
	general_err_t test_position(uint8_t index, uint8_t position);

private:
	const uint8_t m_i2c_addr = 0x40;
	i2c_API * m_i2c;

	Stepping_Motor * m_base_motor;
	Stepping_Motor * m_adjuster_1_motor;
	Stepping_Motor * m_adjuster_2_motor;
	Stepping_Motor * m_adjuster_3_motor;
	Stepping_Motor * m_arm_rotator_motor;
	Stepping_Motor * m_arm_grabber_motor;



};

#endif /* ROBOT_ARM_CONTROLLER_ROBOT_ARM_CONTROLLER_HPP_ */
