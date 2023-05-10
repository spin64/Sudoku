#include "game.h"

game::game(std::default_random_engine rng): rng{rng} {
    g = new sudokuGrid(rng);
}

game::~game(){}

void game::play(){
    std::cout << std::endl;
    while(!(g->checkWin())){
        g->printGrid();
        char c;

        std::cout << std::endl;
        std::cout << "Would you like to guess (g), remove a number (r), reset board (f), or quit (q): " ;
        std::cin >> c;

        if (c == 'g'){
            guess();
        } else if (c == 'r'){
            remove();
        } else if (c == 'f'){
            g->resetGrid();
            std::cout << std::endl;
        }else if (c == 'q'){
            return;
        }
    }
}

void game::guess(){
    int guess,x,y;

    std::cout << "Guess: " ;
    std::cin >> guess;

    if (guess > 9 || guess < 1){
        std::cout << "Invalid guess" << std::endl;
        return;
    }

    std::cout << "At: ";
    std::cin >> x;
    std::cin >> y;

    if (x > 8 || x < 0 || y > 8 || y < 0){
        std::cout << "Invalid cell" << std::endl;
        return;
    }

    std::cout << std::endl;
    g->setGrid(x,y,guess);
}

void game::remove(){
    int x,y;

    std::cout << "Remove unit at: ";
    std::cin >> x;
    std::cin >> y;
    
    if (x > 8 || x < 0 || y > 8 || y < 0){
        std::cout << "Invalid cell" << std::endl;
        return;
    }

    std::cout << std::endl;
    g->removeCell(x,y);
}