/*
 * ACS712_API.hpp
 *
 *  Created on: Mar 28, 2020
 *      Author: nikolaj
 */

#ifndef ACS712_INCLUDE_ACS712_API_HPP_
#define ACS712_INCLUDE_ACS712_API_HPP_

#include <stdio.h>
#include <iostream>
#include <stdint.h>

class ACS712_API {
public:
	ACS712_API(uint8_t device_id);
	~ACS712_API();
	uint16_t get_current();

private:
	uint16_t m_current;
	uint8_t m_device_id;
};



#endif /* ACS712_INCLUDE_ACS712_API_HPP_ */
