#include <string>
#include <vector>

#include "processor.h"
#include "parser.h"

// Returns the aggregate CPU utilization
float Processor::Utilization() { 
  float percentage =(float)LinuxParser::ActiveTimer()/LinuxParser::Timer();
  return percentage;
}
