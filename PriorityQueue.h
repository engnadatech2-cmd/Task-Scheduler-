#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Task.h"
#include <stdexcept>

// Max-Heap based Priority Queue for Task
// Configured to favor lower priority numbers (1 = highest)
class PriorityQueue {
private:
    Task* heap;
    int capacity;
    int currentSize;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            
            // We want task with lower priority number to bubble up.
            // On tie, we favor the task that arrived first.
            bool swapNeeded = false;
            if (heap[index].priority < heap[parent].priority) {
                swapNeeded = true;
            } else if (heap[index].priority == heap[parent].priority && 
                       heap[index].arrivalTime < heap[parent].arrivalTime) {
                swapNeeded = true;
            }

            if (swapNeeded) {
                Task temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        while (2 * index + 1 < currentSize) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int highest = index;

            if (heap[leftChild].priority < heap[highest].priority ||
               (heap[leftChild].priority == heap[highest].priority && heap[leftChild].arrivalTime < heap[highest].arrivalTime)) {
                highest = leftChild;
            }

            if (rightChild < currentSize && 
                (heap[rightChild].priority < heap[highest].priority ||
                (heap[rightChild].priority == heap[highest].priority && heap[rightChild].arrivalTime < heap[highest].arrivalTime))) {
                highest = rightChild;
            }

            if (highest != index) {
                Task temp = heap[index];
                heap[index] = heap[highest];
                heap[highest] = temp;
                index = highest;
            } else {
                break;
            }
        }
    }

    void resize() {
        capacity *= 2;
        Task* newHeap = new Task[capacity];
        for (int i = 0; i < currentSize; i++) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
    }

public:
    PriorityQueue(int cap = 10) : capacity(cap), currentSize(0) {
        heap = new Task[capacity];
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    // Copy Constructor
    PriorityQueue(const PriorityQueue& other) {
        capacity = other.capacity;
        currentSize = other.currentSize;
        heap = new Task[capacity];
        for (int i = 0; i < currentSize; ++i) {
            heap[i] = other.heap[i];
        }
    }

    // Assignment Operator
    PriorityQueue& operator=(const PriorityQueue& other) {
        if (this != &other) {
            delete[] heap;
            capacity = other.capacity;
            currentSize = other.currentSize;
            heap = new Task[capacity];
            for (int i = 0; i < currentSize; ++i) {
                heap[i] = other.heap[i];
            }
        }
        return *this;
    }

    void push(const Task& task) {
        if (currentSize == capacity) {
            resize();
        }
        heap[currentSize] = task;
        heapifyUp(currentSize);
        currentSize++;
    }

    void pop() {
        if (isEmpty()) return;
        heap[0] = heap[currentSize - 1];
        currentSize--;
        heapifyDown(0);
    }

    Task top() const {
        if (isEmpty()) throw std::out_of_range("Queue is empty");
        return heap[0];
    }

    bool isEmpty() const {
        return currentSize == 0;
    }
};

#endif // PRIORITYQUEUE_H
