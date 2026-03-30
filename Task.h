#ifndef TASK_H
#define TASK_H

#include <string>

struct Task {
    std::string name;
    int priority;         // 1 = highest, 10 = lowest
    int burstTime;
    int arrivalTime;      // auto-incremented by order of entry
    int waitingTime;
    int turnaroundTime;
    int remainingBurstTime; // For preemption in Round Robin

    Task();
    Task(std::string n, int p, int b, int a);
};

#endif // TASK_H
