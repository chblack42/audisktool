/* 
 *Chuck Black
 */

#include "Config.h"
#include "CommandLine.h"
#include "Report.h"
#include "Tool.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "vars.h"
int main()
{
	Config config;
	CommandLine command;
	Report report;
	Tool tool;
	std::string value;
	std::string rep[6];
	int configArray[8];
	std::cout << "audisktool, version 1, type \"help\" for the list of commands\n";
	int commandValue = command.getCommand(value);
	while(commandValue != 14)
	{
		switch(commandValue){
			case constants::HELP:
				command.displayHelp();
				break;
			case constants::RUN:
				config.arrayConfig(configArray);
				std::cout << config.printMe();
				std::cout << ", report file name = ";
				std::cout << report.getFilename();
				std::cout << "\nPlease wait...\n";
				for(int i =0; i<configArray[1];i++)
				{
					sleep(configArray[0]);
					std::cout << i+1;
					std::cout << " time(s) checked\n";
					tool.run(configArray, rep);
					report.addReport(rep);
					
				}
				std::cout << "\nFile ";
				std::cout << report.getFilename();
				std::cout << " has been updated!\n";
				break;
			case constants::MONITORINTERVAL:
				config.changeConfig(commandValue, value);
				break;
			case constants::NUMOFRECORDS:
				config.changeConfig(commandValue, value);
				break;
			case constants::BLK_READ:		
				if(atoi(value.c_str()) > 1 || atoi(value.c_str()) < 0)
					{
						std::cout << "Invalid Value, must be 1 or 0\n";
						break;
					}
				config.changeConfig(commandValue, value);
				break;
			case constants::BLK_READ_S:
				if(atoi(value.c_str()) > 1 || atoi(value.c_str()) < 0)
					{
						std::cout << "Invalid Value, must be 1 or 0\n";
						break;
					}
				config.changeConfig(commandValue, value);
				break;
			case constants::KB_READ_S:
				if(atoi(value.c_str()) > 1 || atoi(value.c_str()) < 0)
					{
						std::cout << "Invalid Value, must be 1 or 0\n";
						break;
					}
				config.changeConfig(commandValue, value);
				break;
			case constants::BLK_WRITE:
				if(atoi(value.c_str()) > 1 || atoi(value.c_str()) < 0)
					{
						std::cout << "Invalid Value, must be 1 or 0\n";
						break;
					}
				config.changeConfig(commandValue, value);
				break;
			case constants::BLK_WRITE_S:
				if(atoi(value.c_str()) > 1 || atoi(value.c_str()) < 0)
					{
						std::cout << "Invalid Value, must be 1 or 0\n";
						break;
					}
				config.changeConfig(commandValue, value);
				break;
			case constants::KB_WRITES_S:
				if(atoi(value.c_str()) > 1 || atoi(value.c_str()) < 0)
					{
						std::cout << "Invalid Value, must be 1 or 0\n";
						break;
					}
				config.changeConfig(commandValue, value);
				break;
			case constants::PRINTCONF:
				std::cout << config.printMe() << "\n";
				break;
			case constants::PRINGREPORT:
				std::cout << "\n"<< report.toString();
				break;
			case constants::RESETCONF:
				config.reset();
				std::cout << "Configurations have been reset to defualt\n";
				break;
			case constants::FILENAMECHNG:
				report.setFileName(value);
				break;
			case constants::EXIT:
				return 0;
				break;
			default:
				std::cout << "Invalid Command!\n";
			}
		commandValue = command.getCommand(value);
		}

		
	return 0;
}
