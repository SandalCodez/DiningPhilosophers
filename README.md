
# Dining Philosophers Problem

## Overview
This C++ program simulates the classic Dining Philosophers problem with two philosophers. The problem demonstrates concurrent programming challenges and solutions for resource sharing and deadlock prevention.

## Problem Description
- Two philosophers sit at a table
- Two forks are placed between them
- Each philosopher needs two forks to eat
- Philosophers alternate between thinking and eating
- We need to ensure both philosophers can eat without deadlock

## Implementation Details

### Key Components
- **Mutexes**: Two mutex locks (`fork0` and `fork1`) represent the forks and ensure mutual exclusion
- **Threads**: Each philosopher is simulated by a separate thread
- **Resource Hierarchy**: The solution implements a deadlock prevention strategy where philosophers pick up forks in a specific order

### Deadlock Prevention
This solution uses the resource hierarchy approach to prevent deadlock:
- Philosopher 0 always picks up fork0 first, then fork1
- Philosopher 1 always picks up fork1 first, then fork0

By breaking the symmetry (having philosophers grab forks in different orders), we eliminate the circular wait condition necessary for deadlock.

### Execution Flow
Each philosopher repeats the following cycle 3 times:
1. Think (simulated by sleeping)
2. Get hungry
3. Acquire first fork based on ID
4. Acquire second fork based on ID
5. Eat (simulated by sleeping)
6. Release both forks in reverse order of acquisition

## How to Compile and Run

### Requirements
- C++ compiler with C++11 support
- pthread library

### Compilation
```bash
g++ -std=c++11 dining_philosophers.cpp -o dining_philosophers -pthread
```

### Execution
```bash
./dining_philosophers
```

## Expected Output
The program outputs the state changes of each philosopher, showing when they're thinking, hungry, eating, and when they pick up or put down forks.

## Educational Value
This program demonstrates:
- Thread synchronization using mutexes
- Deadlock prevention techniques
- Concurrent resource allocation
- Simple simulation of a classic computer science problem  
