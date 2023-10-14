// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#include "Questions.h"
#include "Category.h"
#include "Scoreboard.h"
#include "Leaderboard.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*Function split as an integer
Parameters are text as string, separator as character, the array as string, and the size of the array as integer*/
int split(string text, char separator, string arr[], int size){

    //If the length of the text, or the size is equal to 0, return 0
    if (text.length() == 0 || size == 0){
        return 0;
    }

    //Initialize number as integer equal to 0
    //Initialize len as integer equal to the length of the text
    //Initialize the word as a string variable, this will hold each word in the string
    int num = 0;
    int len = text.length();
    string word = "";

    //For loop with i set to 0, terminate when i reaches the length
    for (int i = 0; i < len; i++){

        /*If the text with position i does not equal the separator, 
        input each character of the word until the separator*/
        if (text[i] != separator){
            word = word + text[i];
        }

        /*Else the array with index number is equal to the word
        Increase number by 1
        Reset word to an empty string*/
        else{
            arr[num] = word;
            num++;
            word = "";
        }
    }
    //Put the last word into the array and increase number by 1
    if (num < size){
        arr[num] = word;
        num++;
    }

    //If the number is bigger than the size of the array, return -1
    if (num > size){
        return -1;
    }

    //Return number
    return num;
}

/*
*This functions takes in a string and returns the lowercase of that string
*Parameter: input - the input string
*Returns: lowercase string
*/
string toLower(string input){

    //For loop with i set to 0, terminate at at end of string
    for(int i = 0; i < input.length(); i++){

        //If the character of i in the string is capital, turn it to lowercase
        if(input[i] >= 65 && input[i] <= 90){
            input[i] += 32;
        }
    }
    return input;
}

//Main function
int main(){ 
    int choice4 = 0;

    //Large while loop for replaying the game if user decides to
    while(choice4 != 2){
        Map map; //Create object called map of type Map
        map.spawnPointValues(); //Spawn point values in map
        string name;
        char choice; //For taking in menu options
        char choice2;
        int choice3 = 0;
        int bet = -1;
        Scoreboard scoreboard; //Create object called scoreboard of type scoreboard

        //Welcome page
        cout << "=================================\n"
        << "      Welcome to Jeopardy\n"
        << "A twist on the classic game show\n"
        <<"=================================" << endl;

        //Input name
        cout << "Before we begin, please enter your name:" << endl;
        cin >> name;
        cout << "Welcome, " << name << endl;
        cout << "Before we start, would you like to hear the rules? (Y/N)" << endl;
        cin >> choice;

        //If user input N for no
        if(choice == 'N'){
            cout << "Ok, let the game begin!" << endl;
        }
        else{

            //Exit loop when user input N for no
            while(choice != 'N'){

                //If user inputs Y for yes, output rules
                if (choice == 'Y'){
                    cout << "How to play: \n"
                    << "1. A 4 by 5 board will appear with 5 categories and point values for each category\n"
                    << "2. The player will pick a category and then pick a point value, and a question will be given\n"
                    << "3. If the answer is correct, the amount will be added to the player's total score,\n"
                    << "if it is incorrect, then that amount will be deducted from the total\n"
                    << "4. After the first round, there will be a second round where all point values are doubled\n"
                    << "5. The final round will be final jeopardy where the player will be given the category and the question, the player will then\n"
                    << "choose an amount to bet. If they are correct, that amount will be added, if they are incorrect, the amount will be deducted" << endl;
                    cout << "Are you ready to begin the game? (Y/N)" << endl;
                    cin >> choice2;

                    //Begin game if user inputs Y for yes
                    if(choice2 == 'Y'){
                        cout << "Ok, let the game begin!" << endl;
                        break;
                    }

                    //Else ask again if the want to hear the rules
                    else if(choice2 == 'N'){
                        cout << "Would you like to here the rules again? (Y/N)" << endl;
                        cin >> choice;

                        //If no, begin game
                        if(choice == 'N'){
                            cout << "Ok, let the game begin!" << endl;
                        }
                    }

                    //If user inputs any other character, invalid
                    else{
                        cout << "Please enter Y for yes or N for no." << endl;
                        cout << "Are you ready to begin the game? (Y/N)" << endl;
                        cin >> choice2;
                    }
                }

                //If user inputs any other character, invalid
                else{
                    cout << "Please enter Y for yes or N for no." << endl;
                    cout << "Would you like to here the rules? (Y/N)" << endl;
                    cin >> choice;
                }
            }
        }
        cin.ignore(); // ignores cin
        cout << "Let us see the first board" << endl;

        //For loop for 20 moves on the map
        for(int i = 0; i < 20; i++){ 
            string lineCategory = "";
            Questions question; //Create object called question of type Questions
            Category category[50]; //Create array of Category objects
            string tempCategory[50];
            string answer; //For user answer
            string inputCategory; //For category input
            int pointValue; 
            int random = 0;
            int money = 0;
            int numOfCategories = 0;
            int num = 0;

            //For reading category file and filling array with categorie object
            string fileCategory = "Category.txt";
            ifstream inFile(fileCategory);
            while(getline(inFile, lineCategory)){
                category[numOfCategories].setCategory(lineCategory);
                numOfCategories++;
            }

            //Fill temp array with string from the category array
            for(int i = 0; i < 6; i++){ // using less than 6 because there are 5 categories per board.
                tempCategory[i] = category[i].getCategory();
            }

            //Print map
            map.spawnCategory(tempCategory);
            map.printMap();

            //Input category and point value (case insensitive)
            cout << "Please enter the category for your next question (Enter 'Q' to quit the game)" << endl;
            getline(cin, inputCategory);
            string input = toLower(inputCategory);
            if(input == "q"){
                cout << "Thank you for playing Jeopardy\n"
                << "Your final amount is $" << scoreboard.getMoney() << endl;
                return 0;
            }
            cout << "Now please enter the point value (must be an integer value)" << endl;
            cin >> pointValue;

            //If user input is invalid
            if(map.execute(input, pointValue) == false){

                i--; //To prevent skipping a turn
                cin.ignore(); //Doing getline after a cin
                continue;
            }
            else if(input == "memes"){

                //Read meme questions file
                string line = "";
                ifstream inFile("memeQuestions.txt");
                string arr[50];
                int numOfLines = 0;

                //For outputting random line in file
                srand(time(0));
                int random = rand() % 25 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, '/', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multiple choice answers, call member function 
                                question.setChoices(arr[i]);
                                cout << question.getChoices() << endl;
                            }
                            cout << endl;

                            //arr of 5 is the correct answer, call member function to set answer
                            question.setAnswer(arr[5]);
                        }

                        //For free response questions, number of splits is equal to 2
                        else{

                            //array of 0 is the question and array of 1 is the answer
                            question.setQuestion(arr[0]);
                            question.setAnswer(arr[1]);
                            cout << question.getQuestion() << endl;
                        }

                        //Input answer
                        cout << "Your answer:" << endl;
                        cin.ignore();
                        getline(cin, answer);
                        string answerLower = toLower(answer);

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answerLower) == true){
                            scoreboard.setMoneyGain(pointValue);
                            cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                        else{
                            scoreboard.setMoneyLoss(pointValue);
                            cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                    }
                }

            }
            else if(input == "comp sci"){
                
                //Read comp sci questions file
                string line = "";
                ifstream inFile("CompSciQuestions.txt");
                string arr[50];
                int numOfLines = 0;

                //For outputting random line in file
                srand(time(0));
                int random = rand() % 25 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, '/', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multiple choice answers, call member function 
                                question.setChoices(arr[i]);
                                cout << question.getChoices() << endl;
                            }
                            cout << endl;

                            //arr of 5 is the correct answer, call member function to set answer
                            question.setAnswer(arr[5]);
                        }

                        //For free response questions, number of splits is equal to 2
                        else{

                            //array of 0 is the question and array of 1 is the answer
                            question.setQuestion(arr[0]);
                            question.setAnswer(arr[1]);
                            cout << question.getQuestion() << endl;
                        }

                        //Input answer
                        cout << "Your answer:" << endl;
                        cin.ignore();
                        getline(cin, answer);
                        string answerLower = toLower(answer);

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answerLower) == true){
                            scoreboard.setMoneyGain(pointValue);
                            cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                        else{
                            scoreboard.setMoneyLoss(pointValue);
                            cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                    }
                }
            }
            else if(input == "music"){

                //Read music questions file
                string line = "";
                ifstream inFile("musicQuestions.txt");
                string arr[50];
                int numOfLines = 0;

                //For outputting random line in file
                srand(time(0));
                int random = rand() % 25 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, '/', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multiple choice answers, call member function 
                                question.setChoices(arr[i]);
                                cout << question.getChoices() << endl;
                            }
                            cout << endl;

                            //arr of 5 is the correct answer, call member function to set answer
                            question.setAnswer(arr[5]);
                        }

                        //For free response questions, number of splits is equal to 2
                        else{

                            //array of 0 is the question and array of 1 is the answer
                            question.setQuestion(arr[0]);
                            question.setAnswer(arr[1]);
                            cout << question.getQuestion() << endl;
                        }

                        //Input answer
                        cout << "Your answer:" << endl;
                        cin.ignore();
                        getline(cin, answer);
                        string answerLower = toLower(answer);

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answerLower) == true){
                            scoreboard.setMoneyGain(pointValue);
                            cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                        else{
                            scoreboard.setMoneyLoss(pointValue);
                            cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                    }
                }
            }
            else if(input == "crypto"){
                
                //Read crypto questions file
                string line = "";
                ifstream inFile("cryptoQuestions.txt");
                string arr[50];
                int numOfLines = 0;

                //For outputting random line in file
                srand(time(0));
                int random = rand() % 23 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, '/', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multiple choice answers, call member function 
                                question.setChoices(arr[i]);
                                cout << question.getChoices() << endl;
                            }
                            cout << endl;

                            //arr of 5 is the correct answer, call member function to set answer
                            question.setAnswer(arr[5]);
                        }

                        //For free response questions, number of splits is equal to 2
                        else{

                            //array of 0 is the question and array of 1 is the answer
                            question.setQuestion(arr[0]);
                            question.setAnswer(arr[1]);
                            cout << question.getQuestion() << endl;
                        }

                        //Input answer
                        cout << "Your answer:" << endl;
                        cin.ignore();
                        getline(cin, answer);
                        string answerLower = toLower(answer);

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answerLower) == true){
                            scoreboard.setMoneyGain(pointValue);
                            cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                        else{
                            scoreboard.setMoneyLoss(pointValue);
                            cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                    }
                }
            }
            else if(input == "animals"){

                //Read animal questions file
                string line = "";
                ifstream inFile("animalQuestions.txt");
                string arr[50];
                int numOfLines = 0;

                //For outputting random line in file
                srand(time(0));
                int random = rand() % 25 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, '/', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multiple choice answers, call member function 
                                question.setChoices(arr[i]);
                                cout << question.getChoices() << endl;
                            }
                            cout << endl;

                            //arr of 5 is the correct answer, call member function to set answer
                            question.setAnswer(arr[5]);
                        }

                        //For free response questions, number of splits is equal to 2
                        else{

                            //array of 0 is the question and array of 1 is the answer
                            question.setQuestion(arr[0]);
                            question.setAnswer(arr[1]);
                            cout << question.getQuestion() << endl;
                        }

                        //Input answer
                        cout << "Your answer:" << endl;
                        cin.ignore();
                        getline(cin, answer);
                        string answerLower = toLower(answer);

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answerLower) == true){
                            scoreboard.setMoneyGain(pointValue);
                            cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                        else{
                            scoreboard.setMoneyLoss(pointValue);
                            cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                    }
                }
            }   
        }
        //Output total amount at the end of first round
        cout << "Great job, that is the end of the first round, your total money is now: " << scoreboard.getMoney() << endl;

        //Terminate when user inputs 2
        while(choice3 != 2){
            cout << "Would you like to continue to the second round or cash out now? (1. Continue, 2. Cash out)" << endl;
            cin >> choice3;

            //If user inputs 1, break out of loop and go into second round
            if(choice3 == 1){
                cout << "Great, let us see the second board" << endl;
                break;
            }

            //If user inputs 2, end game
            else if(choice3 == 2){
                cout << "Thank you for playing Jeopardy, your final amount is $" << scoreboard.getMoney() << endl;

                //Write player name and money earned to file
                ofstream outFile;
                outFile.open("players.txt", fstream::app); //fstream::app keeps the info in the file without overwriting it
                outFile << name << ',' << scoreboard.getMoney() << endl;
                outFile.close();
                int numOfPlayers = 0;
                Leaderboard leaderboard[50]; //Create array of Leaderboard objects
                string arr[50];

                //Read file
                ifstream inFile;
                inFile.open("players.txt");
                string line = "";
        
                //Vector pair with integer for their score and string for name of player
                vector<pair<int, string>> leader;

                //Terminate at end of file
                while(getline(inFile, line)){

                    //Call split function
                    split(line, ',', arr, 50);

                    /*Fill leaderboard array with leaderboard object, array of 0 is player name, array of 1 is score,
                    increment numOfPlayers by 1*/
                    leaderboard[numOfPlayers] = Leaderboard(arr[0], stoi(arr[1]));
                    numOfPlayers++;
                }

                //Put the money corresponding with the name into the vector
                for(int i = 0; i < numOfPlayers; i++){
                    leader.push_back(make_pair(leaderboard[i].getMoney(), leaderboard[i].getName()));
                }

                //Sort vector in descending order
                sort(leader.rbegin(), leader.rend());

                //Output leaderboard, name then score
                cout << "Here is the current leaderboard:" << endl;
                cout << "===========Leader Board===========" << endl;
                for (int i = 0; i < numOfPlayers; i++){
                    cout << i + 1 << ". " << leader[i].second << " " << leader[i].first << endl;
                }
                inFile.close();
            }
            else{
                cout << "Please enter 1 to continue or 2 to cash out" << endl;
            }
        }
        
        //Only continue if player inputs 1
        if(choice3 == 1){

            //Spawn double point values in map
            map.spawnPointValuesDouble();
            cin.ignore();

            //For loop for 20 moves on the map
            for(int i = 0; i < 20; i++){ 
                string lineCategory = "";
                Questions question; //Create object called question of type Questions
                Category category[50]; //Create array of Category objects
                string tempCategory[50];
                string answer; //For user answer
                string inputCategory; //For category input
                int pointValue;
                int random = 0;
                int money = 0;
                int numOfCategories = 0;
                int num = 0;

                //For reading category file and filling array with categorie object
                string fileCategory = "Category.txt";
                ifstream inFile(fileCategory);
                while(getline(inFile, lineCategory)){
                    category[numOfCategories].setCategory(lineCategory);
                    numOfCategories++;
                }

                //Fill temp array with string from the category array
                for(int i = 5; i < 11; i++){
                    tempCategory[i] = category[i].getCategory();
                }

                //Print map
                map.spawnCategoryDouble(tempCategory);
                map.printMap();

                //Input category and point value (case insensitive)
                cout << "Please enter a category for your next question (Enter 'Q' to quit the game)" << endl;
                getline(cin, inputCategory);
                string input = toLower(inputCategory);
                if(input == "q"){
                    cout << "Thank you for playing Jeopardy\n"
                    << "Your final amount is $" << scoreboard.getMoney() << endl;
                    return 0;
                }
                cout << "Now please enter the point value (must be an integer value)" << endl;
                cin >> pointValue;

                //If user input is invalid
                if(map.executeDouble(input, pointValue) == false){

                    i--; //To prevent skipping a turn
                    cin.ignore(); //Doing getline after a cin
                    continue;
                }
                else if(input == "theatre"){

                    //Read theatre questions file
                    string line = "";
                    ifstream inFile("theatreQuestions.txt");
                    string arr[50];
                    int numOfLines = 0;

                    //For outputting random line in file
                    srand(time(0));
                    int random = rand() % 25 + 1;
                    
                    //Terminate at end of file
                    while(getline(inFile, line)){

                        //Calculate number of lines in file
                        numOfLines++;

                        //If the line number and the random number are equal
                        if(numOfLines == random){

                            //Call split function
                            num = split(line, '/', arr, 50);

                            //For multiple choice questions, number of splits are greater than 2
                            if(num > 2){

                                //arr of 0 is the question, call member function
                                question.setQuestion(arr[0]);
                                cout << question.getQuestion() << endl;

                                //For multiple choice answers
                                for(int i = 1; i < 5; i++){

                                    //arr of 1 to 4 are the multiple choice answers, call member function 
                                    question.setChoices(arr[i]);
                                    cout << question.getChoices() << endl;
                                }
                                cout << endl;

                                //arr of 5 is the correct answer, call member function to set answer
                                question.setAnswer(arr[5]);
                            }

                            //For free response questions, number of splits is equal to 2
                            else{

                                //array of 0 is the question and array of 1 is the answer
                                question.setQuestion(arr[0]);
                                question.setAnswer(arr[1]);
                                cout << question.getQuestion() << endl;
                            }

                            //Input answer
                            cout << "Your answer:" << endl;
                            cin.ignore();
                            getline(cin, answer);
                            string answerLower = toLower(answer);

                            /*Check the answer using member function from questions class, 
                            if it is correct, add the point value they entered to the total money using scoreboard class
                            if it is incorrect, subtract that money from their total*/
                            if(question.checkAnswer(answerLower) == true){
                                scoreboard.setMoneyGain(pointValue);
                                cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                            else{
                                scoreboard.setMoneyLoss(pointValue);
                                cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                        }
                    }
                }
                else if(input == "disney"){

                    //Read disney questions file
                    string line = "";
                    ifstream inFile("disneyQuestions.txt");
                    string arr[50];
                    int numOfLines = 0;

                    //For outputting random line in file
                    srand(time(0));
                    int random = rand() % 25 + 1;
                    
                    //Terminate at end of file
                    while(getline(inFile, line)){

                        //Calculate number of lines in file
                        numOfLines++;

                        //If the line number and the random number are equal
                        if(numOfLines == random){

                            //Call split function
                            num = split(line, '/', arr, 50);

                            //For multiple choice questions, number of splits are greater than 2
                            if(num > 2){

                                //arr of 0 is the question, call member function
                                question.setQuestion(arr[0]);
                                cout << question.getQuestion() << endl;

                                //For multiple choice answers
                                for(int i = 1; i < 5; i++){

                                    //arr of 1 to 4 are the multiple choice answers, call member function 
                                    question.setChoices(arr[i]);
                                    cout << question.getChoices() << endl;
                                }
                                cout << endl;

                                //arr of 5 is the correct answer, call member function to set answer
                                question.setAnswer(arr[5]);
                            }

                            //For free response questions, number of splits is equal to 2
                            else{

                                //array of 0 is the question and array of 1 is the answer
                                question.setQuestion(arr[0]);
                                question.setAnswer(arr[1]);
                                cout << question.getQuestion() << endl;
                            }

                            //Input answer
                            cout << "Your answer:" << endl;
                            cin.ignore();
                            getline(cin, answer);
                            string answerLower = toLower(answer);

                            /*Check the answer using member function from questions class, 
                            if it is correct, add the point value they entered to the total money using scoreboard class
                            if it is incorrect, subtract that money from their total*/
                            if(question.checkAnswer(answerLower) == true){
                                scoreboard.setMoneyGain(pointValue);
                                cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                            else{
                                scoreboard.setMoneyLoss(pointValue);
                                cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                        }
                    }
                }
                else if(input == "plants"){

                    //Read plants questions file
                    string line = "";
                    ifstream inFile("plantQuestions.txt");
                    string arr[50];
                    int numOfLines = 0;

                    //For outputting random line in file
                    srand(time(0));
                    int random = rand() % 25 + 1;
                    
                    //Terminate at end of file
                    while(getline(inFile, line)){

                        //Calculate number of lines in file
                        numOfLines++;

                        //If the line number and the random number are equal
                        if(numOfLines == random){

                            //Call split function
                            num = split(line, '/', arr, 50);

                            //For multiple choice questions, number of splits are greater than 2
                            if(num > 2){

                                //arr of 0 is the question, call member function
                                question.setQuestion(arr[0]);
                                cout << question.getQuestion() << endl;

                                //For multiple choice answers
                                for(int i = 1; i < 5; i++){

                                    //arr of 1 to 4 are the multiple choice answers, call member function 
                                    question.setChoices(arr[i]);
                                    cout << question.getChoices() << endl;
                                }
                                cout << endl;

                                //arr of 5 is the correct answer, call member function to set answer
                                question.setAnswer(arr[5]);
                            }

                            //For free response questions, number of splits is equal to 2
                            else{

                                //array of 0 is the question and array of 1 is the answer
                                question.setQuestion(arr[0]);
                                question.setAnswer(arr[1]);
                                cout << question.getQuestion() << endl;
                            }

                            //Input answer
                            cout << "Your answer:" << endl;
                            cin.ignore();
                            getline(cin, answer);
                            string answerLower = toLower(answer);

                            /*Check the answer using member function from questions class, 
                            if it is correct, add the point value they entered to the total money using scoreboard class
                            if it is incorrect, subtract that money from their total*/
                            if(question.checkAnswer(answerLower) == true){
                                scoreboard.setMoneyGain(pointValue);
                                cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                            else{
                                scoreboard.setMoneyLoss(pointValue);
                                cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                        }
                    }
                }

                else if(input == "geography"){
                    //Read geography questions file
                    string line = "";
                    ifstream inFile("geographyQuestions.txt");
                    string arr[50];
                    int numOfLines = 0;

                    //For outputting random line in file
                    srand(time(0));
                    int random = rand() % 25 + 1;
                    
                    //Terminate at end of file
                    while(getline(inFile, line)){

                        //Calculate number of lines in file
                        numOfLines++;

                        //If the line number and the random number are equal
                        if(numOfLines == random){

                            //Call split function
                            num = split(line, '/', arr, 50);

                            //For multiple choice questions, number of splits are greater than 2
                            if(num > 2){

                                //arr of 0 is the question, call member function
                                question.setQuestion(arr[0]);
                                cout << question.getQuestion() << endl;

                                //For multiple choice answers
                                for(int i = 1; i < 5; i++){

                                    //arr of 1 to 4 are the multiple choice answers, call member function 
                                    question.setChoices(arr[i]);
                                    cout << question.getChoices() << endl;
                                }
                                cout << endl;

                                //arr of 5 is the correct answer, call member function to set answer
                                question.setAnswer(arr[5]);
                            }

                            //For free response questions, number of splits is equal to 2
                            else{

                                //array of 0 is the question and array of 1 is the answer
                                question.setQuestion(arr[0]);
                                question.setAnswer(arr[1]);
                                cout << question.getQuestion() << endl;
                            }

                            //Input answer
                            cout << "Your answer:" << endl;
                            cin.ignore();
                            getline(cin, answer);
                            string answerLower = toLower(answer);

                            /*Check the answer using member function from questions class, 
                            if it is correct, add the point value they entered to the total money using scoreboard class
                            if it is incorrect, subtract that money from their total*/
                            if(question.checkAnswer(answerLower) == true){
                                scoreboard.setMoneyGain(pointValue);
                                cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                            else{
                                scoreboard.setMoneyLoss(pointValue);
                                cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                        }
                    }
                }
                else if(input == "sports"){
                    //Read sport questions file
                    string line = "";
                    ifstream inFile("sportQuestions.txt");
                    string arr[50];
                    int numOfLines = 0;

                    //For outputting random line in file
                    srand(time(0));
                    int random = rand() % 25 + 1;
                    
                    //Terminate at end of file
                    while(getline(inFile, line)){

                        //Calculate number of lines in file
                        numOfLines++;

                        //If the line number and the random number are equal
                        if(numOfLines == random){

                            //Call split function
                            num = split(line, '/', arr, 50);

                            //For multiple choice questions, number of splits are greater than 2
                            if(num > 2){

                                //arr of 0 is the question, call member function
                                question.setQuestion(arr[0]);
                                cout << question.getQuestion() << endl;

                                //For multiple choice answers
                                for(int i = 1; i < 5; i++){

                                    //arr of 1 to 4 are the multiple choice answers, call member function 
                                    question.setChoices(arr[i]);
                                    cout << question.getChoices() << endl;
                                }
                                cout << endl;

                                //arr of 5 is the correct answer, call member function to set answer
                                question.setAnswer(arr[5]);
                            }

                            //For free response questions, number of splits is equal to 2
                            else{

                                //array of 0 is the question and array of 1 is the answer
                                question.setQuestion(arr[0]);
                                question.setAnswer(arr[1]);
                                cout << question.getQuestion() << endl;
                            }

                            //Input answer
                            cout << "Your answer:" << endl;
                            cin.ignore();
                            getline(cin, answer);
                            string answerLower = toLower(answer);

                            /*Check the answer using member function from questions class, 
                            if it is correct, add the point value they entered to the total money using scoreboard class
                            if it is incorrect, subtract that money from their total*/
                            if(question.checkAnswer(answerLower) == true){
                                scoreboard.setMoneyGain(pointValue);
                                cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                            else{
                                scoreboard.setMoneyLoss(pointValue);
                                cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                            }
                        }
                    }
                }   
            }

            //If final money is positive
            if(scoreboard.getMoney() > 0){
                cout << "Great job, that is the end of the second round, your total money is now: " << scoreboard.getMoney() << endl;

                //Terminate when user inputs 2
                while(choice3 != 2){
                    cout << "Would you like to continue to final jeopardy or cash out now? (1. Continue, 2. Cash out)" << endl;
                    cin >> choice3;

                    //If user inputs 1, break out of loop and go into Final Jeopardy
                    if(choice3 == 1){
                        cout << "Great, let's go into final jeopardy" << endl;
                        break;
                    }

                    //If user inputs 2, end game
                    else if(choice3 == 2){
                        cout << "Thank you for playing Jeopardy, your final amount is $" << scoreboard.getMoney() << endl;

                        //Write player name and money earned to file
                        ofstream outFile;
                        outFile.open("players.txt", fstream::app); //fstream::app keeps the info in the file without overwriting it
                        outFile << name << ',' << scoreboard.getMoney() << endl;
                        outFile.close();
                        int numOfPlayers = 0;
                        Leaderboard leaderboard[50]; //Create array of Leaderboard objects
                        string arr[50];

                        //Read file
                        ifstream inFile;
                        inFile.open("players.txt");
                        string line = "";
            
                        //Vector pair with integer for their score and string for name of player
                        vector<pair<int, string>> leader;

                        //Terminate at end of file
                        while(getline(inFile, line)){

                            //Call split function
                            split(line, ',', arr, 50);

                            /*Fill leaderboard array with leaderboard object, array of 0 is player name, array of 1 is score,
                            increment numOfPlayers by 1*/
                            leaderboard[numOfPlayers] = Leaderboard(arr[0], stoi(arr[1]));
                            numOfPlayers++;
                        }

                        //Put the money corresponding with the name into the vector
                        for(int i = 0; i < numOfPlayers; i++){
                            leader.push_back(make_pair(leaderboard[i].getMoney(), leaderboard[i].getName()));
                        }

                        //Sort vector in descending order
                        sort(leader.rbegin(), leader.rend());

                        //Output leaderboard, name then score
                        cout << "Here is the current leaderboard:" << endl;
                        cout << "===========Leader Board===========" << endl;
                        for (int i = 0; i < numOfPlayers; i++){
                            cout << i + 1 << ". " << leader[i].second << " " << leader[i].first << endl;
                        }
                        inFile.close();
                        return 0;
                    }
                    else{
                        cout << "Please enter 1 to continue or 2 to cash out" << endl;
                    }
                }
            }

            //If money is negative or 0
            else{
                cout << "Thank you for playing jeopardy, your final amount is now $" << scoreboard.getMoney() << endl;
                cout << "Unfortunately, you do not have enough money to continue to final jeopardy, we hope you've had fun" << endl;

                //Write player name and money earned to file
                ofstream outFile;
                outFile.open("players.txt", fstream::app); //fstream::app keeps the info in the file without overwriting it
                outFile << name << ',' << scoreboard.getMoney() << endl;
                outFile.close();
                int numOfPlayers = 0;
                Leaderboard leaderboard[50]; //Create array of Leaderboard objects
                string arr[50];

                //Read file
                ifstream inFile;
                inFile.open("players.txt");
                string line = "";
            
                //Vector pair with integer for their score and string for name of player
                vector<pair<int, string>> leader;

                //Terminate at end of file
                while(getline(inFile, line)){

                    //Call split function
                    split(line, ',', arr, 50);

                    /*Fill leaderboard array with leaderboard object, array of 0 is player name, array of 1 is score,
                    increment numOfPlayers by 1*/
                    leaderboard[numOfPlayers] = Leaderboard(arr[0], stoi(arr[1]));
                    numOfPlayers++;
                }

                //Put the money corresponding with the name into the vector
                for(int i = 0; i < numOfPlayers; i++){
                    leader.push_back(make_pair(leaderboard[i].getMoney(), leaderboard[i].getName()));
                }

                //Sort vector in descending order
                sort(leader.rbegin(), leader.rend());

                //Output leaderboard, name then score
                cout << "Here is the current leaderboard:" << endl;
                cout << "===========Leader Board===========" << endl;
                for (int i = 0; i < numOfPlayers; i++){
                    cout << i + 1 << ". " << leader[i].second << " " << leader[i].first << endl;
                }
                inFile.close();  
            }
            if(choice3 == 1 && scoreboard.getMoney() > 0){
                cout << "=========================\n"
                << "Welcome to Final Jeopardy\n"
                << "=========================\n"
                << "Note: There are no multiple choice questions for final jeopardy\n"
                << "Please make sure your answers are spelled correctly" << endl;

                while(scoreboard.check(bet) == false){
                    cout << "Please input a value to bet, you can bet a max of $" << scoreboard.getMoney() << endl;
                    cin >> bet;
                    if(scoreboard.check(bet) == false){
                        cout << "That is an invalid bet, please make sure you typed it in correctly" << endl;
                    } 
                    else{
                        cout << "Great, you are betting $" << bet << endl;
                        cout << "Let us see the final jeopardy question" << endl;
                        break;
                    }
                }
                //Read final jeopardy questions file
                string line = "";
                ifstream inFile("finalJeopardy.txt");
                string arr[50];
                int numOfLines = 0;
                string answer;
                Questions question;

                //For ouputting random line in file
                srand(time(0));
                int random = rand() % 10 + 1;
                        
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        split(line, '/', arr, 50);

                        //array of 0 is the question and array of 1 is the answer
                        question.setQuestion(arr[0]);
                        question.setAnswer(arr[1]);
                        cout << question.getQuestion() << endl;
                                
                        //Input answer
                        cout << "Your answer:" << endl;
                        cin.ignore();
                        getline(cin, answer);
                        string answerLower = toLower(answer);

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answerLower) == true){
                            scoreboard.setMoneyGain(bet);
                            cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                        else{
                            scoreboard.setMoneyLoss(bet);
                            cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                        }
                    }
                } 
                cout << "Congragulations, you have made it to the end of Jeopardy, we hope you have enjoyed your time" << endl;
                cout << "Your final amount is now $" << scoreboard.getMoney() << endl;

                //Write player name and money earned to file
                ofstream outFile;
                outFile.open("players.txt", fstream::app); //fstream::app keeps the info in the file without overwriting it
                outFile << name << ',' << scoreboard.getMoney() << endl;
                outFile.close();
                int numOfPlayers = 0;
                Leaderboard leaderboard[50]; //Create array of Leaderboard objects
                string arr1[50];

                //Read file
                ifstream inFilePlayers;
                inFilePlayers.open("players.txt");
                string linePlayers = "";
                
                //Vector pair with integer for their score and string for name of player
                vector<pair<int, string>> leader;

                //Terminate at end of file
                while(getline(inFilePlayers, linePlayers)){

                    //Call split function
                    split(linePlayers, ',', arr1, 50);

                    /*Fill leaderboard array with leaderboard object, array of 0 is player name, array of 1 is score,
                    increment numOfPlayers by 1*/
                    leaderboard[numOfPlayers] = Leaderboard(arr1[0], stoi(arr1[1]));
                    numOfPlayers++;
                }

                //Put the money corresponding with the name into the vector
                for(int i = 0; i < numOfPlayers; i++){
                    leader.push_back(make_pair(leaderboard[i].getMoney(), leaderboard[i].getName()));
                }

                //Sort vector in descending order
                sort(leader.rbegin(), leader.rend());

                //Output leaderboard, name then score
                cout << "Here is the current leaderboard:" << endl;
                cout << "===========Leader Board===========" << endl;
                for (int i = 0; i < numOfPlayers; i++){
                    cout << i + 1 << ". " << leader[i].second << " " << leader[i].first << endl;
                }
                inFile.close();
            }
        }
        while(choice4 != 2){
            cout << "If you would like to replay the game, press 1, otherwise press 2 to exit" << endl;
            cin >> choice4;

            //If user inputs 1, break out of this loop and loop through the entire game again
            if(choice4 == 1){
                break;
            }

            //If user input 2, return and exit program
            else if(choice4 == 2){
                cout << "Thank you for playing Jeopardy" << endl;
                return 0;
            }

            //For invalid input
            else{
                cout << "Please enter 1 to play again or 2 to exit" << endl;
            } 
        }
    } 
}