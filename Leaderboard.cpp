// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#include "Leaderboard.h"

//Default constructor - sets playerName to empty string and money to 0
Leaderboard::Leaderboard(){
    playerName = "";
    money = 0;
}

//Parameterized constructor - Initializes playerName and money
Leaderboard::Leaderboard(string playerName, int money){
    setName(playerName);
    setMoney(money);
}

//Sets playerName equal to the input name
void Leaderboard::setName(string name){
    playerName = name;
}

//Returns playerName
string Leaderboard::getName(){
    return playerName;
}

//Set money equal to the final money at the end of the game
void Leaderboard::setMoney(int finalMoney){
    money = finalMoney;
}

//Returns money
int Leaderboard::getMoney(){
    return money;
}