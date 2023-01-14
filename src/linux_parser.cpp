//
// Created by Dima on 14/01/2023.
//
#include <string>
#include <vector>
#include <dirent.h>
#include <unistd.h>

#include "../inc/linux_parser.h"

float LinuxParser::MemoryUtil() {
    return 0.0;
}

long LinuxParser::upTime() {
    return 0;
}

std::vector<int> LinuxParser::Pids() {
    return std::vector<int>();
}

int LinuxParser::NumOfProcesses() {
    return 0;
}

int LinuxParser::CurrentProcesses() {
    std::string line;
    std::string key;
    int value;
    std::ifstream stream(kProcDirectory + kStatFilename);
    if (stream.is_open()) {
        while (std::getline(stream, line)) {
            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "processes") {
                    return std::stoi(value);
                }
            }
        }
    }
    return 0;
}

std::string LinuxParser::Kernel() {
    return std::string();
}

std::string LinuxParser::OS() {
    std::string line;
    std::string key;
    std::string value;
    std::ifstream filestream(kOSPath);

    // Read the file line by line
    if(filestream.is_open()){
        while(std::getline(filestream, line)){
            // Parse the line
            std::replace(line.begin(), line.end(), '=', ' ');
            std::replace(line.begin(), line.end(), '"', ' ');
            std::istringstream linestream(line);
            // Read the line for key value pairs and return it
            while(linestream >> key >> value){
                if(key == "PRETTY_NAME"){
                    std::replace(value.begin(), value.end(), '_', ' ');
                    return value;
                }
            }
        }
    }
    return value;
}

std::vector<std::string> LinuxParser::CpuUtil() {
    std::string line;
    std::string key;
    std::string value;
    std::string usertime, nicetime, systemtime, idletime, iowait, irq, softirq, steal;
    std::ifstream filestream(kProcDirectory + kStatFilename);
    if (filestream.is_open()) {
        while (std::getline(filestream, line)) {
            std::istringstream linestream(line);
            while (linestream >> key >> usertime >> nicetime >> systemtime >> idletime >> iowait >> irq >> softirq >> steal) {
                if (key == "cpu") {
                    return {usertime, nicetime, systemtime, idletime, iowait,   irq,      softirq,    steal};
                }
            }
        }
    }
    return {};
}

// Read and return the system memory used by the process
std::string LinuxParser::Ram(int pid) {
    std::string line;
    std::string key;
    std::string value;
    std::ifstream filestream(kProcDirectory + to_string(pid) + kStatusFilename);
    if(filestream.is_open()){
        while(std::getline(filestream, line)){
            std::istringstream linestream(line);
            while(linestream >> key >> value){
                if(key == "VmSize:"){
                    return to_string(stoi(value)/1000); // returns memory usage in MB
                }
            }
        }
    }
    return string();
}
