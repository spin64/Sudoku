#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

#include "game.h"

int main(int argc, char *argv[]) {

    // for seeding
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{ seed };

    game g{rng};
    g.play();
    return 0;
}