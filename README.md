# temp-mon
This project is designed to evaluate latency and power consumption for scientific calculations on various platforms, including x86 architectures and NVIDIA Jetson Xavier NX. The repository includes source code for simulations, and scripts for data collection.

```
├── heat_original.cpp                            # Initial version of heat simulation
├── heat_refined.cpp                             # General refined version of the simulation
├── heat_refined_x86.cpp                         # Simulation for x86 platform
├── heat_refined_x86_nt.cpp                      # x86 simulation with multithreading
├── heat_refined_x86_latency.cpp                 # x86 simulation focusing on latency measurement
├── heat_refined_x86_normalisation.cpp           # x86 simulation for normalized data collection
├── heat_refined_jetson.cpp                      # Simulation for Jetson Xavier NX platform
├── heat_refined_jetson_nt.cpp                   # Jetson simulation with multithreading
├── heat_refined_jetson_latency.cpp              # Jetson simulation focusing on latency measurement
├── heat_refined_jetson_normalisation.cpp        # Jetson simulation for normalized data collection
├── jetson_specifications.xlsx                   # Hardware specifications of the Jetson Xavier NX
├── timeout tegrastats logging results.txt       # Logs for Jetson tegrastats performance monitoring
├── command for jetson xavier.txt                # Command script for running on Jetson Xavier NX
├── .git/                                        # Git repository metadata
├── .gitignore                                   # Ignored files for git

```
