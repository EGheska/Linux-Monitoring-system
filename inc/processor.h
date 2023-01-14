//
// Created by Dima on 14/01/2023.
//

#ifndef LINUX_MONITORING_SYSTEM_PROCESSOR_H
#define LINUX_MONITORING_SYSTEM_PROCESSOR_H

class Processor {
public:
    float Utilization();

private:
    // Jiffies from previous CPU states
    long int prevuser{-1};
    long int prevnice{-1};
    long int prevsystem{-1};
    long int previdle{-1};
    long int previowait{-1};
    long int previrg{-1};
    long int prevsoftring{-1};
    long int prevsteal{-1};
};

#endif //LINUX_MONITORING_SYSTEM_PROCESSOR_H
