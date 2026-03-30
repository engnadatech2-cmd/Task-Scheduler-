#include "FCFS.h"
#include <iostream>

void FCFS::addTask(const Task& t) {
    queue.push_back(t);
    totalTasks++;
}

void FCFS::run() {
    std::cout << "\n=== FCFS Scheduling Result ===\n";
    if (queue.isEmpty()) {
        std::cout << "No tasks to schedule.\n";
        return;
    }

    int currentTime = 0;
    while (!queue.isEmpty()) {
        Task t = queue.front();
        queue.pop_front();

        t.waitingTime = currentTime - t.arrivalTime;
        if (t.waitingTime < 0) {
            currentTime = t.arrivalTime; // System idle time
            t.waitingTime = 0;
        }

        int startTime = currentTime;
        currentTime += t.burstTime;
        t.turnaroundTime = t.waitingTime + t.burstTime;

        totalWaitingTime += t.waitingTime;
        totalTurnaroundTime += t.turnaroundTime;

        printTaskResult(startTime, currentTime, t);
    }

    printAverages();
}
