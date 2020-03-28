/*
 * MG996_API.hpp
 *
 *  Created on: Mar 28, 2020
 *      Author: nikolaj
 */

#ifndef MG966_INCLUDE_MG966_API_HPP_
#define MG966_INCLUDE_MG966_API_HPP_

#include "General_Error.hpp"

#include <stdint.h>
#include <wiringPi.h> /* include wiringPi library */
#include <stdio.h>
#include <softPwm.h>  /* include header file for software PWM */
#include <iostream>

class MG966_API {
public:
	MG966_API(uint8_t pwm_pin);
	~MG966_API();
	general_err_t initialize(); // define referance point
	general_err_t set_position(uint8_t pos);
	uint8_t get_position(void);

private:

	general_err_t set_duty_cycle(uint8_t duty_cycle);

	uint8_t m_position;
	uint8_t m_pwm_pin;
	uint8_t m_duty_cycle;
	uint8_t m_frequency = 200; // 50 hz is standard for mg966

	// define boundery
	const uint8_t m_max_rotation = 120;
	const uint8_t m_min_rotation = 0;

	const uint8_t m_max_duty_cycle = 200;
	const uint8_t m_min_duty_cycle = 0;

};



#endif /* MG966_INCLUDE_MG966_API_HPP_ */
