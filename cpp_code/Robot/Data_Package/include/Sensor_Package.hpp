/*
 * Sensor_Package.hpp
 *
 *  Created on: Mar 2, 2020
 *      Author: espenv
 */

#ifndef MAIN_COMPONENTS_DATA_PACKAGE_INCLUDE_SENSOR_PACKAGE_HPP_
#define MAIN_COMPONENTS_DATA_PACKAGE_INCLUDE_SENSOR_PACKAGE_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Sensor_Package.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, Sensor_Package.hpp, is designed as:
 |					Package class defining a standard of all future sensor implementations
 |				Basic package protocol is given as:
 |				[ Version ] [ Sensor_Type ] [ (float) data ]
 |
 |
 |
 |
 |
 |  version       : 1.0
 |
 |  Return Value  :   return_type
 |
 +-----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------+
 |   		 					Datasheet Awareness              		        |
 +------------------------------------------------------------------------------+
 |
 |
 |  Datasheet Awareness 1):
 |  	Link:[ ], Mar 2, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Mar 2, 2020
 |
 |		Brief:
 |
 |
 |
 |
 |
  +-----------------------------------------------------------------------------*/



/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/
#include "IoT_Home_Error.hpp"
#include "utils.h"
#include "Mesh_network_setting.hpp"

#include <esp_log.h>
#include <esp_err.h>
#include <string>
#include <esp_sleep.h>
#include "sdkconfig.h"

#include <stdint.h>

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/
typedef enum{
	AC06=0,			// Round table machine
}MACHINE_ID;

typedef enum{
	DS18B20=0,       // Temperature sensor
}SENSOR_ID;

typedef enum{
	Temp_Contact=0, // Contact/Ambient temperature
}DATA_TYPE;

class Sensor_Package {
public:
	Sensor_Package();
	Sensor_Package(time_t timestamp, uint8_t version,MACHINE_ID machine_id, SENSOR_ID sensor_id, DATA_TYPE data_type, uint8_t data_flag, float data );
	~Sensor_Package();
	iot_error_t update(time_t timestamp, uint8_t version,MACHINE_ID machine_id, SENSOR_ID sensor_id, DATA_TYPE data_type, uint8_t data_flag, float data );
	iot_error_t setDataFlag(uint8_t data_flag);
	iot_error_t setData(float data);
	iot_error_t setTime(time_t timestamp);
	float		getData();
	iot_error_t toString(std::string * s);
	iot_error_t toProtocol(std::string * s);
	iot_error_t toProtocol(std::vector<std::string> *s);
	iot_error_t display(void);
	iot_error_t clear(void);

private:
	iot_error_t validate(std::string * data_string);
	time_t  m_timestamp;
	uint8_t m_version;
	uint8_t m_machine_id;
	uint8_t m_sensor_id;
	uint8_t m_data_type;
	uint8_t m_data_flag;
	float   m_data;
	bool    is_filled;
};




#endif /* MAIN_COMPONENTS_DATA_PACKAGE_INCLUDE_SENSOR_PACKAGE_HPP_ */
