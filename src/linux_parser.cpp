#include <string>
#include <vector>
#include <dirent.h>
#include <unistd.h>
#include <algorithm>
#include <sstream>

#include "linux_parser.h"


//-----------------------------------------------------------------------------
// Utils
//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------
// System
//-----------------------------------------------------------------------------

std::string LinuxParser::OperatingSystem() {
  std::string line;
  std::string key;
  std::string value = "n/a";
  std::ifstream filestream(kOSPath);
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
  std::ifstream stream(kProcDirectory + kVersionFilename);
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
  std::ifstream stream(kProcDirectory + kStatFilename);
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
  std::ifstream stream(kProcDirectory + kMeminfoFilename);
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
  std::string path = kProcDirectory + kStatFilename;
  std::string result = LinuxParser::KeyValParser("processes", path);
  t_processes = std::stoi(result);
  return t_processes;
}

// Reads and returns the number of running processes
int LinuxParser::RunningProcesses() { 
  int a_processes = 0;
  std::string path = kProcDirectory + kStatFilename;
  std::string result = LinuxParser::KeyValParser("procs_running", path);
  a_processes = std::stoi(result);
  return a_processes;
}

// Reads and returns the system uptime
long LinuxParser::UpTime() { 
  long uptime = 0.0;
  std::string temp = "0.0";
  std::string line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> temp;
  }
  uptime = std::atoi(temp.c_str());
  return uptime; 
}

// //-----------------------------------------------------------------------------
// // Processor
// //-----------------------------------------------------------------------------

// Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { 
  std::vector<std::string> jiffies = CpuUtilization();
  long t_jiffies = 0;
  for(std::string jiffie : jiffies) {
    t_jiffies += std::stoi(jiffie);
  }
  return t_jiffies;
}

// Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { 
  long a_jiffies = 0;
  a_jiffies = Jiffies() - IdleJiffies();
  return a_jiffies;
}

// Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { 
  std::vector<std::string> jiffies = CpuUtilization();
  long i_jiffies = 0;
  long idle = std::stoi(jiffies[3]);
  long iowait = std::stoi(jiffies[4]);
  i_jiffies = idle + iowait;
  return i_jiffies;
}
//-----------------------------------------------------------------------------
// Process
//-----------------------------------------------------------------------------

// Reads and returns the uptime of a process
long LinuxParser::UpTime(int pid) { 
  long ticks = 0;
  std::string line;
  std::string skip;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line); 
    for(int i = 1; i < 22; ++i) {
      linestream >> skip;
    }
    linestream >> ticks;
  }
  return ticks / sysconf(_SC_CLK_TCK);
}