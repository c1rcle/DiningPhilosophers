#include <iostream>
#include <vector>
#include "MenuItem.h"

class Menu
{
private:
    std::vector<MenuItem *> items;
    bool quitTyped = false;
    bool unknownInput = true;
    void printMenu();
public:
    Menu();
    ~Menu();
    void addMenuItem(MenuItem * item);
    void processInput();
};