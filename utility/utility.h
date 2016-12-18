
/*Learn array size via macro*/
#define ARRAY_SIZE(param) (sizeof(param)/sizeof(*(param)))

/*Learn array size via template and constexpr [C++11]*/
template<typename T, size_t n>
constexpr size_t sizeof_array(const T(&r)[n]) { return n; }

#include <chrono>

class measure_interval
{

private:

    clock_t begin_ctime;
    clock_t end_ctime;

    std::chrono::high_resolution_clock::time_point begin_hrtime;
    std::chrono::high_resolution_clock::time_point end_hrtime;

public:

    void start_ctimer();
    void end_ctimer();
    float calculate_cinterval();
    void start_hrtimer();
    void end_hrtimer();
    float calculate_hrinterval();

};




