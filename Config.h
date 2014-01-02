/* 
 *Chuck Black
 */
#ifndef _Config_H_
#define _Config_H_
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "vars.h"

class Config
{

	public:
		Config();
		void arrayConfig(int config[]);
		void changeConfig(int num, std::string value);
		std::string toString();
		std::string printMe();
		void reset();
	private:
		
};
#endif
