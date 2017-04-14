#include "file_operations.h"

bool is_fexist(const std::string& name)
{
	return ( access( name.c_str(), F_OK ) != -1 );
}

bool isFileExist(const std::string& filePath)
{
	std::ifstream ifile(filePath); 
	return ifile.is_open();
}


int getFileLineNumber(const std::string filename)
{
	int lineCount=0;
	std::string line;
	std::string source="";
	
	std::ifstream mfile(filename);


	while (std::getline(mfile, line))
		lineCount++;

	return lineCount;
}

