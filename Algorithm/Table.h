#pragma once

#include <vector>
#include <mutex>
#include <thread>
#include "Philosopher.h"
#include "Fork.h"

class Table
{
private:
    int philosopherCount;
    int thinkingTime;
    int eatingTime;
    std::vector<Philosopher> philosophers;
    std::vector<Fork> forks;
    std::vector<std::thread> threads;
    void initializeContainers();
public:
    Table(int philosopherCount, int thinkingTime, int eatingTime);
    void start();
    void stop();
    void changeParameters(int philosopherCount, int thinkingTime, int eatingTime);
    std::vector<Philosopher> &getPhilosophers();
    std::vector<Fork> &getForks();
    int getPhilosopherCount() const;
};