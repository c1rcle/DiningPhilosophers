cmake_minimum_required(VERSION 3.15)
project(DiningPhilosophers)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread -lncurses")

add_executable(DiningPhilosophers main.cpp Algorithm/Philosopher.h Algorithm/Table.h Algorithm/Philosopher.cpp Algorithm/Table.cpp Menu/Menu.h Menu/MenuItem.h Menu/Submenus/SimulationItem.h Menu/Menu.cpp Menu/Submenus/SimulationItem.cpp Algorithm/Fork.h Visualizer/Visualizer.h Visualizer/Visualizer.cpp)
target_link_libraries(${PROJECT_NAME} ncurses)