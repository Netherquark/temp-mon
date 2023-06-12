#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <chrono>
#include <iomanip>

using namespace std;

int main()
{
      int i = 0;
      while (i < 1001){
        auto start = std::chrono::high_resolution_clock::now();

      auto stop = std::chrono::high_resolution_clock::now();
  
      auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);  
      
      system("sudo turbostat --Summary --interval 0.001 --quiet --num_iterations 1 --hide \"Avg_MHz\" --hide \"Busy%\" --hide \"Bzy_MHz\" --hide \"TSC_MHz\" --hide \"IPC\" --hide \"IRQ\" --hide \"POLL\" --hide \"C1\" --hide \"C2\" --hide \"C3\" --hide \"POLL%\" --hide \"C1%\" --hide \"C2%\" --hide \"C3%\" --hide \"PkgWatt\"");

      std::cout<< std::fixed << std::setprecision(9) << duration.count() << std::endl;
      
      i++;
      }
       
}
