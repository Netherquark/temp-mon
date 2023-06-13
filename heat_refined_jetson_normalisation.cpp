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
      
      system("sudo timeout 0.06s sudo tegrastats --interval 0.001");
      
      i++;
      }
       
}
