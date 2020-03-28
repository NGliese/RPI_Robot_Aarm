/*
 * MG996_API.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: nikolaj
 */


#include "../MG966/include/MG966_API.hpp"

MG966_API::MG966_API(uint8_t pwm_pin) {

    // set pwm pin
	m_pwm_pin = pwm_pin;
	/* set GPIO as output */
	pinMode(m_pwm_pin,OUTPUT);


}

MG966_API::~MG966_API() {


}

general_err_t MG966_API::initialize() {


	if(softPwmCreate (m_pwm_pin, 50,m_frequency) != 0)
	{
		std::cout << "Failed to initialize pin :: "<< m_pwm_pin << std::endl;
		return GE_FAIL;
	}
	return GE_OK;

}

/*
 * @brief set position of step motor [uinit : degree ]
 */
general_err_t MG966_API::set_position(uint8_t pos) {


	if(pos < m_min_rotation || pos > m_max_rotation)
	{
		std::cout << "Fail in set position :: " << pos << std::endl;
		return GE_FAIL;
	}

	// convert pos ( in degree ) to pwm duty cycle
	// (position / max_position) * 100 -> 0-100
	uint8_t new_duty_cycle = (pos * m_max_duty_cycle) / m_max_rotation;


	if(set_duty_cycle(new_duty_cycle) == GE_OK)
	{
		// update position
		m_position = pos;
		return GE_OK;
	}
	return GE_FAIL;

}

/*
 * @brief return current position
 */
uint8_t MG966_API::get_position(void) {

	return m_position;

}

/*
 * @brief set duty cycle of step motor [ 0 - 100 ]
 */
general_err_t MG966_API::set_duty_cycle(uint8_t duty_cycle) {


	if(duty_cycle < m_min_duty_cycle || duty_cycle > m_max_duty_cycle)
	{
		std::cout << "Fail in set duty cycle :: " << duty_cycle << std::endl;
		return GE_FAIL;
	}
	//printf("duty cycle:[%d] ",duty_cycle);
	softPwmWrite (m_pwm_pin, duty_cycle) ;
	// update duty cycle
	m_duty_cycle = duty_cycle;


	return GE_OK;
}
