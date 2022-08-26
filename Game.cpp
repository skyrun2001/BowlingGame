#include "Game.h"

class Game {

    /// <summary>
    /// Simulates the roll
    /// </summary>
    /// <param name="pins">Number of thrown pins</param>
public:void roll(int pins) {
        rolls.at(currentRoll) = pins;
        currentRoll++;
    }

    /// <summary>
    /// Sum up the score of the throw.
    /// </summary>
    /// <returns>The score of the game</returns>
public:int score() {

        int score = 0;
        int roll = 0;

        //Max 10 frames allowed
        for (int i = 0; i < 10; i++) {
            //Checks if the roll was a strike
            if (rolls[roll] == 10) {
                score += SumStrike(roll);
                roll++;
            }
            //Checks if the roll was a spare
            if (rolls[roll] + rolls[roll + 1] == 10) {
                score += SumSpare(roll);
                roll += 2;
            }
            else
            {
                score += SumTurn(roll);
                roll += 2;
            }
        }
        return score;
    }
};