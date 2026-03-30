[README.md](https://github.com/user-attachments/files/26361294/README.md)
# Task Scheduler

A C++17 console application simulating basic OS process scheduling algorithms. Built dynamically utilizing custom-written generic data structures without relying on conventional STL containers for core algorithm queues or priority organization.

## Features

- **Custom Data Structures**: Internally leverages a custom `LinkedList<T>` (Doubly Linked) and `PriorityQueue` (Max-Heap dynamically customized to prioritize lower numerical priority tags).
- **Core Algorithms**: Precisely simulates three essential CPU scheduling methods:
  - **FCFS** (First-Come-First-Serve)
  - **Priority Scheduling** (Non-preemptive heap-pulled priority execution)
  - **Round Robin** (Preemptive cyclic traversal with user-defined quantum)
- **Interactive Menu**: Reliable user-friendly navigation for loading processes and testing different algorithmic benchmarks instantaneously.
- **Accurate Analysis**: Evaluates accurate context variables, generating detailed output logs displaying `Average Waiting Time` and `Average Turnaround Time`. 

## Architecture

- `Task.h/cpp`: The comprehensive structure mapped for task definitions, embedding dynamic parameters like `remainingBurstTime` for deep algorithms like RR.
- `LinkedList.h`: Doubly-Linked template serving cleanly as FIFO queues and Circular traversals efficiently maintaining single responsibilities.
- `PriorityQueue.h`: Advanced Array-backed Max-Heap dynamically restructuring incoming models according to strictly mapped system priorities.
- `Scheduler.h/cpp`: Pure abstract unification laying out standard benchmarking, reporting metrics, and abstract virtual prototypes (`run()`).
- `FCFS.h/cpp`, `PriorityScheduler.h/cpp`, `RoundRobin.h/cpp`: Derived components extending `Scheduler` representing complete individual algorithms seamlessly isolated in scopes.
- `main.cpp`: Driver mapping out CLI logic gracefully. 

## Build & Run

Ensure you have MinGW or a similar context natively accepting C++17 instructions. Both `std=c++17` strict compilation and sequential linking must occur. 

**Compile:**
```bash
g++ -std=c++17 main.cpp Task.cpp Scheduler.cpp FCFS.cpp PriorityScheduler.cpp RoundRobin.cpp -o scheduler
```

**Run:**
```bash
./scheduler.exe   # Or ./scheduler if on Linux environments
```

## Output Example

```text
=== FCFS Scheduling Result ===
Time 0   - 10  : ProcessName (priority: 2)
Time 10  - 15  : AnotherTask (priority: 5)
Time 15  - 17  : TaskFinal (priority: 1)

Average Waiting Time    : 6.67 ms
Average Turnaround Time : 12.33 ms
```

## Author

Developed under Professional C++ standards enforcing pure Object-Oriented paradigms.
