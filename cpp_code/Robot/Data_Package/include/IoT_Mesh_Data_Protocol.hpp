/*
 * IoT_Mesh_Data_Protocol.hpp
 *
 *  Created on: Mar 3, 2020
 *      Author: espenv
 */

#ifndef MAIN_COMPONENTS_DATA_PACKAGE_INCLUDE_IOT_MESH_DATA_PROTOCOL_HPP_
#define MAIN_COMPONENTS_DATA_PACKAGE_INCLUDE_IOT_MESH_DATA_PROTOCOL_HPP_

/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  IoT_Mesh_Data_Protocol.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, IoT_Mesh_Data_Protocol.hpp, is designed as:
 |				    The container of data together with transmitter and receiver id
 |	 				for mesh network
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
 |  	Link:[ ], Mar 3, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Mar 3, 2020
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

#include "Sensor_Package_PraDa.hpp"

#include <string.h>

#include <stdint.h>



/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/


class IoT_Mesh_Data_Protocol {
public:
	IoT_Mesh_Data_Protocol();
	IoT_Mesh_Data_Protocol(std::string sender_id, std::string receiver, Sensor_Package_PraDa * package);
	~IoT_Mesh_Data_Protocol();
	iot_error_t update(std::string sender_id, std::string receiver, Sensor_Package_PraDa * package);
	iot_error_t toString(std::string * str);
	iot_error_t display();
	iot_error_t toProtocol(std::string * string_data);
	iot_error_t getSenderId(std::string * sensor_id);
	iot_error_t getReceiverId(std::string * receiver_id);
private:
	std::string     m_sender_id;
	std::string     m_receiver_id;
	Sensor_Package_PraDa  m_package;
	bool 			is_filled;
};




#endif /* MAIN_COMPONENTS_DATA_PACKAGE_INCLUDE_IOT_MESH_DATA_PROTOCOL_HPP_ */
