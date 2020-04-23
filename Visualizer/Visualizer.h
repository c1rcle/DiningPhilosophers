#include <ncurses.h>
#include "../Algorithm/Table.h"

class Visualizer
{
private:
    Table *diningTable;
    void initializeWindow();
    void drawPhilosophers();
    void drawForks();
public:
    Visualizer(int philosopherCount, int thinkingTime, int eatingTime);
    ~Visualizer();
    void startSimulation();
    void refreshWindow();
};