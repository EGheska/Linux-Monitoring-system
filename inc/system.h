//
// Created by Dima on 14/01/2023.
//

#ifndef LINUX_MONITORING_SYSTEM_SYSTEM_H
#define LINUX_MONITORING_SYSTEM_SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
public:
    Processor &Cpu();
    std::vector<Process> &Processes();
    float MemoryUtil();
    long upTime();
    int NumOfProcesses();
    int CurrentProcessess();
    std::string Kernel();
    std::string OS();

private:
    // Defining processor called CPU
    Processor cpu_ = {};
    std::vector<Process> processess_ = {};
};

#endif //LINUX_MONITORING_SYSTEM_SYSTEM_H
