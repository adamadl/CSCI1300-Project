// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <string>

using namespace std;
class Questions{
    public:
    //Default Constructor
        Questions();

    //Setters
        void setQuestion(string questionText);
        void setAnswer(string correctResponse);
        void setChoices(string choices);
        void setResponse(string input);
    
    //Getters
        string getChoices();
        string getQuestion();
        string getAnswer();
        string getResponse();

    //Extra
        bool checkAnswer(string response) const;

    //Data Members
    private:
        string question;
        string answer;
        string choices;
        string response;
};
#endif