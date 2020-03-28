



#include "utils/include/IoT_Home_Error.hpp"
#include "Data_Package/include/Sensor_Package_PraDa.hpp"
#include "Robot_Arm_Controller.hpp"

#include <iostream>







// STATEMACHINE




int main(int argc, char ** argv)
{
	std::cout <<"Hello World" << std::endl;
	/* initialize wiringPi setup */
	// should be done only once (?)
	wiringPiSetup();

	Robot_Arm_Controller RAC;

	for(;;)
	{
		std::cout << "TESTING RAC :: " << std::endl;
		RAC.Test();
		delay(1000);
	}

	return 0;
	
	
}
