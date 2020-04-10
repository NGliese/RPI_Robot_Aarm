/***********************************************************************************************+
 *  \brief       -- XX -- Library - CPP Source file
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       i2c_API.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2020
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#define DEBUG_PRINT(LOG_TAG, expr,UINT) (printf(#LOG_TAG " >> " #expr " = %d " #UINT"\n",expr) ) // debug print
#define LOG_PRINT(LOG_TAG,expr) (printf(#LOG_TAG ":: "#expr "\n" ))
#include "i2c_API.hpp"


static const char *LOG_TAG = "i2c_API";

i2c_API::i2c_API(uint8_t addr)
{
     wiringPiI2CSetup(0);
     m_addr = addr;

}

i2c_API::~i2c_API()
{
}

/**
 * @brief     write to i2c
 *
 *
 * @return
 *    - GE_OK
 */
general_err_t i2c_API::write8(uint8_t reg, uint8_t data)
{
    LOG_PRINT(LOG_TAG, ">> i2c_API::write8 >> ");


    LOG_PRINT(LOG_TAG, "<< i2c_API::write8 << ");

    return GE_OK;
}

/**
 * @brief     read to i2c
 *
 *
 * @return
 *    - GE_OK
 */
general_err_t i2c_API::read8(uint8_t reg, uint8_t data)
{
   LOG_PRINT(LOG_TAG, ">> i2c_API::read8 >> ");


   LOG_PRINT(LOG_TAG, "<< i2c_API::read8 << ");

   return GE_OK;
}

/**
 * @brief  scan the i2c
 *
 */
general_err_t i2c_API::i2c_API::scan()
{

    LOG_PRINT(LOG_TAG, ">> enclosing_method >> ");


    LOG_PRINT(LOG_TAG, "<< enclosing_method << ");

    return GE_OK;
}
