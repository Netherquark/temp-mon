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
      while (i < 1000001){
        auto start = std::chrono::high_resolution_clock::now();

      auto stop = std::chrono::high_resolution_clock::now();
  
      auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);  
      
      system("sudo timeout 0.06s sudo tegrastats --interval 0.001");

      std::cout<< std::fixed << std::setprecision(9) << duration.count() << std::endl;
      
      i++;
      }
       
}
