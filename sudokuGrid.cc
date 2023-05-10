#include "sudokuGrid.h"

sudokuGrid::sudokuGrid(std::default_random_engine rng): rng{rng}{
    // inintalizses grid with empty cells
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            grid[i][j] = new cell(0,'g');
        }
    }
    initGrid();
}

sudokuGrid::~sudokuGrid(){
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            free(grid[i][j]);
        }
    }
}

void sudokuGrid::initGrid(){
    int remaining = 17;
    std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> chance = {1, 2, 3};
    while(remaining > 0){
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                shuffle(chance.begin(), chance.end(), rng);
                if (chance[0] == 1){
                    shuffle(nums.begin(), nums.end(), rng);
                    if(validNum(i,j,nums[0])){
                        grid[i][j] = new cell(nums[0],'d');
                        remaining--;
                    }
                }
            }
        }
    }
}

bool sudokuGrid::validNum(int row, int col, int num){

    // check if number already exists in row
    for(int i = 0; i < 9; ++i){
        if(grid[row][i]->getN() == num){
            return false;
        }
    }

    // check if number already exists in column
    for(int i = 0; i < 9; ++i){
        if(grid[i][col]->getN() == num){
            return false;
        }
    }

    // start indices are the top left of a 3x3 square
    int rowStart = row - row % 3;
    int colStart = col - col% 3;

    // check if number already exsists in 3x3 square
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[rowStart + i][colStart + j]->getN() == num) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuGrid::checkWin(){
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            if(!validNum(i, j, grid[i][j]->getN())){
                return false;
            }
        }
    }
    return true;
}

void sudokuGrid::setGrid(int x, int y, int n){
    if(grid[y][x]->getType() == 'g') {
        grid[y][x]->setN(n);
    } else {
        std::cout << "Invalid cell" << std::endl << std::endl;
    }
}

void sudokuGrid::resetGrid(){
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            if(grid[i][j]->getType() == 'g'){
                grid[i][j]->setN(0);
            }
        }
    }
}

void sudokuGrid::removeCell(int x, int y){
    grid[y][x]->setN(0);
}

void sudokuGrid::printGrid(){
    std::cout << "    0 1 2   3 4 5   6 7 8"<< std::endl;
    std::cout << "  -------------------------" << std::endl;
    for (int i = 0; i < 9; ++i){
        std::cout << i << " | ";
        for (int j = 0; j < 9; ++j){
            std::cout << grid[i][j]->getN() << " ";
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