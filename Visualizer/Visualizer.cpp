#include "Visualizer.h"

Visualizer::Visualizer(int philosopherCount, int thinkingTime, int eatingTime)
{
    diningTable = new Table(philosopherCount, thinkingTime, eatingTime);
}

Visualizer::~Visualizer()
{
    delete diningTable;
}

void Visualizer::startSimulation()
{
    std::thread screenRefresh(&Visualizer::refreshWindow, this);
    screenRefresh.join();
}

void Visualizer::refreshWindow()
{
    initializeWindow();
    diningTable->start();

    while (getch() != 'q')
    {
        drawPhilosophers();
        drawForks();
        refresh();
        napms(100);
    }

    move(diningTable->getPhilosopherCount() * 2 + 2, 0);
    attron(COLOR_PAIR(4));
    clrtoeol();
    printw("Waiting for threads to stop...");
    refresh();

    diningTable->stop();
    endwin();
}

void Visualizer::initializeWindow()
{
    initscr();
    start_color();
    noecho();
    timeout(0);

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);

    move(diningTable->getPhilosopherCount() * 2 + 2, 0);
    addstr("Press 'q' to stop simulation...");
}

void Visualizer::drawPhilosophers()
{
    move(0, 0);
    for (auto& philosopher : diningTable->getPhilosophers())
    {
        std::string status;
        switch (philosopher.getStatus())
        {
            case Thinking:
                attron(COLOR_PAIR(1));
                status = "thinking";
                break;
            case Eating:
                attron(COLOR_PAIR(2));
                status = "eating";
                break;
            default:
                attron(COLOR_PAIR(3));
                status = "hungry";
                break;
        }

        clrtoeol();
        if (status == "hungry")
        {
            printw("Philosopher %d is %s\n", philosopher.getIdentifier(),
                status.c_str());
        }
        else
        {
            printw("Philosopher %d is %s - %d%%\n", philosopher.getIdentifier(),
                status.c_str(), philosopher.getProgress());
        }
    }


}

void Visualizer::drawForks()
{
    move(diningTable->getPhilosopherCount() + 1, 0);
    for (auto& fork : diningTable->getForks())
    {
        clrtoeol();
        if (fork.philosopherIdentifier == -1)
        {
            attron(COLOR_PAIR(4));
            printw("Fork %d is not used\n", fork.forkIdentifier);
        }
        else
        {
            attron(COLOR_PAIR(2));
            printw("Fork %d is held by Philosopher %d\n", fork.forkIdentifier, fork.philosopherIdentifier);
        }
    }
}
