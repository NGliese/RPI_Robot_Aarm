/*
 * utils.h
 *
 *  Created on: Jun 17, 2018
 *      Author: nikolaj
 */

#ifndef COMPONENTS_MONITOR_INCLUDE_UTILS_H_
#define COMPONENTS_MONITOR_INCLUDE_UTILS_H_

#include <string>
#include <vector>


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#include <iostream>
#include <sstream>  // Required for stringstreams
#include <string>


void split(const std::string& s, char delim,std::vector<std::string>& v);
std::string Uint8ToString ( uint8_t number );
std::string TimeToString ( time_t number );
std::string IntToString(int number) ;
std::string UintToString(uint8_t number) ;
std::string FloatToString(float number) ;
std::string FloatToString ( float number , int precision);
void printBits(size_t const size, void const * const ptr);
#endif /* COMPONENTS_MONITOR_INCLUDE_UTILS_H_ */
