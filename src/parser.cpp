#include <string>
#include <vector>
#include <dirent.h>
#include <unistd.h>
#include <algorithm>
#include <sstream>

#include "parser.h"

// Utils


//Parses the file to find a value for a given key
std::string LinuxParser::KeyValParser(std::string key, std::string path) {
  std::string value = "n/a";
  bool search = true;
  std::string line;
  std::string temp;
  std::ifstream stream(path);
  if(stream.is_open()) {
    while(search == true && stream.peek() != EOF) {
      std::getline(stream, line);
      std::istringstream linestream(line); 
      linestream >> temp;
      if(temp == key) {
        linestream >> temp;
        value = temp;
        search = false;
      } // End inner if
    } // End while
  } // End outer if
  return value; 
}


// System


std::string LinuxParser::OperatingSystem() {
  std::string line;
  std::string key;
  std::string value = "n/a";
  std::ifstream filestream(oSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

std::string LinuxParser::Kernel() {
  std::string skip;
  std::string kernel = "n/a";
  std::string line;
  std::ifstream stream(procDirectory + versionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> skip >> skip >> kernel;
  }
  return kernel;
}
// Reads and returns CPU utilization
std::vector<std::string> LinuxParser::CpuUtilization() { 
  std::vector<std::string> timers;
  std::string timer;
  std::string line;
  std::string skip;
  std::ifstream stream(procDirectory + statFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line); 
    linestream >> skip;
    for(int i = 0; i < 10; ++i) {
      linestream >> timer;
      timers.push_back(timer);
    }
  }
  return timers; 
}

// Reads and returns the system memory utilization
float LinuxParser::MemoryUtilization() { 
  std::string skip;
  std::string temp;
  std::string line;
  float mem = 0.0;
  std::vector<std::string> memory;
  std::ifstream stream(procDirectory + meminfoFilename);
  if (stream.is_open()) {
    for (int i = 0; i < 2; ++i) {
      std::getline(stream, line);
      std::istringstream linestream(line);
      linestream >> skip >> temp >> skip;
      memory.push_back(temp);
    }
  }
  float mem_total = std::stof(memory[0]);
  float mem_free = std::stof(memory[1]);
  mem = (mem_total - mem_free) / mem_total;
  return mem;
}

// Reads and returns the total number of processes
int LinuxParser::TotalProcesses() { 
  int t_processes = 0;
  std::string path = procDirectory + statFilename;
  std::string result = LinuxParser::KeyValParser("processes", path);
  t_processes = std::stoi(result);
  return t_processes;
}

// Reads and returns the number of running processes
int LinuxParser::RunningProcesses() { 
  int a_processes = 0;
  std::string path = procDirectory + statFilename;
  std::string result = LinuxParser::KeyValParser("procs_running", path);
  a_processes = std::stoi(result);
  return a_processes;
}

// Reads and returns the system uptime
long LinuxParser::UpTime() { 
  long uptime = 0.0;
  std::string temp = "0.0";
  std::string line;
  std::ifstream stream(procDirectory + uptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> temp;
  }
  uptime = std::atoi(temp.c_str());
  return uptime; 
}

// Processor

// Read and return the number of unit of time for the system
long LinuxParser::Timer() { 
  std::vector<std::string> timer = CpuUtilization();
  long t_time = 0;
  for(std::string time : timer) {
    t_time += std::stoi(time);
  }
  return t_time;
}

// Read and return the number of active unit of time for the system
long LinuxParser::ActiveTimer() { 
  long a_times = 0;
  a_times = Timer() - IdleTimer();
  return a_times;
}

// Read and return the number of idle unit of time for the system
long LinuxParser::IdleTimer() { 
  std::vector<std::string> times = CpuUtilization();
  long i_times = 0;
  long idle = std::stoi(times[3]);
  long iowait = std::stoi(times[4]);
  i_times = idle + iowait;
  return i_times;
}