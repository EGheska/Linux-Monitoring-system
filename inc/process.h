//
// Created by Dima on 14/01/2023.
//

#ifndef LINUX_MONITORING_SYSTEM_PROCESS_H
#define LINUX_MONITORING_SYSTEM_PROCESS_H
/*
 * Class which represents the processes
 * THis class contains atributes of the processor
 */
#include <string>

class Process{
public:
    Process(int PID);
    int Pid() const;
    std::string User();
    std::string Command();
    void updateCpuUtil();
    float getCpuUtil() const;
    std::string Ram();
    bool operator<(Process const &a) const;

private:
    int pid;
    float cpu_util{0.0};

};

#endif //LINUX_MONITORING_SYSTEM_PROCESS_H
