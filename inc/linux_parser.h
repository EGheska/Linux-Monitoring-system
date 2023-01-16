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
    static std::string const kProcDirectory{"/proc/"};
    static std::string const kCmdlineFilename{"/cmdline"};
    static std::string const kCpuinfoFilename{"/cpuinfo"};
    static std::string const kStatusFilename{"/status"};
    static std::string const kStatFilename{"/stat"};
    static std::string const kUptimeFilename{"/uptime"};
    static std::string const kMeminfoFilename{"/meminfo"};
    static std::string const kVersionFilename{"/version"};
    static std::string const kOSPath{"/etc/os-release"};
    static std::string const kPasswordPath{"/etc/passwd"};

// System
    float MemoryUtil();
    long upTime();
    std::vector<int> Pids();
    int TotalProcesses();
    int RunningProcesses();
    std::string OS();
    std::string Kernel();

// CPU
    enum CPUStates {
        kUser_ = 0,
        kNice_,
        kSystem_,
        kIdle_,
        kIOwait_,
        kIRQ_,
        kSoftIRQ_,
        kSteal_,
        kGuest_,
        kGuestNice_
    };
    std::vector<std::string> CpuUtil();

    std::string Ram(int pid);
// Processes
    std::string Command(int pid);
    std::string Uid(int pid);
    std::string User(int pid);
    long int UpTime(int pid);
    std::vector<std::string> ProcessCpuUtil(int pid);
};


#endif //LIN_LINUX_PARSER_H
