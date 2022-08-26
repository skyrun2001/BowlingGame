//
// Created by Kentix on 26.08.22.
//
#include <array>
#include <string>
#include <utility>

#include "Frame.h"
#include "output.h"

#ifndef BOWLINGGAME_GAME_H
#define BOWLINGGAME_GAME_H

class Game {
    ///Array of the row
    std::array<int, 22> rolls{};

    ///Number of current roll
    int currentRoll = 0;

    ///Array of the game frames
    std::array<Frame, 10> frames;

    ///Number of the current frame
    int currentFrame = 0;

    ///Array of the scores for printing the score of each frame
    std::array<int, 10> scores{};

    /// <summary>
    /// Sums up the Strikes
    /// </summary>
    /// <param name="frame">The number of frame in the game</param>
    /// <returns>Returns the count of the strike.</returns>
    int SumStrike(int frame) {
        if(frame !=9){
            return 10 + frames.at(frame + 1).rolls.at(0)+ frames.at(frame + 1).rolls.at(1);
        } else
        {
            return 10 + frames.at(frame).rolls.at(1)+ frames.at(frame).rolls.at(0);
        }

    }

    /// <summary>
    /// Sums ups the spare
    /// </summary>
    /// <param name="frame">The number of frame in the game</param>
    /// <returns>Returns the count of the spare.</returns>
    int SumSpare(int frame) {
        if(frame !=9){
            return 10 + frames.at(frame + 1).rolls.at(0);
        } else {
            return 10 + frames.at(frame).rolls.at(1);
        }

    }

    /// <summary>
    /// Sums up the rolls
    /// </summary>
    /// <param name="frame">The number of frame in the game</param>
    /// <returns>Returns the count of the rolls.</returns>
    int SumTurn(int frame) {
        return frames.at(frame).rolls.at(0) + frames.at(frame).rolls.at(1);
    }

public:

    /// <summary>
    /// Initialize the game
    /// </summary>
    void initGame(){
        for (int i=0; i<10;i++){
            Frame frame;
            frame.frameNumber = i;
            frame.rolls.at(0) = 0;
            frame.rolls.at(1) = 0;
            frames.at(i) = frame;
            scores.at(i)=0;
        }
    }

    ///The name of the player as a public string
    std::string playerName;

    /// <summary>
    /// Simulates the roll
    /// </summary>
    /// <param name="pins">Number of thrown pins</param>
    void roll(int pins, std::string playerNameParam) {
        rolls.at(currentRoll) = pins;
        playerName =std::move(playerNameParam);
        if(currentRoll % 2 == 0 && currentRoll !=0){
            currentFrame++;
        }
        int currentFrameRoll = frames.at(currentFrame).currentRoll;
        frames.at(currentFrame).currentRoll++;
        frames.at(currentFrame).rolls.at(currentFrameRoll) = pins;
        if(pins == 10){
            currentFrame++;
        } else {
            currentRoll++;
        }
        Output output;
        scores.at(currentFrame)= score();
        output.printScore(frames, playerName, score(), scores);
    }

    /// <summary>
    /// Sum up the score of the throw.
    /// </summary>
    /// <returns>The score of the game</returns>
    int score() {

        int score = 0;
        //Max 10 frames allowed
        for (int frame = 0; frame < 10; frame++) {
            for(int roll =0; roll <1; roll++){
                //Checks if the roll was a strike
                if (frames.at(frame).rolls.at(roll) == 10) {
                    score += SumStrike(frame);
                    frame++;
                    break;
                }
                //Checks if the roll was a spare
                if (frames.at(frame).rolls.at(roll) + frames.at(frame).rolls.at(roll+1) == 10) {
                    score += SumSpare(frame);
                    break;
                } else {
                    score += SumTurn(frame);
                }
            }

        }
        return score;
    }

    ///The default constructor
    Game() = default;

};
#endif //BOWLINGGAME_GAME_H
