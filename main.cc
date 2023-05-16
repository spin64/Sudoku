#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>

#include "game.h"

int main(int argc, char *argv[]) {
    std::string fileName = "none";

    // for seeding
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{ seed };

    for (int i = 0; i < argc; ++i) {
        if (std::string(argv[i]) == "-load" && i != 0) {
            fileName = std::string(argv[i + 1]);
        } 
    }

    // create class
    game g{rng, fileName};
    g.play();

    return 0;
}