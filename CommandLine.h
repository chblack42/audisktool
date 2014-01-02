#ifndef _CommandLine_H_
#define _CommandLine_H_
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <time.h> 
#include "vars.h"

class CommandLine
{
	private:
	
		
	public:
		CommandLine();
		int getCommand(std::string &value);
		void displayHelp();
};
#endif
