#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

#include "sudokuGrid.h"

class game{
    std::default_random_engine rng;
    sudokuGrid g;
public:
    game(std::default_random_engine rng);
    ~game();
    void play();
    void guess();
    void remove();
};

#endif