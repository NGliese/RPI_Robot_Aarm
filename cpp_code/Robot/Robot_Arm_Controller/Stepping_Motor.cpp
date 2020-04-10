/*
 * Stepping_Motor.cpp
 *
 *  Created on: Mar 29, 2020
 *      Author: nikolaj
 */


#include "Stepping_Motor.hpp"

Stepping_Motor::Stepping_Motor(uint8_t dev_id, uint8_t motor_pin,i2c_API * i2c) {

	m_device_id = dev_id;
	m_current_sensor = new ACS712_API(m_device_id);

	m_motor_pin = motor_pin;
	m_motor = new MG966_API(m_motor_pin,i2c);
}

Stepping_Motor::~Stepping_Motor() {
	delete m_motor;
	delete m_current_sensor;
}

general_err_t Stepping_Motor::set_position(uint8_t pos) {
	return m_motor->set_position(pos);;
}
