#include "RoundRobin.h"
#include <iostream>

RoundRobin::RoundRobin(int q) : quantum(q) {}

void RoundRobin::setQuantum(int q) {
    quantum = q;
}

void RoundRobin::addTask(const Task& t) {
    queue.push_back(t);
    totalTasks++;
}

void RoundRobin::run() {
    std::cout << "\n=== Round Robin Scheduling Result ===\n";
    if (queue.isEmpty()) {
        std::cout << "No tasks to schedule.\n";
        return;
    }

    int currentTime = 0;
    double totalWait = 0;
    double totalTurnaround = 0;
    int tasksCompleted = 0;

    while (!queue.isEmpty()) {
        Task t = queue.front();
        queue.pop_front();

        // Fast-forward time if needed
        if (currentTime < t.arrivalTime) {
            currentTime = t.arrivalTime;
        }

        int startTime = currentTime;
        int executeTime = (t.remainingBurstTime > quantum) ? quantum : t.remainingBurstTime;
        
        t.remainingBurstTime -= executeTime;
        currentTime += executeTime;

        printTaskResult(startTime, currentTime, t);

        if (t.remainingBurstTime > 0) {
            // Task continues execution later
            queue.push_back(t);
        } else {
            // Task finished
            int turnaround = currentTime - t.arrivalTime;
            int wait = turnaround - t.burstTime;
            
            totalTurnaround += turnaround;
            totalWait += wait;
            tasksCompleted++;
        }
    }

    // Set totals for base class to print
    totalTurnaroundTime = totalTurnaround;
    totalWaitingTime = totalWait;

    printAverages();
}
