#ifndef PRIORITYSCHEDULER_H
#define PRIORITYSCHEDULER_H

#include "Scheduler.h"
#include "PriorityQueue.h"

class PriorityScheduler : public Scheduler {
private:
    PriorityQueue pq;

public:
    void addTask(const Task& t) override;
    void run() override;
};

#endif // PRIORITYSCHEDULER_H
