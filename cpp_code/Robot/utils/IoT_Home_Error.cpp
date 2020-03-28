/*
 * IoT_Home_Error.cpp
 *
 *  Created on: Nov 23, 2019
 *      Author: gliese
 */

#include "IoT_Home_Error.hpp"





/**
 * @brief Convert an ESP error code to a string.
 * @param [in] errCode The errCode to be converted.
 * @return A string representation of the error code.
 */
const char* IoT_Home_Error::errorToString(iot_error_t errCode) {
	switch(errCode) {
		case IoT_OK:
			return "OK";
		case IoT_FAIL:
			return "Fail";
		case IoT_NOT_SENDT:
			return "IoT not able to sendt data to address";
		case IoT_NOT_CONNECTED:
			return "We are not connected to a mesh";
		case IoT_NO_DATA:
			return "No data recieved";
		case IoT_PROTOCOL_EMPTY:
			return "Protocol is empty";
		case IoT_DATA_NOT_VALID:
			return "Data not valid";
		case IoT_SEMAPHORE_NOT_TAKEN:
			return "Not able to take the semaphore";
		case IoT_NO_MESH_ADDR:
			return "The mesh address is not found";
		case IoT_SECUITY_FAIL:
			return "Secuity code failed!";
		case IoT_SPI_NOT_INITIALIZED:
			return "SPI not initialized";
	}
	return "Unknown ESP_ERR error";

}
