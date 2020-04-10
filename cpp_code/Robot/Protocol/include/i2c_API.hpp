/*
 * i2c_API.hpp
 *
 *  Created on: Apr 9, 2020
 *      Author: nikolaj
 */


/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  i2c_API.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 		 :  <nikolaj.gliese.pedersen@dansac.com>
 |
 |  Description  :  This class, i2c_API.hpp, is designed as:
 |
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
 |   		 					Datasheet Awareness              		        |
 +------------------------------------------------------------------------------+
 |
 |
 |  Datasheet Awareness 1):
 |  	Link:[ ], Apr 9, 2020
 |		Brief:
 |
 |  Datasheet Awareness 2):
 |  	Link:[ ], Apr 9, 2020
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




/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/





#ifndef PROTOCOL_INCLUDE_I2C_API_HPP_
#define PROTOCOL_INCLUDE_I2C_API_HPP_

#include "General_Error.hpp"
#include <wiringPiI2C.h>

class i2c_API {
public:
    i2c_API(uint8_t addr);
    ~i2c_API();
    general_err_t write8(uint8_t reg, uint8_t data   );
    general_err_t read8(uint8_t reg, uint8_t data   );
    general_err_t scan();
private:
    uint8_t m_addr;

};


#endif /* PROTOCOL_INCLUDE_I2C_API_HPP_ */
