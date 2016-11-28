#include "utility.h"

void measure_interval::start_ctimer()
{
  begin_ctime = std::clock();
}

void measure_interval::end_ctimer()
{
  end_ctime = std::clock();
}

float measure_interval::calculate_cinterval()
{
  return  ( ((float) ( end_ctime - begin_ctime )) /  CLOCKS_PER_SEC) * 1000.0;
}

void measure_interval::start_hrtimer()
{
  begin_hrtime = std::chrono::high_resolution_clock::now();
}

 void measure_interval::end_hrtimer()
{
  end_hrtime = std::chrono::high_resolution_clock::now();
}

float measure_interval::calculate_hrinterval()
{
  return std::chrono::duration<double, std::milli>(end_hrtime - begin_hrtime).count();
}

