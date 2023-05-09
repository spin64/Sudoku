#ifndef _sudokuGrid_H_
#define _sudokuGrid_H_

#include <iostream>
#include "cell.h"

class sudokuGrid{
    cell * grid[9][9];
public:
    sudokuGrid();
    ~sudokuGrid();
    void initGrid();
    bool checkRows();
    bool checkColumns();
    bool checkSquares();
    bool checkWin();
    void setGrid(int x, int y, int n);
    void removeCell(int x, int y);
    void printGrid();
};


#endif