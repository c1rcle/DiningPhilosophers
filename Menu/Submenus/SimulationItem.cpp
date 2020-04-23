#include "SimulationItem.h"
#include "../../Visualizer/Visualizer.h"

SimulationItem::SimulationItem()
{
    menuDescription = "Dining philosophers problem simulation (simu)";
    menuCommand = "simu";

    philosopherCount = 5;
    thinkingTime = 4;
    eatingTime = 3;
}

void SimulationItem::printMenu()
{
    std::cout << std::endl;
    std::cout << "Dining philosophers problem simulation menu" << std::endl;
    std::cout << "1. Configure parameters (para)" << std::endl;
    std::cout << "2. Run simulation (exec)" << std::endl;
    std::cout << "3. Go back (back)" << std::endl;
    std::cout << "Choose option: ";
}

void SimulationItem::processInput()
{
    std::string readConsole;
    backTyped = false;
    while (!backTyped)
    {
        printMenu();
        std::cin >> readConsole;
        if (readConsole == "para") configureParameters();
        else if (readConsole == "exec") executeSimulation();
        else if (readConsole == "back") backTyped = true;
        else std::cout << "Unknown command!" << std::endl;
    }
}

void SimulationItem::configureParameters()
{
    std::cout << "\nPhilosophers count: ";
    std::cin >> philosopherCount;
    std::cout << "Thinking time: ";
    std::cin >> thinkingTime;
    std::cout << "Eating time: ";
    std::cin >> eatingTime;
}

void SimulationItem::executeSimulation() const
{
    Visualizer visualizer(philosopherCount, thinkingTime, eatingTime);
    visualizer.startSimulation();
}
