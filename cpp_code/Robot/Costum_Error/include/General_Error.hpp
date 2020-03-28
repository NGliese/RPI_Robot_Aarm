/*
 * General_Error.hpp
 *
 *  Created on: Feb 25, 2020
 *      Author: espenv
 */

#ifndef MAIN_COMPONENTS_COSTUM_ERROR_INCLUDE_GENERAL_ERROR_HPP_
#define MAIN_COMPONENTS_COSTUM_ERROR_INCLUDE_GENERAL_ERROR_HPP_


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  General_Error.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, General_Error.hpp, is designed as:
 |				    A general error indicator for return functions
 |
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
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/

#include <string>


/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/

enum general_err_t{
	GE_OK=0,
	GE_FAIL,
	GE_AMBIENT_TEMP_BOUNDERY,
	GE_I2C_SLAVE_NOT_PRESENT,
	GE_IMG_STORRAGE_TOO_SMALL,
	GE_SEMAPHORE_NOT_TAKEN,
	GE_NO_IMAGE,
	GE_NULLPTR,
	GE_IMAGE_NOT_RECIEVED,
	GE_NUMBER_OF_CICLES_TOO_BIG,
	GE_EMPTY,
	GE_NO_TEMP,
	GE_NO_VEL,
	GE_NO_IMAGE_TO_SAVE,
	GE_TEMP_NOT_CHANGED,
	GE_VELCOITY_OUT_OF_RANGE,
	GE_I2C_NOT_ACH,
	GE_I2C_SPEED_TOO_LOW,
	GE_I2C_CLEAR_DATA_ERROR,
	GE_I2C_WAIT_TIME_OUT,
	GE_SUB_FRAME_ERROR,
	GE_TEMP_NOT_ABOVE_THREASHOLD,
	GE_NO_HEIGHT,
	GE_POINT_TEMPERATURE_OUT_OF_RANGE,
	GE_NO_HEIGHT_MAX_CNT_HIT,
	GE_NO_HEIGHT_L_BOUNDERY_HIT,
	GE_CIRCLE_VOTES_TOO_LOW,
	GE_NO_CIRCLE,
	GE_SDCARD_NOT_FOUND,
	GE_VIRTUAL_SENSOR,
	GE_TIMER_INIT_FAILED,
	GE_TIMER_PAUSE_FAILED,
	GE_TIMER_RESET_FAILED,
	GE_TIMER_START_FAILED,
	GE_WEIRD_STUFF,
	GE_TIMEOUT,
	GE_OUT_OF_RANGE,
	GE_CLOSED,
	GE_NO_DATA,
};

class General_Error_List{
private:
public:
	static const char* errorToString(general_err_t errCode);
};




#endif /* MAIN_COMPONENTS_COSTUM_ERROR_INCLUDE_GENERAL_ERROR_HPP_ */
