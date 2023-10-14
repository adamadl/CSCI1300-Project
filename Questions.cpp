// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#include "Questions.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor - sets question, answer, and choices to empty strings
Questions::Questions(){
    question = "";
    answer = "";
    choices = "";
    response = "";
}  

//Set question equal to the question from file
void Questions::setQuestion(string questionText){
    question = questionText;
}

//Returns question
string Questions::getQuestion(){
    return question;
}

//Set choices equal to choices from file
void Questions::setChoices(string inputChoices){
    choices = inputChoices;
}

//Returns choices
string Questions::getChoices(){
    return choices;
}

void Questions::setResponse(string input){
    response = input;
}

string Questions::getResponse(){
    return response;
}

//Set the answer equal to the correct answer from file
void Questions::setAnswer(string correctResponse){
    answer = correctResponse;
}

//Returns correct answer
string Questions::getAnswer(){
    return answer;
}

//Checks if the correct answer is equal to the players response and returns a boolean value
bool Questions::checkAnswer(string response) const{
    return response == answer;
}