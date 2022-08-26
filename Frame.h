//
// Created by Kentix on 26.08.22.
//

#include <array>
#ifndef BOWLINGGAME_FRAME_H
#define BOWLINGGAME_FRAME_H
///Hold all information about a single Frame in the game
class Frame {


public:
    ///Rolled pins
    std::array<int, 2> rolls{};

    ///Current Roll number
    int currentRoll = 0;

};
#endif //BOWLINGGAME_FRAME_H
