/*
 * IoT_Mesh_Data_Protocol.cpp
 *
 *  Created on: Mar 3, 2020
 *      Author: espenv
 */

/***********************************************************************************************+
 *  \brief       IoT Mesh Data Protocol Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *				Defining the protocol within the mesh network
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       IoT_Mesh_Data_Protocol.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "IoT_Mesh_Data_Protocol.hpp"

static const char *LOG_TAG = "IoT_Mesh_Data_Protocol";


IoT_Mesh_Data_Protocol::IoT_Mesh_Data_Protocol() {
	m_sender_id = "";
	m_receiver_id = "";
	is_filled = false;
}



IoT_Mesh_Data_Protocol::IoT_Mesh_Data_Protocol(std::string sender_id,
		std::string receiver_id, Sensor_Package_PraDa* package) {
	m_sender_id = sender_id;
	m_receiver_id = receiver_id;
	m_package = *package;
	is_filled = true;
}

IoT_Mesh_Data_Protocol::~IoT_Mesh_Data_Protocol() {
}
/**
 * @brief      Converts the protocol to a string
 *
 * @attention  In order to send the protocol, we have to convert the
 * 			   package to a string, before sending it.
 * 			   This function handles the conversion in relationship
 * 			   to the definition of the protocol, as described
 * 			   in the headerfile.
 *
 * @param[out] processed_protocol is the returned converted string
 *
 * @return
 *    - IoT_OK
 *    - IoT_PROTOCOL_EMPTY
 *    - IoT_DATA_NOT_VALID
 */
iot_error_t IoT_Mesh_Data_Protocol::toString(std::string* str) {
//	ESP_LOGI(LOG_TAG, ">> IoT_Mesh_Data_Protocol::toString >> ");
	if (!is_filled) {
		return IoT_PROTOCOL_EMPTY;
	}

	std::string data;
	// sender id
	str->append(m_sender_id.c_str());
	str->append(",");

	// receiver id
	str->append(m_receiver_id.c_str());
	str->append(",");

	// Sensor Package Data
	if(!m_package.toString(&data)==IoT_OK){
		return IoT_PROTOCOL_EMPTY;
	}
	str->append(data);

	//ESP_LOGI(LOG_TAG, "<< IoT_Mesh_Data_Protocol::toString << ");

	return IoT_OK;
}

/**
 * @brief      return the sender id
 *
 * @attention  no use of function
 *
 *
 * @return
 *    - IoT_OK
 *    - IoT_FAIL
 */
iot_error_t IoT_Mesh_Data_Protocol::getSenderId(std::string* sensor_id) {
	//ESP_LOGD(LOG_TAG, ">> get_sensor_id  >> ");
	if(m_sender_id == "")
	{
		return IoT_FAIL;
	}
	*sensor_id = m_sender_id;

	//ESP_LOGD(LOG_TAG, "<<  get_sensor_id << ");


	return IoT_OK;
}

/**
 * @brief      Convert a string data to protocol data
 *
 * @attention  a secuity check is performed to ensure true data
 *
 * @param[in]  string_data containing the full protocol string
 *
 * @return
 *    - IoT_OK
 *    - IoT_PROTOCOL_EMPTY
 *    - IoT_SECUITY_FAIL
 *    - IoT_
 *    - IoT_
 */
iot_error_t IoT_Mesh_Data_Protocol::toProtocol(std::string* string_data) {

//ESP_LOGI(LOG_TAG, ">> IoT_Mesh_Data_Protocol::toProtocol >> ");
std::vector<std::string> splitted_data;
	split(*string_data,',',splitted_data);
	if(splitted_data.size()==0)
	{
		return IoT_PROTOCOL_EMPTY;
	}
/*
	printf("Data string : [%d] ->",splitted_data.size());
	for(int i = 0; i < splitted_data.size(); i++)
	{
		printf("[%i],[%s]",i,splitted_data[i].c_str());
	}
	printf("\n");*/

	m_sender_id = splitted_data[0].c_str();
	m_receiver_id = splitted_data[1].c_str();
	//ESP_LOGI(LOG_TAG, "<< IoT_Mesh_Data_Protocol::toProtocol << ");
	is_filled = true;
	return m_package.toProtocol(&splitted_data);



}

/**
 * @brief      return the destination id
 *
 * @attention  this function is only used by the node to know
 * 			   the address of who to send the package
 *
 *
 * @return
 *    - IoT_OK
 *    - IoT_FAIL
 */
iot_error_t IoT_Mesh_Data_Protocol::getReceiverId(std::string* receiver_id) {
	//ESP_LOGD(LOG_TAG, ">> get_sensor_id  >> ");
		if(m_receiver_id == "")
		{
			return IoT_FAIL;
		}
		*receiver_id = m_receiver_id;

	//	ESP_LOGD(LOG_TAG, "<<  get_sensor_id << ");


		return IoT_OK;
}

iot_error_t IoT_Mesh_Data_Protocol::update(std::string sender_id,
		std::string receiver_id, Sensor_Package_PraDa* package) {

	//ESP_LOGI(LOG_TAG, ">> IoT_Mesh_Data_Protocol::update >> ");

	m_sender_id = sender_id;
	m_receiver_id = receiver_id;
	m_package = *package;
	is_filled = true;

	//ESP_LOGI(LOG_TAG, "<< IoT_Mesh_Data_Protocol::update << ");

	return IoT_OK;
}
/**
 * @brief   Displays the container
 *
 * @attention
 *
 *
 * @return
 *    - IoT_OK
 */
iot_error_t IoT_Mesh_Data_Protocol::display() {
	//ESP_LOGI(LOG_TAG, ">> IoT_Mesh_Data_Protocol::display >> ");
	std::string data;
	toString(&data);
	std::cout << LOG_TAG << " " << data.c_str() << std::endl;
	//ESP_LOGE(LOG_TAG, "[%s]", data.c_str());

	//ESP_LOGI(LOG_TAG, "<< IoT_Mesh_Data_Protocol::display << ");

	return IoT_OK;
}


