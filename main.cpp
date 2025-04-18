#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

// Two forks represented by mutexes
std::mutex fork0;
std::mutex fork1;

// Function to represent a philosopher's behavior
void philosopher(int id) {
    for (int i = 0; i < 3; i++) {
        // Thinking
        std::cout << "Philosopher " << id << " is thinking" << std::endl;
        usleep(500000); // Sleep for 0.5 seconds
        
        std::cout << "Philosopher " << id << " is hungry" << std::endl;
        
        // Resource hierarchy solution - breaking symmetry
        if (id == 0) {
            // Philosopher 0 gets fork0 then fork1
            fork0.lock();
            std::cout << "Philosopher " << id << " got first fork" << std::endl;
            
            fork1.lock();
            std::cout << "Philosopher " << id << " got second fork" << std::endl;
            
            // Eating
            std::cout << "Philosopher " << id << " is eating" << std::endl;
            usleep(500000); // Sleep for 0.5 seconds
            
            // Put down forks
            fork1.unlock();
            fork0.unlock();
        } else {
            // Philosopher 1 gets fork1 then fork0
            fork1.lock();
            std::cout << "Philosopher " << id << " got first fork" << std::endl;
            
            fork0.lock();
            std::cout << "Philosopher " << id << " got second fork" << std::endl;
            
            // Eating
            std::cout << "Philosopher " << id << " is eating" << std::endl;
            usleep(500000); // Sleep for 0.5 seconds
            
            // Put down forks
            fork0.unlock();
            fork1.unlock();
        }
        
        std::cout << "Philosopher " << id << " put down both forks" << std::endl;
    }
}

int main() {
    // Create threads for the two philosophers
    std::thread phil0(philosopher, 0);
    std::thread phil1(philosopher, 1);
    
    // Wait for threads to finish
    phil0.join();
    phil1.join();
    
    return 0;
}
