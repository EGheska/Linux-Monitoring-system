//
// Created by Dima on 14/01/2023.
//

#include "../inc/system.h"
#include "../inc/processor.h"
#include "../inc/process.h"
#include "../inc/linux_parser.h"

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

}

long System::upTime() {

}

int System::NumOfProcesses() {

}

int System::CurrentProcessess() {

}

std::string System::Kernel(){ return LinuxParser::Kernel(); }

std::string System::OS() {

}

