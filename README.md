# ⚙️ Task Scheduler — C++17

A console application that simulates how an Operating System decides **which process runs next** — and when.  
Three scheduling algorithms. Zero STL containers. Pure C++17.

---

## 🧠 How It Works

You feed it tasks. It schedules them.

```
Name: RenderFrame   Priority: 2   Burst: 12ms
Name: SaveFile      Priority: 5   Burst:  8ms
Name: SyncData      Priority: 1   Burst:  5ms
```

Pick an algorithm → get a full execution timeline + performance metrics.

---

## 🔀 Scheduling Algorithms

| Algorithm | Strategy | Data Structure |
|-----------|----------|----------------|
| **FCFS** | First in, first out — no questions asked | `LinkedList<Task>` |
| **Priority** | Lowest number = highest urgency | `PriorityQueue<Task>` Min-Heap |
| **Round Robin** | Everyone gets a turn, no one starves | `LinkedList<Task>` circular |

All three are **non-preemptive** (except Round Robin's time-slice design).

---

## 📊 Output

```
=== Priority Scheduling Result ===
Time  0 -  5  : SyncData     (priority: 1)
Time  5 - 17  : RenderFrame  (priority: 2)
Time 17 - 25  : SaveFile     (priority: 5)

Average Waiting Time    :  7.33 ms
Average Turnaround Time : 14.00 ms
```

---

## 🏗️ Architecture

```
TaskScheduler/
├── main.cpp                  # Menu loop & entry point
├── Task.h / Task.cpp         # Task model (name, priority, burst, remaining)
├── PriorityQueue.h           # Max-Heap — custom, no STL
├── LinkedList.h              # Doubly linked list — custom, no STL
├── Scheduler.h / .cpp        # Abstract base — run(), metrics, output
├── FCFS.h / .cpp             # First-Come-First-Serve
├── PriorityScheduler.h / .cpp# Priority-based scheduling
└── RoundRobin.h / .cpp       # Round Robin with user-defined quantum
```

> Every scheduler inherits from `Scheduler` and overrides a single `run()` — clean, isolated, extensible.

---

## ⚙️ Build & Run

```bash
g++ -std=c++17 main.cpp Task.cpp Scheduler.cpp FCFS.cpp \
    PriorityScheduler.cpp RoundRobin.cpp -o scheduler

./scheduler
```

> Requires: g++ with C++17 support (MinGW on Windows / g++ on Linux)

---

## 🖥️ Menu

```
=== Task Scheduler ===
 1. Add Task
 2. Run FCFS
 3. Run Priority Scheduling
 4. Run Round Robin
 5. Show All Tasks
 0. Exit
```

---

## 🔍 Design Highlights

- **No STL** — `LinkedList<T>` and `PriorityQueue<T>` built from scratch
- **Abstract base class** — `Scheduler` enforces a single interface across all algorithms
- **remainingBurstTime** — tracked separately so Round Robin never corrupts original data
- **True time simulation** — `turnaroundTime = completionTime - arrivalTime`

---

## 🚀 Planned

- [ ] Preemptive Priority Scheduling
- [ ] Gantt Chart ASCII visualization
- [ ] CSV export for results

---

## 👩‍💻 Author

**Nada Magdy** — C++ Systems Developer  
[GitHub](https://github.com/engnadatech2-cmd) · [LinkedIn](https://linkedin.com/in/nada-magdy-6717703b9)
