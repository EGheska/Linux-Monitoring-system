//
// Created by Dima on 14/01/2023.
//

#ifndef LIN_LINUX_PARSER_H
#define LIN_LINUX_PARSER_H

#include <fstream>
#include <string>
#include <vector>


namespace LinuxParser {

// Paths to system files
 const std::string kProcDirectory{"/proc/"};
 const std::string kStatusFilename{"/status"};
 const std::string kStatFilename{"/stat"};
 const std::string kUptimeFilename{"/uptime"};
 const std::string kMeminfoFilename{"/meminfo"};
 const std::string kVersionFilename{"/version"};
 const std::string kOSPath{"/etc/os-release"};

// System
float MemoryUtilization();
long UpTime();
std::string KeyValParser(std::string, std::string);
int TotalProcesses();
int RunningProcesses();
std::string OperatingSystem();
std::string Kernel();

// CPU
std::vector<std::string> CpuUtilization();
long Jiffies();
long ActiveJiffies();
long IdleJiffies();

long int UpTime(int pid);
}; 


#endif //LIN_LINUX_PARSER_H
