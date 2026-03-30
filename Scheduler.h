#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.h"
#include <iostream>
#include <iomanip>

class Scheduler {
protected:
    int totalTasks;
    double totalWaitingTime;
    double totalTurnaroundTime;

    void printTaskResult(int startTime, int endTime, const Task& t);
    void printAverages();

public:
    Scheduler();
    virtual ~Scheduler() = default;

    virtual void addTask(const Task& t) = 0;
    virtual void run() = 0;
};

#endif // SCHEDULER_H
