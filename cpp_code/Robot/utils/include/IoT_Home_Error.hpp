/*
 * IoT_Home_Error.hpp
 *
 *  Created on: Nov 23, 2019
 *      Author: gliese
 */

#ifndef COMPONENTS_UTILS_INCLUDE_IOT_HOME_ERROR_HPP_
#define COMPONENTS_UTILS_INCLUDE_IOT_HOME_ERROR_HPP_
#include <string>

enum iot_error_t{
	IoT_OK=0,
	IoT_FAIL,
	IoT_NOT_SENDT,
	IoT_NOT_CONNECTED,
	IoT_NO_DATA,
	IoT_PROTOCOL_EMPTY,
	IoT_DATA_NOT_VALID,
	IoT_SEMAPHORE_NOT_TAKEN,
	IoT_NO_MESH_ADDR,
	IoT_SECUITY_FAIL,
	IoT_SPI_NOT_INITIALIZED,


};
class IoT_Home_Error {
public:
	static const char* errorToString(iot_error_t errCode);
private:
};


#endif /* COMPONENTS_UTILS_INCLUDE_IOT_HOME_ERROR_HPP_ */
