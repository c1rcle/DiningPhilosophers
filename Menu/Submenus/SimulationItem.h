#include <iostream>
#include "../MenuItem.h"
#include "../../Algorithm/Table.h"

class SimulationItem : public MenuItem
{
private:
    int philosopherCount;
    int thinkingTime;
    int eatingTime;
    void printMenu() override;
    void configureParameters();
    void executeSimulation() const;
public:
    SimulationItem();
    void processInput() override;
};