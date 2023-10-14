// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#include "Scoreboard.h"
#include <iostream>
#include <string>

using namespace std;

//Sets playerName to empty string
Scoreboard::Scoreboard(){
    playerName = "";
    money = 0;
    bet = 0;
}

//Set playerName equal to the input name
void Scoreboard::setPlayerName(string inputPlayer){
    playerName = inputPlayer;
}

//Returns playerName
string Scoreboard::getPlayerName(){
    return playerName;
}

void Scoreboard::setMoney(int inputMoney){
    money = inputMoney;
}

//Adds input money to the total money if answer is correct
void Scoreboard::setMoneyGain(int inputMoney){
    money += inputMoney;
}

//Subtracts input money from total money if answer is incorrect
void Scoreboard::setMoneyLoss(int inputMoney){
    money -= inputMoney;
}

//Returns money
int Scoreboard::getMoney(){
    return money;
}

bool Scoreboard::check(int bet){
    if(bet > money || bet <= 0){
        return false;
    }
    else{
        return true;
    }
}