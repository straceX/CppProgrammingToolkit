
#ifdef _WIN32
   #include <io.h>
   #include <errno.h>
   #define access _access
#else
   #include <unistd.h>
#endif

bool is_fexist(const std::string& name);