#include "PriorityScheduler.h"
#include <iostream>

void PriorityScheduler::addTask(const Task& t) {
    pq.push(t);
    totalTasks++;
}

void PriorityScheduler::run() {
    std::cout << "\n=== Priority Scheduling Result ===\n";
    if (pq.isEmpty()) {
        std::cout << "No tasks to schedule.\n";
        return;
    }

    int currentTime = 0;
    while (!pq.isEmpty()) {
        Task t = pq.top();
        pq.pop();

        t.waitingTime = currentTime - t.arrivalTime;
        if (t.waitingTime < 0) {
            currentTime = t.arrivalTime;
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
