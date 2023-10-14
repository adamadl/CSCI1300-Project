// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <string>

using namespace std;

class Leaderboard{
    public:
    //Default Constructor
        Leaderboard();

    //Parameterized Constructor
        Leaderboard(string playerName, int money); 

    //Setters
        void setName(string name);
        void setMoney(int finalMoney);

    //Getters
        string getName();
        int getMoney();

    //Data members
    private:
        string playerName;
        int money;
};
#endif