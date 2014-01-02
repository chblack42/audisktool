/* 
 *Chuck Black
 */
#include "Config.h"


Config::Config()
{

}
/**
 * Edits the config file 
 *
 *@param change Indicates which config option to change
 *@param value The value to change the config option to
 */
void Config::changeConfig(int change, std::string value)
{
	int config[8];
	arrayConfig(config);
	switch(change){
		case constants::MONITORINTERVAL:
				config[0] = atoi(value.c_str());
				break;
		case constants::NUMOFRECORDS:
				config[1] = atoi(value.c_str());
				break;
		case constants::BLK_READ:
				config[2] = atoi(value.c_str());
				break;
		case constants::BLK_READ_S:
				config[3] = atoi(value.c_str());
				break;
		case constants::KB_READ_S:
				config[4] = atoi(value.c_str());
				break;
		case constants::BLK_WRITE:
				config[5] = atoi(value.c_str());
				break;
		case constants::BLK_WRITE_S:
				config[6] = atoi(value.c_str());
				break;
		case constants::KB_WRITES_S:
				config[7] = atoi(value.c_str());
				break;
		default: 
				std::cout << "No changes made";
	}
	
	std::ofstream myOutFile("audisktool.conf");
	std::string output;
	std::stringstream ss;
	if(myOutFile.is_open())
	{
		for(int i = 0; i<8;i++)
		{	
			ss << config[i];
			output.append(ss.str());
			ss.str("");
			
			output.append(" ");
		}
		myOutFile << output;
		myOutFile.close();
	}
}
/**
 * Prints the current configuration to a string
 *
 *@return The string containing the configuration info
 */
std::string Config::toString()
{
	std::ifstream myInFile ("audisktool.conf");
	std::string config;
	if(myInFile.is_open())
	{
			getline(myInFile, config);
	}	
	return config;
}
/**
 * Creates an array with the configuration values
 *
 *@param An array to hold the values
 */
void Config::arrayConfig(int config[])
{
	std::string configValues = toString();
	for(int i=0;i<8;i++)
	{
		config[i] = atoi(configValues.substr(0, configValues.find(' ')).c_str());
		configValues = configValues.substr(configValues.find(' ')+1, configValues.size());
	}
}
/**
 * Prints the configuration with added details
 *
 *@return The string with the detailed information
 */
std::string Config::printMe()
{  
		std::string configValues = toString();
		std::string output = "Monitoring Interval = ";
		output.append(configValues.substr(0,configValues.find(' ')));
		configValues = configValues.substr(configValues.find(' ')+1, configValues.size());
		output.append(" Seconds, Number of records = ");
		output.append(configValues.substr(0,configValues.find(' ')));
		configValues = configValues.substr(configValues.find(' ')+1, configValues.size());
		output.append(", print_blk_read = ");
		output.append(configValues.substr(0,configValues.find(' ')));
		configValues = configValues.substr(configValues.find(' ')+1, configValues.size());
		output.append(", print_blk_read/s = ");
		output.append(configValues.substr(0,configValues.find(' ')));
		configValues = configValues.substr(configValues.find(' ')+1, configValues.size());
		output.append(", print_kb_read/s = ");
		output.append(configValues.substr(0,configValues.find(' ')));
		configValues = configValues.substr(configValues.find(' ')+1, configValues.size());
		output.append(", print_blk_write = ");
		output.append(configValues.substr(0,configValues.find(' ')));
		configValues = configValues.substr(configValues.find(' ')+1, configValues.size());
		output.append(", print_blk_write/s = ");
		output.append(configValues.substr(0,configValues.find(' ')));
		configValues = configValues.substr(configValues.find(' ')+1, configValues.size());
		output.append(", print kb_writes/s = ");
		output.append(configValues.substr(0,configValues.find(' ')));
		return output;
}	
/**
 * Resets the configuration back to default
 */
void Config::reset()
{
	changeConfig(constants::MONITORINTERVAL, constants::DEFAULT);
	changeConfig(constants::NUMOFRECORDS, constants::DEFAULT);
	changeConfig(constants::BLK_READ, constants::DEFAULT);
	changeConfig(constants::BLK_READ_S, constants::DEFAULT);
	changeConfig(constants::KB_READ_S, constants::DEFAULT);
	changeConfig(constants::BLK_WRITE, constants::DEFAULT);
	changeConfig(constants::BLK_WRITE_S, constants::DEFAULT);
	changeConfig(constants::KB_WRITES_S, constants::DEFAULT);
}

	
	
