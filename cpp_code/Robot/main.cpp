



#include "utils/include/IoT_Home_Error.hpp"
#include "Data_Package/include/Sensor_Package_PraDa.hpp"
#include "Robot_Arm_Controller.hpp"

#include <iostream>







// STATEMACHINE



/**
 * @brief
 *
 * @attention
 *
 *
 * @param[in]
 * @param[in]
 *
 * @param[out]
 * @param[out]
 *
 * @return
 *    - IoT_OK
 *    -
 *    -
 */
int main(int argc, char ** argv)
{
	std::cout <<"Hello World" << std::endl;
	/* initialize wiringPi setup */
	// should be done only once (?)
	wiringPiSetup();

	Robot_Arm_Controller RAC;
	RAC.set_Default();
	for(;;)
	{
		std::cout << "TESTING RAC :: " << std::endl;
		RAC.test_position(0,50);
		delay(1000);
	}

	return 0;
	
	
}
