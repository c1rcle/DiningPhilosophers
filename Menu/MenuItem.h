#pragma once
#include <fstream>
#include <ctime>
#include <chrono>
#include <vector>

class MenuItem
{
protected:
    bool backTyped = false;
    std::string menuDescription;
    std::string menuCommand;
    virtual void printMenu() = 0;
public:
    virtual ~MenuItem() = default;
    virtual void processInput() = 0;
    std::string getMenuDescription() { return menuDescription; }
    std::string getMenuCommand() { return menuCommand; }
};