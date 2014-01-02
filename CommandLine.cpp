/* 
 *Chuck Black
 */
#include "CommandLine.h"

CommandLine::CommandLine()
{
}
/**
 *
 * Gets which command is being executed
 *
 *@param value The incoming command
 *
 *@return The int value of the command
 */
int CommandLine::getCommand(std::string &value)
{
	
	std::string command;

	std::cout << ">";
	getline(std::cin,command,'\n');

	//Gets the first word for a command
	std::string first = command.substr(0, command.find(' ')); 

	command = command.substr(command.find(' ')+1, command.size());

	if(first == "help")
		return constants::HELP;
	if(first == "run")
		return constants::RUN;
	if(first == "set")
	{
		//Gets the second world of a command
		std::string second = command.substr(0, command.find(' '));
		command = command.substr(command.find(' ')+1,command.size());
		value = command;
		if(second == "interval")
			return constants::MONITORINTERVAL;
		if(second == "count")
			return constants::NUMOFRECORDS;
		if(second == "report")
			return constants::FILENAMECHNG;
		if(second == "blk_read")
			return constants::BLK_READ;
		if(second == "blk_read/s")
			return constants::BLK_READ_S;
		if(second == "kb_read/s")
			return constants::KB_READ_S;
		if(second == "blk_write")
			return constants::BLK_WRITE;
		if(second == "blk_write/s")
			return constants::BLK_WRITE_S;
		if(second == "kb_write")
			return constants::KB_WRITES_S;
	}
	if(first == "print")
	{
		std::string second = command.substr(0, command.find(' '));
		command = command.substr(command.find(' ')+1,command.size());
		if(second == "config")
			return constants::PRINTCONF;
		if(second == "report")
			return constants::PRINGREPORT;
	}
	
	if(first == "reset")
	{
		std::string second = command.substr(0, command.find(' '));
		command = command.substr(command.find(' ')+1,command.size());
		if(second == "config")
			return constants::RESETCONF;
	}
	if(first == "exit")
		return constants::EXIT;
	

return -1;
		
}
/**
 * Displays the help info
 *
 */
void CommandLine::displayHelp()
{
	std::cout << "\nrun - run the monitoring tool\n" <<
"set interval [value] – set sampling period to [value]\n" <<
"set count [value] – set the number of records to [value]\n" <<
"set report [name] – set report file name to [name]\n" <<
"set blk_read [0|1] – set print_blk_read to 0 or 1\n" <<
"set blk_read/s [0|1] – set print_blk_read/s to 0 or 1\n" <<
"set kb_read/s [0|1] – set print_kb_read/s to 0 or 1\n" <<
"set blk_write [0|1] – set print_blk_write to 0 or 1\n" <<
"set blk_write/s [0|1] – set print_blk_write/s to 0 or 1\n" <<
"set kb_write [0|1] – set print_kb_write to 0 or 1\n" <<
"print config – display all the parameters\n" << 
"print report – open and display the report file\n" <<
"reset config – to set the configuration to default\n" <<
"exit – exit the tool\n";
}


