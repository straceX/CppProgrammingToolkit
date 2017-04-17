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


std::string getFileExtension(const std::string& filePath)
{
	std::string result;
	int dotIter;
	int slashIter;

	if(filePath.empty())
		return "";
	
	dotIter = filePath.find_last_of(".");
	slashIter = filePath.find_last_of("/\\");

	if(dotIter > slashIter)
		result = filePath.substr(dotIter + 1);
	else
		result = filePath.substr(slashIter + 1);
	
	return result;
}
