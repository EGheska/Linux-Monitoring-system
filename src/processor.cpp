#include <string>
#include <vector>

#include "processor.h"
#include "linux_parser.h"

// Returns the aggregate CPU utilization
float Processor::Utilization() { 
  float percentage =(float)LinuxParser::ActiveJiffies()/LinuxParser::Jiffies();
  return percentage;
}
