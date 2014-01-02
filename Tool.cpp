/* Chuck Black
 * 	chb0006
 * 	main.cpp*/
#include "Tool.h"

Tool::Tool()
{
}
/**
 * Gathers the disk information 
 *
 *@param configArray Decides what infomation to be gathered
 *@param report Information gatherd gets stored in here
 */
void Tool::run(int configArray[], std::string report[])
{
	std::ifstream fin;
	std::string output;
	for(int i = 0; i <6; i++)
	{
			report[i] = "N/A";
	}
	std::string findme = "sda";
	std::string input;
	bool found = false;
	fin.open("/proc/diskstats");
	if(fin.is_open())
	{
		int loc;
		//Checks for the sda drive
		while(!fin.eof() && !found)
		{
			getline(fin,input);
			loc = input.find(findme);
			if(loc > 0)
			found= true;
		}
		input = input.substr(loc);
		input = input.substr(input.find(' ')+1);
		int data[11];
		//Sorts important information found in the file
		for(int i = 0; i <11; i++)
		{
			data[i] = atoi(input.substr(0,input.find(' ')).c_str());
			input = input.substr(input.find(' ')+1);
		}
		std::stringstream ss;
		 float calc;
		//Writes the BLK_READ to the report	
		if(configArray[2] == 1)
		{
			ss << data[0];
			report[0] = ss.str();
			ss.str("");
		}
		//Writes the BLK_READ_S to the report	
		if(configArray[3] == 1)
		{
			calc = ((float)data[0]/(float)data[3])*1000;
			ss << calc;
			report[1] = ss.str();
			ss.str("");
		}
		//Writes the KB_READ_S to the report		
		if(configArray[4] == 1)
		{
			calc = ((float)data[0]/(float)data[3])*1000*2;
			ss << calc;
			report[2] = ss.str();
			ss.str("");
		}
		//Writes the BLK_WRITE to the report
		if(configArray[5] == 1)
		{
			ss << data[4];
			report[3] = ss.str();
			ss.str("");
		}
		//Writes the BLK_WRITE_S to the report
		if(configArray[6] == 1)
		{
			calc = ((float)data[4]/(float)data[7])*1000;
			ss << calc;
			report[4] = ss.str();
			ss.str("");
		}
		//Writes the KB_WRITES_S to the report
		if(configArray[7] == 1)
		{
			calc = ((float)data[4]/(float)data[7])*1000*2;
			ss << calc;
			report[5] = ss.str();
			ss.str("");
		}
	
	}
	fin.close();
	
}
		
	

