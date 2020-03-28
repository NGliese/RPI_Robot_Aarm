/*
 * Sensor_Package_PraDa.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: espenv
 */

/***********************************************************************************************+
 *  \brief       Sensor_Package_PraDa Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *  			This class is used as the data protocol for PraDa version 1.0 [2020-03-09]
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       Sensor_Package_PraDa.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "Sensor_Package_PraDa.hpp"

static const char *LOG_TAG = "Sensor_Package_PraDa";

Sensor_Package_PraDa::Sensor_Package_PraDa() {
	m_timestamp = 0;
	m_sensor_id = 0;
	m_quality = 0;
	m_data = 0;
	is_filled = false;
	// set log level to warn
	//esp_log_level_set(LOG_TAG, ESP_LOG_WARN);
}

Sensor_Package_PraDa::Sensor_Package_PraDa(time_t timestamp, uint16_t sensor_id,
		uint16_t quality, float data) {
	m_timestamp = timestamp;
	m_sensor_id = sensor_id;
	m_quality = quality;
	m_data = data;
	is_filled = true;
	// set log level to warn
	//esp_log_level_set(LOG_TAG, ESP_LOG_WARN);
}

Sensor_Package_PraDa::~Sensor_Package_PraDa() {
}
/**
 * @brief update package
 *
 * @attention
 *
 *
 * @param[in] timestamp,
 * @param[in] sensor_id
 * @param[in] quality
 * @param[in] data
 *
 * @return
 *    - IoT_OK
 *    -
 *    -
 */
iot_error_t Sensor_Package_PraDa::update(time_t timestamp, uint16_t sensor_id,
		uint16_t quality, float data) {
	//ESP_LOGI(LOG_TAG, ">> Sensor_Package_PraDa::update >> ");
	m_timestamp = timestamp;
	m_sensor_id = sensor_id;
	m_quality = quality;
	m_data = data;
	is_filled = true;
	//ESP_LOGI(LOG_TAG, "<< Sensor_Package_PraDa::update << ");

	return IoT_OK;
}

iot_error_t Sensor_Package_PraDa::setSensorid(uint16_t sensor_id) {
	//ESP_LOGI(LOG_TAG, ">> Sensor_Package_PraDa::setSensorid >> ");

	m_sensor_id = sensor_id;

//	ESP_LOGI(LOG_TAG, "<< Sensor_Package_PraDa::setSensorid << ");

	return IoT_OK;
}

iot_error_t Sensor_Package_PraDa::setQuality(uint16_t quality) {
	//ESP_LOGI(LOG_TAG, ">> Sensor_Package_PraDa::setQuality >> ");

	m_quality = quality;

	//ESP_LOGI(LOG_TAG, "<< Sensor_Package_PraDa::setQuality << ");

	return IoT_OK;
}

iot_error_t Sensor_Package_PraDa::setData(float data) {

	//ESP_LOGI(LOG_TAG, ">> Sensor_Package_PraDa::setData >> ");

	m_data = data;

	//ESP_LOGI(LOG_TAG, "<< Sensor_Package_PraDa::setData << ");

	return IoT_OK;
}

iot_error_t Sensor_Package_PraDa::setTime(time_t timestamp) {
	//ESP_LOGI(LOG_TAG, ">> Sensor_Package_PraDa::setTime >> ");

	m_timestamp = timestamp;

	//ESP_LOGI(LOG_TAG, "<< Sensor_Package_PraDa::setTime << ");

	return IoT_OK;
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
iot_error_t Sensor_Package_PraDa::toString(std::string* str) {

	//ESP_LOGI(LOG_TAG, ">> Sensor_Package::to_String  >> ");
		if (!is_filled) {
			return IoT_PROTOCOL_EMPTY;
		}

		std::string s;
		// timestamp
		s.append(TimeToString(m_timestamp));
		s.append(",");

		// Sensor id
		s.append(IntToString(m_sensor_id));
		s.append(",");

		// Data quality
		s.append(IntToString(m_quality));
		s.append(",");

		// data, with 4 precision
		s.append(FloatToString(m_data, 4));

		if (validate(&s) != IoT_OK) {
			return IoT_DATA_NOT_VALID;
		}

		*str = s;

		//ESP_LOGI(LOG_TAG, "<<  Sensor_Package::to_String << ");

		return IoT_OK;
}

/**
 * @brief      Convert a vector string data to protocol data
 *
 * @attention  This function is meant for mesh data protocol
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
iot_error_t Sensor_Package_PraDa::toProtocol(std::vector<std::string>* splitted_data) {
	//ESP_LOGI(LOG_TAG, ">> Sensor_Package::toProtocol >> ");
	// no clue what int base is, 10 corrospons to an example
	m_timestamp  = strtol(splitted_data->at(2).c_str(), nullptr, 10); // 10 base because it is integers, link:https://stackoverflow.com/questions/14794079/basics-of-strtol
	m_sensor_id  = strtol(splitted_data->at(3).c_str(), nullptr, 10); // 10 base because it is integers
	m_quality    = strtol(splitted_data->at(4).c_str(), nullptr, 10); // 10 base because it is integers
	m_data       = strtof(splitted_data->at(5).c_str(), nullptr);	  // we dont care for the next data ( as it is empty )
	is_filled    = true;
	//ESP_LOGI(LOG_TAG, "<< Sensor_Package::toProtocol << ");

	return IoT_OK;
}

/**
 * @brief      Display the container, with printf
 *
 *
 * @return
 *    - IoT_OK
 */
iot_error_t Sensor_Package_PraDa::display(void) {
//	ESP_LOGW(LOG_TAG, ">> display  >> ");
	std::string data;
	toString(&data);
	//ESP_LOGW(LOG_TAG, "[%s]", data.c_str());
	std::cout << LOG_TAG << " " << data.c_str() << std::endl;
	//ESP_LOGW(LOG_TAG, "<<  display << ");
	return IoT_OK;
}

/**
 * @brief      clear the data inside the protocol
 *
 *
 * @return
 *    - IoT_OK
 */
iot_error_t Sensor_Package_PraDa::clear(void) {
	//ESP_LOGI(LOG_TAG, ">> Sensor_Package::clear >> ");

	m_timestamp = 0;
	m_sensor_id = 0;
	m_quality = 0;
	m_data = 0;
	is_filled = false;

	//ESP_LOGI(LOG_TAG, "<< Sensor_Package::clear << ");

	return IoT_OK;
}

/**
 * @brief      Validate the data before processing
 *
 * @attention  Check if the size of the data is too big
 * 			   to send through the network.
 *
 * @param[in] data_string is the concatenated string
 *
 * @return
 *    - IoT_OK
 *    - IoT_DATA_NOT_VALID
 */
iot_error_t Sensor_Package_PraDa::validate(std::string* data_string) {
	//ESP_LOGD(LOG_TAG, ">> enclosing_method  >> ");

	if (data_string->size() > 200) {
		return IoT_DATA_NOT_VALID;
	}
	//ESP_LOGI(LOG_TAG, "- Data is valid, size -> [%d] -", data_string->size());

	return IoT_OK;
}



