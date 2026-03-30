#ifndef FCFS_H
#define FCFS_H

#include "Scheduler.h"
#include "LinkedList.h"

class FCFS : public Scheduler {
private:
    LinkedList<Task> queue;

public:
    void addTask(const Task& t) override;
    void run() override;
};

#endif // FCFS_H
