#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <chrono>
#include <iomanip>

using namespace std;

int main()
{
    double pi    = acos(-1.);
    
    
    // simulation parameters
    int    nx    = 10000;
    double rd        = 0.1;
    double l     = 2.*pi;
    double alpha = 0.1;
    int itmax        = 1000;
    
    // derived quantities
    double dx        = l/nx;
    double dt        = rd*(dx*dx)/alpha;
    
    double t        = 0.0;
    
    vector<double> u(nx); // container for u 
    vector<double> uana(nx); // container (variable for analytical solution)
    vector<double> du(nx); // container 
    
    
    
    //ofstream fn;
    
    //cout << "size of u = " << u.size() << endl;
    
    // IC
    
    int i = 0;
    
    for (int i=0 ; i<nx ; i++ ){
      u[i] = sin(i*dx);
      uana[i] = sin(i*dx);
      i = i + 1;
    };
    
    //fn.open("u");
    
    for (int it=0; it<=itmax ; it++){
    
      // update time
      t = t + dt;
    
      //cout << "it, t = " << it << ", " << t << endl;
    
      // compute RHS
      du[0] = rd*(u[1]-2*u[0]+u[nx-1]);

       auto start = std::chrono::high_resolution_clock::now();

       for (int i=1 ; i<nx-1 ; i++ ){
      //for (int i=u.begin()+1 ; i != u.end()-1 ; i++ ){
        du[i] = rd*(u[i+1]-2*u[i]+u[i-1]);
      };
      du[nx-1] = rd*(u[0]-2*u[nx-1]+u[nx-2]);
    
      auto stop = std::chrono::high_resolution_clock::now();
  
      auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start);  

      //system("sudo turbostat --Summary --interval 0.001 --quiet --num_iterations 1 --hide "Avg_MHz" --hide "Busy%" --hide "Bzy_MHz" --hide "TSC_MHz" --hide "IPC" --hide "IRQ" --hide "POLL" --hide "C1" --hide "C2" --hide "C3" --hide "POLL%" --hide "C1%" --hide "C2%" --hide "C3%" --hide "PkgWatt"");
      //system("sudo turbostat --Summary --interval 0.001 --quiet --num_iterations 1 --hide \"Avg_MHz\" --hide \"Busy%\" --hide \"Bzy_MHz\" --hide \"TSC_MHz\" --hide \"IPC\" --hide \"IRQ\" --hide \"POLL\" --hide \"C1\" --hide \"C2\" --hide \"C3\" --hide \"POLL%\" --hide \"C1%\" --hide \"C2%\" --hide \"C3%\" --hide \"PkgWatt\"");

      std::cout<< std::fixed << std::setprecision(9) << duration.count() << std::endl;

      // update u and uana
      for (int i=0 ; i<nx ; i++ ){
        u[i] = u[i] + du[i];
        uana[i] = exp(-alpha*t)*sin(i*dx);
      };
    
    
      // write results to file "u"
      //fn << "it, t = " << it << t << endl;
      //for (int i=0 ; i<nx ; i++){
      //  fn << u[i] << " ";
      //}
      //fn << endl;
    
    }
    
   //fn.close();
   
   // write data for accuracy graph
   //ofstream fn1,fn2;
   //fn1.open("com.1");
   //fn2.open("ana.1");
   //
   //for (int i=0 ; i<nx ; i++){
   //  fn1 << u[i] << " ";
   //  fn2 << uana[i] << " ";
   //}
   //
   //
   //fn1.close();
   //fn2.close();


}
