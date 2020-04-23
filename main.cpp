#include "Menu/Menu.h"
#include "Menu/Submenus/SimulationItem.h"

int main()
{
    auto * menu = new Menu();
    menu->addMenuItem(new SimulationItem());
    menu->processInput();
    return 0;
}
