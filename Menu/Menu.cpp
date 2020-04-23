
#include "Menu.h"

Menu::Menu() = default;

Menu::~Menu()
{
    for (auto item : items)
    {
        delete item;
    }
}

void Menu::addMenuItem(MenuItem *item)
{
    items.push_back(item);
}

void Menu::printMenu()
{
    std::cout << "\nApplication menu" << std::endl;
    int i = 1;
    for (MenuItem * item : items)
    {
        std::cout << i << ". " << item->getMenuDescription() << std::endl;
        i++;
    }
    std::cout << i << ". " << "Quit application (quit)" << std::endl;
    std::cout << "Choose option: ";
}

void Menu::processInput()
{
    std::string readConsole;
    quitTyped = false;
    while (!quitTyped)
    {
        printMenu();
        std::cin >> readConsole;
        unknownInput = true;
        if (readConsole == "quit")
        {
            quitTyped = true;
            unknownInput = false;
        }

        for (MenuItem * item : items)
        {
            if (readConsole == item->getMenuCommand())
            {
                item->processInput();
                unknownInput = false;
            }
        }
        if (unknownInput) std::cout << "Unknown command!" << std::endl;
    }
}