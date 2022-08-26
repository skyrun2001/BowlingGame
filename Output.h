//
// Created by Kentix on 26.08.22.
//
#include <string>
#include "Frame.h"
#include <array>
#include <iostream>
#ifndef BOWLINGGAME_OUTPUT_H
#define BOWLINGGAME_OUTPUT_H
///Output the game results
class Output{

public:

    /// Prints the game information
    /// \param frames The frame array with all frame of the game
    /// \param playerName  Name of the player which results are shown
    /// \param score Complete score of the game at the moment
    /// \param scores Array of scores for all frames
    void printScore(std::array<Frame, 10> frames, std::string playerName, int score, std::array<int,10> scores){
        std::cout << "+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+" << std::endl;
        std::cout << "¡ Frame ¡   1   ¡   2   ¡   3   ¡   4   ¡   5   ¡   6   ¡   7   ¡   8   ¡   9   ¡   10   ¡ Total ¡" << std::endl;
        std::cout << "+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+" << std::endl;
        for(int i=0;i<10;i++){
            if(i==0) {
                std::cout << "\t\t¡ "<< frames.at(i).rolls.at(0) << " ¡ " << frames.at(i).rolls.at(1);
            } else {
                std::cout << " ¡ "<< frames.at(i).rolls.at(0) << " ¡ " << frames.at(i).rolls.at(1);
            }
        }
        std::cout << " ¡ \t\t ¡"<< std::endl;
        std::cout << "¡ "<< playerName <<"\t+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\t\t ¡" << std::endl;

        for(int i = 0; i < 10; i++){
            if(i==0) {
                std::cout << "\t\t¡ "<< scores.at(i) << "  ";
            } else {
                std::cout << " \t¡ "<< scores.at(i) << "  ";
            }
        }
        std::cout << " ¡ "<< score <<" \t ¡"<< std::endl;
        std::cout << "+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+" << std::endl;
    }
};



#endif //BOWLINGGAME_OUTPUT_H
