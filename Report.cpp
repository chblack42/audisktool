/* 
 *Chuck Black
 */
#include "Report.h"

Report::Report()
{
	filename = "report.adt";
}

void Report::setFileName(std::string name)
{
	filename = name;
}

/**
 * Adds the report data to a file
 *
 *@param data The incoming information for the file
 */
void Report::addReport(std::string data[])
{
	std::ofstream fout;
	std::string output;
	fout.open(filename.c_str(),std::ios::app);
	if(fout.is_open())
	{
		for(int i = 0; i <6; i++)
		{
			output.append(data[i]);
			if(i == 0)
			output.append("\t  ");
			else
			output.append("\t\t");
		}
		fout << output;
		fout << '\n';
	}
	
	fout.close();
	
}
/**
 * Prints the contents of the file to a string
 *
 *@return Returns the string of file information
 */
std::string Report::toString()
{
	std::string output="blk_read    blk_read/s   kb_read/s    blk_write     blk_write/s    kb_write/s\n";
	std::string get;
	std::ifstream fin;
	fin.open(filename.c_str());
	if(fin.is_open())
	{

		while(!fin.eof())
		{
			getline(fin,get);
		
			output.append(get);
			
			output.append("\n");
		}
	}

	return output;
}

std::string Report::getFilename()
{
	return filename;
}
