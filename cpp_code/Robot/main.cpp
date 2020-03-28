



#include "utils/include/IoT_Home_Error.hpp"
#include "Data_Package/include/Sensor_Package_PraDa.hpp"

#include <iostream>



int main(int argc, char ** argv)
{
	std::cout <<"Hello World" << std::endl;

	iot_error_t err = IoT_OK;
	Sensor_Package_PraDa spp;
	spp.update(10,5,2,100);
	spp.display();

	std::cout <<"Hello World" << std::endl;

	std::cout <<"Hello World" << std::endl;




	return 0;
	
	
}
