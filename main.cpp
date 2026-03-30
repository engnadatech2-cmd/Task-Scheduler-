// Compile Command:
// g++ -std=c++17 main.cpp Task.cpp Scheduler.cpp FCFS.cpp PriorityScheduler.cpp RoundRobin.cpp -o scheduler

#include <iostream>
#include <string>
#include <iomanip>
#include "FCFS.h"
#include "PriorityScheduler.h"
#include "RoundRobin.h"
#include "LinkedList.h"

using namespace std;

LinkedList<Task> allTasks;
int taskCounter = 0;

void showMenu() {
    cout << "\n=== Task Scheduler Menu ===\n";
    cout << "1. Add Task\n";
    cout << "2. Run FCFS\n";
    cout << "3. Run Priority Scheduling\n";
    cout << "4. Run Round Robin\n";
    cout << "5. Show All Tasks\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

void addTask() {
    string name;
    int priority, burstTime;
    
    cout << "Enter Task Name: ";
    cin >> ws; 
    getline(cin, name);
    
    cout << "Enter Priority (1 = highest, 10 = lowest): ";
    cin >> priority;
    
    cout << "Enter Burst Time (ms): ";
    cin >> burstTime;
    
    int arrivalTime = taskCounter++;
    
    Task t(name, priority, burstTime, arrivalTime);
    allTasks.push_back(t);
    cout << "Task '" << name << "' added successfully. (Arrival Time: " << arrivalTime << ")\n";
}

void showAllTasks() {
    cout << "\n=== All Tasks ===\n";
    if (allTasks.isEmpty()) {
        cout << "No tasks available.\n";
        return;
    }
    
    LinkedList<Task> tempQueue = allTasks;
    cout << setw(7) << "ArrTime" << " | "
         << setw(15) << "Name" << " | "
         << setw(8) << "Priority" << " | "
         << "Burst" << "\n";
    cout << "------------------------------------------------\n";
    while (!tempQueue.isEmpty()) {
        Task t = tempQueue.front();
        tempQueue.pop_front();
        cout << setw(7) << t.arrivalTime << " | "
             << setw(15) << t.name << " | "
             << setw(8) << t.priority << " | "
             << t.burstTime << "\n";
    }
}

void runFCFS() {
    FCFS scheduler;
    LinkedList<Task> temp = allTasks;
    while (!temp.isEmpty()) {
        scheduler.addTask(temp.front());
        temp.pop_front();
    }
    scheduler.run();
}

void runPriority() {
    PriorityScheduler scheduler;
    LinkedList<Task> temp = allTasks;
    while (!temp.isEmpty()) {
        scheduler.addTask(temp.front());
        temp.pop_front();
    }
    scheduler.run();
}

void runRoundRobin() {
    int quantum;
    cout << "Enter Quantum for Round Robin (ms): ";
    cin >> quantum;
    if (quantum <= 0) {
        cout << "Quantum must be > 0. Defaulting to 4.\n";
        quantum = 4;
    }
    
    RoundRobin scheduler(quantum);
    LinkedList<Task> temp = allTasks;
    while (!temp.isEmpty()) {
        scheduler.addTask(temp.front());
        temp.pop_front();
    }
    scheduler.run();
}

int main() {
    int choice = -1;
    
    while (choice != 0) {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        switch (choice) {
            case 1: addTask(); break;
            case 2: runFCFS(); break;
            case 3: runPriority(); break;
            case 4: runRoundRobin(); break;
            case 5: showAllTasks(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
    
    return 0;
}
