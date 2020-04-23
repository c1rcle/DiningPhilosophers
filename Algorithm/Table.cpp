#include "Table.h"

Table::Table(int philosopherCount, int thinkingTime, int eatingTime)
{
    this->philosopherCount = philosopherCount;
    this->thinkingTime = thinkingTime;
    this->eatingTime = eatingTime;
}

void Table::start()
{
    initializeContainers();

    for (auto& philosopher : philosophers)
    {
        threads.emplace_back(&Philosopher::run, &philosopher);
    }
}

void Table::stop()
{
    for (auto& philosopher : philosophers)
    {
        philosopher.interrupt();
    }

    for (auto& thread : threads)
    {
        thread.join();
    }
}

void Table::changeParameters(int setPhilosopherCount, int setThinkingTime, int setEatingTime)
{
    this->philosopherCount = setPhilosopherCount;
    this->thinkingTime = setThinkingTime;
    this->eatingTime = setEatingTime;
}

void Table::initializeContainers()
{
    philosophers.clear();
    forks.clear();
    threads.clear();

    forks = std::vector<Fork>(philosopherCount);

    philosophers.emplace_back(0, thinkingTime, eatingTime,
        forks[0], forks[philosopherCount - 1]);

    for (auto i = 1; i < philosopherCount; i++)
    {
        philosophers.emplace_back(i, thinkingTime, eatingTime, forks[i - 1], forks[i]);
        forks[i].forkIdentifier = i;
    }
}

std::vector<Philosopher> &Table::getPhilosophers()
{
    return philosophers;
}

std::vector<Fork> &Table::getForks()
{
    return forks;
}

int Table::getPhilosopherCount() const
{
    return philosopherCount;
}
