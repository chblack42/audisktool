/* 
 *Chuck Black
 */
#ifndef _Report_H_
#define _Report_H_
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "vars.h"

class Report
{
	private:
		std::string filename;
	public:
		Report();
		std::string toString();
		void setFileName(std::string name);
		void addReport(std::string data[]);
		std::string getFilename();
};
#endif
