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

using std::to_string;
using std::vector;

Process::Process(int PID) {
    this->pid = PID;
    updateCpuUtil();
}

int Process::Pid() const {
    return this->pid;
}

std::string Process::User() {
    return "";
}

std::string Process::Command() {
    return "";
}

void Process::updateCpuUtil() {
//    std::vector<std::string> cpu_usage = LinuxParser::ProcessCpuUtil(this->pid);

}

float Process::getCpuUtil() const {
    return  cpu_util;
}

std::string Process::Ram() {
    return LinuxParser::Ram(this->pid);
}



bool Process::operator<(const Process &a) const {
    return true;
}




