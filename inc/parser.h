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
//virtual file sys 
 const std::string procDirectory{"/proc/"};
 const std::string statFilename{"/stat"};
 const std::string uptimeFilename{"/uptime"};
 const std::string meminfoFilename{"/meminfo"};
 const std::string versionFilename{"/version"};
 const std::string oSPath{"/etc/os-release"};

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
long Timer();
long ActiveTimer();
long IdleTimer();
}; 
#endif //LIN_LINUX_PARSER_H