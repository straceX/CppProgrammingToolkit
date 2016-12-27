#include "file_operations.h"

bool is_fexist(const std::string& name)
{
	return ( access( name.c_str(), F_OK ) != -1 );
}
