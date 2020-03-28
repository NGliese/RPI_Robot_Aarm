/*
 * utils.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: nikolaj
 */



#include <utils.h>
#include <iomanip>
#include <sstream>

// split the data up
void split(const std::string& s, char delim,std::vector<std::string>& v) {
	if(s.size()==0){
		return;
	}
    auto i = 0;
    auto pos = s.find(delim);
    while (pos != std::string::npos) {
      v.push_back(s.substr(i, pos-i));
      i = ++pos;
      pos = s.find(delim, pos);

      if (pos == std::string::npos)
         v.push_back(s.substr(i, s.length()));
    }
}

std::string IntToString ( int number )
{
	std::ostringstream oss;

  // Works just like cout
  oss<< number;

  // Return the underlying string

  return oss.str();
}

std::string TimeToString ( time_t number )
{
	std::ostringstream oss;

  // Works just like cout
  oss<< number;

  // Return the underlying string

  return oss.str();
}


std::string Uint8ToString ( uint8_t number )
{
	std::ostringstream oss;

  // Works just like cout
  oss<< number;

  // Return the underlying string

  return oss.str();
}


std::string FloatToString ( float number )
{
  std::ostringstream oss;

  // Works just like cout
  oss << std::fixed << std::setprecision(3) << number;

  // Return the underlying string
  return oss.str();
}

std::string FloatToString ( float number , int precision)
{
  std::ostringstream oss;

  // Works just like cout
  oss << std::fixed << std::setprecision(precision) << number;

  // Return the underlying string
  return oss.str();
}


std::string UintToString(uint8_t number) {

	  std::ostringstream oss;

	  // Works just like cout
	  oss  << number;

	  // Return the underlying string
	  return oss.str();
}


//assumes little endian
/*
 * prints out a register of xx size. usage:
 *  uint16_t controlRegister1;
 *  printBits(sizeof(controlRegister1),&controlRegister1);
 */
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

