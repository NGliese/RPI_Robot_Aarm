/*
 * General_Error.cpp
 *
 *  Created on: Feb 25, 2020
 *      Author: espenv
 */

/***********************************************************************************************+
 *  \brief       General error class for return types Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       General_Error.cpp
 *  \author     N.G Pedersen <nikolaj.gliese.pedersen@dansac.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "General_Error.hpp"

/**
 * @brief Convert an ESP error code to a string.
 * @param [in] errCode The errCode to be converted.
 * @return A string representation of the error code.
 */
const char* General_Error_List::errorToString(general_err_t errCode) {

	switch (errCode) {
	case GE_OK:
		return "OK";
	case GE_FAIL:
		return "Fail";
	case GE_AMBIENT_TEMP_BOUNDERY:
		return "Ambient Temperature is out of bounds";
	case GE_I2C_SLAVE_NOT_PRESENT:
		return "Slave not present";
	case GE_IMG_STORRAGE_TOO_SMALL:
		return "The size of the array is too small to contain an image";
	case GE_SEMAPHORE_NOT_TAKEN:
		return "Not able to take semaphore";
	case GE_NO_IMAGE:
		return "No image has been storred yet";
	case GE_NULLPTR:
		return "points to nothing";
	case GE_IMAGE_NOT_RECIEVED:
		return "image not recieved -> due to i2c speed";
	case GE_NUMBER_OF_CICLES_TOO_BIG:
		return "Number of detected circles exciede the maximum allowance";
	case GE_EMPTY:
		return "The recived vector is empty";
	case GE_NO_TEMP:
		return "No new temperature is available";
	case GE_NO_VEL:
		return "No new velocity is available";
	case GE_NO_IMAGE_TO_SAVE:
		return "No Image to save";
	case GE_TEMP_NOT_CHANGED:
		return "Point Sensor Temperature has not changed";
	case GE_VELCOITY_OUT_OF_RANGE:
		return "The estimated velocity is out of range";
	case GE_I2C_NOT_ACH:
		return "The i2c slave did not archknowleadge";
	case GE_I2C_SPEED_TOO_LOW:
		return " The i2c speed (maybe) too low";
	case GE_I2C_CLEAR_DATA_ERROR:
		return "Error when clearing new data";
	case GE_I2C_WAIT_TIME_OUT:
		return "Time out counter reached";
	case GE_SUB_FRAME_ERROR:
		return "The subframes did not interchange";
	case GE_TEMP_NOT_ABOVE_THREASHOLD:
		return "The largest temperautre in the frame is below minimum temperature";
	case GE_NO_HEIGHT:
		return "No New Height";
	case GE_POINT_TEMPERATURE_OUT_OF_RANGE:
		return "Point temperature is out of range";
	case GE_NO_HEIGHT_L_BOUNDERY_HIT:
		return "No height: The estimated L is wrong";
	case GE_NO_HEIGHT_MAX_CNT_HIT:
		return "No height: We hit the max count";
	case GE_CIRCLE_VOTES_TOO_LOW:
		return "The detected circle votes are too low to be usefull";
	case GE_NO_CIRCLE:
		return "No Circle found";
	case GE_SDCARD_NOT_FOUND:
		return "SD card does not exist";
	case GE_VIRTUAL_SENSOR:
		return "VIRTUAL SENSOR SELECTED!";
	case GE_TIMER_INIT_FAILED:
		return "The timer failed to initialize";
	case GE_TIMER_PAUSE_FAILED:
		return "timer failed to pause";
	case GE_TIMER_RESET_FAILED:
		return "timer failed to reset";
	case GE_TIMER_START_FAILED:
		return "timer failed to start";
	case GE_WEIRD_STUFF:
		return "Weird stuff in the statemachine";
	case GE_TIMEOUT:
		return "Timeout occured";
	case GE_OUT_OF_RANGE:
		return "Out of range";
	case GE_CLOSED:
		return "Driver is closed";
	case GE_NO_DATA:
		return "No data";
	}
	return "Unknown ESP_ERR error";

}

