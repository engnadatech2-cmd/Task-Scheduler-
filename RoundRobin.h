#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include "Scheduler.h"
#include "LinkedList.h"

class RoundRobin : public Scheduler {
private:
    LinkedList<Task> queue;
    int quantum;

public:
    RoundRobin(int q = 4);
    void setQuantum(int q);
    void addTask(const Task& t) override;
    void run() override;
};

#endif // ROUNDROBIN_H
