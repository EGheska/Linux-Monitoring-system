//
// Created by Dima on 14/01/2023.
//
#include <string>
#include <vector>
#include <dirent.h>
#include <unistd.h>
#include <algorithm>
#include <sstream>

#include "linux_parser.h"


float LinuxParser::MemoryUtil() {
    float total_memory, available_memory;
    std::string line;
    std::string key;
    std::string value;
    std::ifstream filestream(kProcDirectory+kMeminfoFilename);
    if (filestream.is_open()){
        while(std::getline(filestream, line)){
            std::istringstream linestream(line);
            while (linestream >> key >> value){
                if(key == "MemTotal:"){
                    total_memory = std::stof(value);
                }else if(key == "MemAvailable:"){
                    available_memory = std::stof(value);
                }
            }
        }
    }
    if(total_memory == 0.0){
        return 0.0;
    }
    return (total_memory - available_memory)/total_memory;
}

long LinuxParser::upTime() {
    std::string uptime;
    std::string line;
    std::ifstream stream(kProcDirectory + kUptimeFilename);
    if(stream.is_open()){
        std::getline(stream, line);
        std::istringstream linestream(line);
        linestream >> uptime;
    }
    return std::stol(uptime);
}

std::vector<int> LinuxParser::Pids() {
    std::vector<int> pids;
    DIR* directory = opendir(kProcDirectory.c_str());
    struct dirent* file;
    while((file = readdir(directory)) != nullptr){
        if(file -> d_type == DT_DIR){
            
            std::string filename = file -> d_name;
            if(std::all_of(filename.begin(), filename.end(), isdigit)){
                int pid = std::stoi(filename);
                pids.push_back(pid);
            }
        }
    }
    closedir(directory);
    return pids;
}

std::string LinuxParser::Kernel() {
    std::string os;
    std::string line;
    std::string kernel;
    std::string version;
    std::ifstream stream(kProcDirectory + kVersionFilename);
    if(stream.is_open()){
        std::getline(stream, line);
        std::istringstream linestream(line);
        linestream >> os >> version >> kernel;
    }
    return kernel;
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
    std::ifstream filestream(kProcDirectory + std::to_string(pid) + kStatusFilename);
    if(filestream.is_open()){
        while(std::getline(filestream, line)){
            std::istringstream linestream(line);
            while(linestream >> key >> value){
                if(key == "VmSize:"){
                    return std::to_string(stoi(value)/1000); // returns memory usage in MB
                }
            }
        }
    }
    return std::string();
}
int LinuxParser::TotalProcesses(){
    std::string line;
    std::string key;
    std::string value;
    std::ifstream filestream (kProcDirectory + kStatFilename);
    if(filestream.is_open()){
        while(std::getline(filestream,line)){
            std::istringstream linestream(line);
            while(linestream >> key >> value) {
                if (key == "processes") {
                    return std::stoi(value);
                }
            }
        }
    }
    return 0;
}
int LinuxParser::RunningProcesses(){
    std::string line;
    std::string key;
    std::string value;
    std::ifstream filestream (kProcDirectory + kStatFilename);
    if(filestream.is_open()){
        while(std::getline(filestream,line)){
            std::istringstream linestream(line);
            while(linestream >> key >> value) {
                if (key == "procs_running") {
                    return std::stoi(value);
                }
            }
        }
    }
    return 0;
}