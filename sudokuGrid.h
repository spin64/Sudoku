#ifndef _sudokuGrid_H_
#define _sudokuGrid_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include <string>

#include "cell.h"

class sudokuGrid{
    cell * grid[9][9];
    std::default_random_engine rng;
public:
    sudokuGrid(std::default_random_engine rng, std::string fileName);
    ~sudokuGrid();
    void initGrid();
    bool checkWin();
    bool validNum(int row, int col, int num);
    void setGrid(int x, int y, int n);
    void resetGrid();
    void removeCell(int x, int y);
    void printGrid();
    void saveGrid(std::string name);
    void loadGrid();
};


#endif