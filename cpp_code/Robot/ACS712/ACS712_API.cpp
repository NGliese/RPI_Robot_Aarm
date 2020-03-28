/*
 * ACS712_API.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: nikolaj
 */


#include "ACS712_API.hpp"

ACS712_API::ACS712_API(uint8_t device_id) {

	m_device_id = device_id;
	m_current = 12;
}

ACS712_API::~ACS712_API() {
}

uint16_t ACS712_API::get_current() {

	return m_current;
}
