#include <iostream> // cout
#include <ctime>
#include <unistd.h>  // This is for usleep
#include <chrono>  // This is for system_clock:: stuff
//#include <memory> // for smart pointers which I don't use

#include <vector> // std::vector
#include <queue> // std::queue

#include <pthread.h> // posix thread library



uint64_t TimeSinceEpochMicrosec( void )
{
  using namespace std::chrono;
  return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
};


void PrintToScreen(float rel_time, float loop_time)
{
  std::cout << "Time Since Start   : " << rel_time << "\n";
  std::cout << "Previous Loop Time : " << loop_time << "\n\n\n";
};


int main(int argc, char *argv[])
{

  std::cout << "Hello world \n\n";

  // Initialize timing variables
  float rel_time, loop_time, end_time;
  uint64_t t, t_prev, start, time_to_wait, temp_t, prop_time, usleep_time;
  start = TimeSinceEpochMicrosec();
  t = start;
  t_prev = start;
  rel_time = ((float)(t - start))/1000000.0;
  loop_time = ((float)(t - t_prev))/1000000.0;


  // End Time in seconds
  end_time = 10.0;
  prop_time = 1000;  // Microseconds --> Loop time
  usleep_time = 100; // Microseconds --> approx how long it takes to run usleep




  while( rel_time < end_time )
    {

      t = TimeSinceEpochMicrosec();
      rel_time = ((float)(t - start))/1000000.0;
      loop_time = ((float)(t - t_prev))/1000000.0;


      ////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////

      // Do the stuff you would want to do over a timed-loop


      PrintToScreen(rel_time, loop_time);





      ////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////


      // Determine time_to_wait
      t_prev = t;
      time_to_wait = prop_time - ( TimeSinceEpochMicrosec() - t ) - usleep_time;

      std::cout << "time to wait : " << time_to_wait << "\n\n";
      //printf("time to wait : %d",time_to_wait);
      if( time_to_wait > 0)
        {
          usleep( time_to_wait );
        }

    }



  return 0;
}









