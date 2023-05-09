#include "sudokuGrid.h"

sudokuGrid::sudokuGrid(){
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            grid[i][j] = new cell(0,'g');
        }
    }
}

sudokuGrid::~sudokuGrid(){
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            free(grid[i][j]);
        }
    }
}

void sudokuGrid::initGrid(){

}

bool sudokuGrid::checkRows(){
    for (int i = 0; i < 9; ++i){
        int tempSum = 0;
        for(int j = 0; j < 9; ++j){
            tempSum += grid[i][j]->getN();
        }

        if(tempSum != 45){
            return false;
        }
    }
    return true;
}

bool sudokuGrid::checkColumns(){
    for (int i = 0; i < 9; ++i){
        int tempSum = 0;
        for(int j = 0; j < 9; ++j){
            tempSum += grid[i][j]->getN();
        }

        if(tempSum != 45){
            return false;
        }
    }
    return true;
}

bool sudokuGrid::checkSquares(){
    for (int i = 0; i < 9; i += 3){
        int tempSum = 0;
        for(int j = 0; j < 9; j += 3){
            tempSum += grid[i][j]->getN();
            tempSum += grid[i][j + 1]->getN();
            tempSum += grid[i][j + 2]->getN();
            tempSum += grid[i + 1][j]->getN();
            tempSum += grid[i + 1][j + 1]->getN();
            tempSum += grid[i + 1][j + 2]->getN();
            tempSum += grid[i + 2][j]->getN();
            tempSum += grid[i + 2][j + 1]->getN();
            tempSum += grid[i + 2][j + 2]->getN();
        }
        if(tempSum != 45){
            return false;
        } 
    }
    return true;
}

bool sudokuGrid::checkWin(){
    return checkColumns() && checkRows() && checkSquares();
}

void sudokuGrid::setGrid(int x, int y, int n){
    grid[y][x]->setN(n);
}

void sudokuGrid::removeCell(int x, int y){
    grid[y][x] = 0;
}

void sudokuGrid::printGrid(){
    std::cout << "    0 1 2   3 4 5   6 7 8"<< std::endl;
    std::cout << "  -------------------------" << std::endl;
    for (int i = 0; i < 9; ++i){
        std::cout << i << " | ";
        for (int j = 0; j < 9; ++j){
            std::cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                std::cout << "| ";
            }
        }
            if ((i + 1) % 3 ==0) {
                std::cout << std::endl;
                std::cout << "  -------------------------";
            } 
        std::cout << std::endl;
    }
}