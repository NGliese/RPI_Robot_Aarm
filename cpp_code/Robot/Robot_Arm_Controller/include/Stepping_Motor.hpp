/*
 * Stepping_Motor.hpp
 *
 *  Created on: Mar 29, 2020
 *      Author: nikolaj
 */

#ifndef ROBOT_ARM_CONTROLLER_INCLUDE_STEPPING_MOTOR_HPP_
#define ROBOT_ARM_CONTROLLER_INCLUDE_STEPPING_MOTOR_HPP_


#include "MG966/include/MG966_API.hpp"
#include "ACS712/include/ACS712_API.hpp"
#include "General_Error.hpp"
#include "i2c_API.hpp"

/*
 * This one should become a thread
 */
class Stepping_Motor {
public:
	Stepping_Motor(uint8_t dev_id, uint8_t motor_pin,i2c_API * i2c);
	~Stepping_Motor();
	general_err_t set_position(uint8_t pos);



private:
	uint8_t m_motor_pin;
	uint8_t m_device_id;
	MG966_API * m_motor;
	ACS712_API * m_current_sensor;

};



#endif /* ROBOT_ARM_CONTROLLER_INCLUDE_STEPPING_MOTOR_HPP_ */
