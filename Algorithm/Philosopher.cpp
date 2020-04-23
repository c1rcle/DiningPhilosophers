#include <iostream>
#include "Philosopher.h"

Philosopher::Philosopher(int identifier, int thinkingTime, int eatingTime,
    Fork &leftFork, Fork &rightFork)
{
    status = Thinking;
    progress = 0;
    isInterrupted = false;

    this->identifier = identifier;
    this->thinkingTime = thinkingTime;
    this->eatingTime = eatingTime;

    this->leftFork = &leftFork;
    this->rightFork = &rightFork;
}

void Philosopher::interrupt()
{
    isInterrupted = true;
}

void Philosopher::run()
{
    while (!isInterrupted)
    {
        eat();
        think();
    }
}

void Philosopher::eat()
{
    status = Hungry;
    std::lock(leftFork->mutex, rightFork->mutex);

    std::lock_guard<std::mutex> leftGuard(leftFork->mutex, std::adopt_lock);
    leftFork->philosopherIdentifier = identifier;
    std::lock_guard<std::mutex> rightGuard(rightFork->mutex, std::adopt_lock);
    rightFork->philosopherIdentifier = identifier;

    status = Eating;
    auto timeElapsed = 0.0;
    auto startTime = std::chrono::high_resolution_clock::now();

    while (timeElapsed / 1000 < eatingTime)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        auto endTime = std::chrono::high_resolution_clock::now();

        timeElapsed = std::chrono::duration<double, std::milli>(endTime - startTime).count();
        progress = (int)(timeElapsed / (eatingTime * 1000) * 100);
    }

    leftFork->philosopherIdentifier = -1;
    rightFork->philosopherIdentifier = -1;
}

void Philosopher::think()
{
    status = Thinking;
    auto timeElapsed = 0.0;
    auto startTime = std::chrono::high_resolution_clock::now();

    while (timeElapsed / 1000 < thinkingTime)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        auto endTime = std::chrono::high_resolution_clock::now();

        timeElapsed = std::chrono::duration<double, std::milli>(endTime - startTime).count();
        progress = (int)(timeElapsed / (thinkingTime * 1000) * 100);
    }
}

int Philosopher::getIdentifier() const
{
    return identifier;
}

Status Philosopher::getStatus()
{
    return status;
}

int Philosopher::getProgress() const
{
    return progress;
}
