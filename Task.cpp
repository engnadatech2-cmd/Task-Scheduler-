#include "Task.h"

Task::Task() 
    : name("Unknown"), priority(10), burstTime(0), arrivalTime(0),
      waitingTime(0), turnaroundTime(0), remainingBurstTime(0) {}

Task::Task(std::string n, int p, int b, int a)
    : name(n), priority(p), burstTime(b), arrivalTime(a),
      waitingTime(0), turnaroundTime(0), remainingBurstTime(b) {}
