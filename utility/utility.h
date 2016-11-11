
/*Learn array size via macro*/
#define ARRAY_SIZE(param) (sizeof(param)/sizeof(*(param)));

/*Learn array size via template and constexpr [C++11]*/
template<typename T, size_t n>
constexpr size_t sizeof_array(const T(&r)[n]) { return n; }


