// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <string>

using namespace std;

class Scoreboard{ 
    public:
    //Default Constructor
        Scoreboard();

    //Setters
        void setPlayerName(string inputPlayer);
        void setMoneyGain(int inputMoney);
        void setMoneyLoss(int inputMoney);
        void setMoney(int inputMoney);

    //Getters
        int getMoney();
        string getPlayerName();
        
    //Extra
        bool check(int bet);

    //Data Members
    private:
        string playerName;
        int money; 
        int bet;    
};
#endif