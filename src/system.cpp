//
// Created by Dima on 14/01/2023.
//
#include <algorithm>
#include <cstddef>
#include <set>
#include <string>
#include <unistd.h>
#include <vector>
#include "system.h"
#include "processor.h"
#include "process.h"
#include "linux_parser.h"
#include "iostream"

System::System() {
    cpu_ = Processor();
    processess_ = {};
    std::cout << "System created" << std::endl;
}

// Taking the systems CPU
Processor &System::Cpu() { return cpu_; }

// Taking the systems processes in composed container
std::vector<Process> &System::Processes() {
    processess_.clear();
    std::vector<int> pids = LinuxParser::Pids();
    for (unsigned int i = 0; i < pids.size(); i++) {
        Process p = Process(pids[i]);
        processess_.push_back(p);
    }
    // sort the processes by CPU usage
    std::sort(processess_.begin(), processess_.end());
    std::reverse(processess_.begin(), processess_.end());
    return processess_;
}

float System::MemoryUtil() {
    return LinuxParser::MemoryUtil();
}

long System::upTime() {
    return LinuxParser::upTime();
}

int System::TotalProcesses(){
    return LinuxParser::TotalProcesses();
}

int System::RunningProcesses() {
    return LinuxParser::RunningProcesses();
}

std::string System::Kernel(){ return LinuxParser::Kernel(); }

std::string System::OS() {
    return LinuxParser::OS();
}









