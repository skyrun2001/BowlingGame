#include <iostream>
#include "Game.h"
#include <array>

int main() {
    std::string name;
    int pins;
    Game game;

    std::cout << "Welcome to the Bowling Game!" << std::endl;
    std::cout << "What is your name?";
    std::cin >> name;

    game.initGame();
    for(int i =0;i <20;i++){
        std::cout << "Enter roll number " << i <<" for " << name << " here:";
        std::cin >> pins;
        game.roll(pins, name);
    }

    std::cout << "Thank you for playing the Bowling Game!" << std::endl;
    return 0;
}
