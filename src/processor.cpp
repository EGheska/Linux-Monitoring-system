//
// Created by Dima on 14/01/2023.
//
#include "processor.h"
#include "linux_parser.h"

#include "string"
#include "vector"


float Processor::Utilization() {
    // Return the aggregate CPU utilizations
    std::vector<std::string> cpuUtil = LinuxParser::CpuUtil();
    const long int usertime = std::stol(cpuUtil[0]);
    const long int nicetime = std::stol(cpuUtil[1]);
    const long int systemtime = std::stol(cpuUtil[2]);
    const long int idletime = std::stol(cpuUtil[3]);
    const long int iowait = std::stol(cpuUtil[4]);
    const long int irq = std::stol(cpuUtil[5]);
    const long int softirq = std::stol(cpuUtil[6]);
    const long int steal = std::stol(cpuUtil[7]);

    // Calculate needed current CPU's states values
    const float IDLE = idletime + iowait;
    const float NON_IDLE = usertime + nicetime + systemtime + irq + softirq + steal;
    const float TOTAL = IDLE + NON_IDLE;

    return 0;
}
