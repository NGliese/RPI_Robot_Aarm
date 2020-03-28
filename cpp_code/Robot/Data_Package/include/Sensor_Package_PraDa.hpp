/*
 * Sensor_Package_PraDa.hpp
 *
 *  Created on: Mar 9, 2020
 *      Author: espenv
 */

#ifndef MAIN_COMPONENTS_DATA_PACKAGE_INCLUDE_SENSOR_PACKAGE_PRADA_HPP_
#define MAIN_COMPONENTS_DATA_PACKAGE_INCLUDE_SENSOR_PACKAGE_PRADA_HPP_



/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  Sensor_Package_PraDa.hpp
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

#include <string>

#include <stdint.h>

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

typedef enum{
	DATA_READY=0, 	  // Data is ready to load
	DATA_NOT_READY,   // Data has not been updated since power on
	DATA_NOT_VALID,   // Data has been updated, but is invalid, old value used
	DATA_NOT_UPDATED, // Data has not been updated since last read
}DATA_FLAG_PRADA;
class Sensor_Package_PraDa {
public:
	Sensor_Package_PraDa();
	Sensor_Package_PraDa(time_t timestamp, uint16_t sensor_id,  uint16_t quality, float data);
	~Sensor_Package_PraDa();

	iot_error_t update(time_t timestamp, uint16_t sensor_id, uint16_t quality, float data);

	iot_error_t setSensorid(uint16_t sensor_id);
	iot_error_t setQuality(uint16_t quality);
	iot_error_t setData(float data);
	iot_error_t setTime(time_t timestamp);

	iot_error_t toString(std::string * s);
	iot_error_t toProtocol(std::string * s);
	iot_error_t toProtocol(std::vector<std::string> *s);
	iot_error_t display(void);
	iot_error_t clear(void);

private:
	iot_error_t validate(std::string * data_string);
	time_t   m_timestamp;
	uint16_t m_sensor_id;
	float    m_data;
	uint16_t m_quality;
	bool     is_filled;
};



#endif /* MAIN_COMPONENTS_DATA_PACKAGE_INCLUDE_SENSOR_PACKAGE_PRADA_HPP_ */
