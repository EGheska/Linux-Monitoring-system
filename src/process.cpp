//
// Created by Dima on 14/01/2023.
//
#include <cctype>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using namespace LinuxParser;

Process::Process(int PID) {
    this->pid = PID;
    updateCpuUtil();
}

int Process::Pid() const {
    return this->pid;
}

std::string Process::User() {
    return LinuxParser::User(this->pid);
}

std::string Process::Command() {
    return LinuxParser::Command(this->pid);
}

void Process::updateCpuUtil() {
    // Get the raw data
    std::vector<std::string> cpu_usage = LinuxParser::ProcessCpuUtil(this->pid);
    const std::size_t utime = std::stol(cpu_usage[0]);
    const std::size_t stime = std::stol(cpu_usage[1]);
    const std::size_t cutime = std::stol(cpu_usage[2]);
    const std::size_t cstime = std::stol(cpu_usage[3]);
    const std::size_t starttime = std::stol(cpu_usage[4]);
    const std::size_t systime = LinuxParser::upTime();

    // Calculate the needed values
    const float TOTAL_TIME = (utime + stime + cutime + cstime) / sysconf(_SC_CLK_TCK);
    const float ELAPSED_TIME = systime - (starttime / sysconf(_SC_CLK_TCK));
    if (ELAPSED_TIME == 0) {
        cpu_util = 0;
    } else {
        cpu_util = TOTAL_TIME / ELAPSED_TIME;
    }
}

float Process::getCpuUtil() const {
    return  cpu_util;
}

std::string Process::Ram() {
    return LinuxParser::Ram(this->pid);
}



bool Process::operator<(const Process &a) const {
    return getCpuUtil() < a.getCpuUtil();
}




