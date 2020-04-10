/*
 * Robot_Arm_Controller.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: nikolaj
 */


#include "Robot_Arm_Controller.hpp"

#define DEFAULT_POSITION      (60)

#define BASE_MOTOR_PIN        (1)
#define ADJUSTER_1_MOTOR_PIN  (2)
#define ADJUSTER_2_MOTOR_PIN  (3)
#define ADJUSTER_3_MOTOR_PIN  (4)
#define ARM_ROTATOR_MOTOR_PIN (5)
#define ARM_GRABBER_MOTOR_PIN (6)

#define LOG_PRINT(LOG_TAG,expr) (printf(#LOG_TAG ":: "#expr "\n" ))


Robot_Arm_Controller::Robot_Arm_Controller() {

    m_i2c = new i2c_API(m_i2c_addr);

	m_base_motor = new Stepping_Motor(1,BASE_MOTOR_PIN,m_i2c);
	m_adjuster_1_motor = new Stepping_Motor(1,ADJUSTER_1_MOTOR_PIN,m_i2c);
	m_adjuster_2_motor = new Stepping_Motor(1,ADJUSTER_2_MOTOR_PIN,m_i2c);
	m_adjuster_3_motor = new Stepping_Motor(1,ADJUSTER_3_MOTOR_PIN,m_i2c);

	m_arm_rotator_motor = new Stepping_Motor(1,ARM_ROTATOR_MOTOR_PIN,m_i2c);
	m_arm_grabber_motor = new Stepping_Motor(1,ARM_GRABBER_MOTOR_PIN,m_i2c);


}

Robot_Arm_Controller::~Robot_Arm_Controller() {
}

general_err_t Robot_Arm_Controller::set_Default() {

	m_base_motor->set_position(DEFAULT_POSITION);
	m_adjuster_1_motor->set_position(DEFAULT_POSITION);
	m_adjuster_2_motor->set_position(DEFAULT_POSITION);
	m_adjuster_3_motor->set_position(DEFAULT_POSITION);

	m_arm_rotator_motor->set_position(DEFAULT_POSITION);


	return GE_OK;
}

// simple test to increment each motor
general_err_t Robot_Arm_Controller::Test() {


	for(uint8_t i = 0; i < 120; i++)
	{
		m_arm_rotator_motor->set_position(i);

	}
	return GE_OK;
}

general_err_t Robot_Arm_Controller::test_position(
        uint8_t index, uint8_t position)
{
LOG_PRINT(LOG_TAG, ">> Robot_Arm_Controller::test_position >> ");

m_arm_rotator_motor->set_position(position);


LOG_PRINT(LOG_TAG, "<< Robot_Arm_Controller::test_position << ");

return GE_OK;
}
