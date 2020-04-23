#include <thread>
#include <mutex>
#include "Fork.h"

enum Status
{
    Thinking,
    Hungry,
    Eating
};

class Philosopher
{
private:
    int identifier;
    Status status;
    int progress;
    int thinkingTime;
    int eatingTime;
    Fork *leftFork;
    Fork *rightFork;
    bool isInterrupted;
    void eat();
    void think();
public:
    Philosopher(int identifier, int thinkingTime, int eatingTime,
        Fork &leftFork, Fork &rightFork);
    void interrupt();
    void run();
    int getIdentifier() const;
    Status getStatus();
    int getProgress() const;
};