
#ifdef _WIN32
   #include <io.h>
   #include <errno.h>
   #define access _access
#else
   #include <unistd.h>
#endif

bool is_fexist(const std::string& name);
bool isFileExist(const std::string& filePath); //C++11

int getFileLineNumber(const std::string filename); //C++11

std::string getFileExtension(const std::string& filePath)