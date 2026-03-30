#include "Scheduler.h"

Scheduler::Scheduler() : totalTasks(0), totalWaitingTime(0.0), totalTurnaroundTime(0.0) {}

void Scheduler::printTaskResult(int startTime, int endTime, const Task& t) {
    std::cout << "Time " << std::setw(3) << std::left << startTime 
              << " - " << std::setw(3) << std::left << endTime 
              << ": " << t.name << " (priority: " << t.priority << ")\n";
}

void Scheduler::printAverages() {
    if (totalTasks > 0) {
        std::cout << "Average Waiting Time    : " 
                  << std::fixed << std::setprecision(2) 
                  << (totalWaitingTime / totalTasks) << " ms\n";
        std::cout << "Average Turnaround Time : " 
                  << std::fixed << std::setprecision(2) 
                  << (totalTurnaroundTime / totalTasks) << " ms\n";
    }
}
