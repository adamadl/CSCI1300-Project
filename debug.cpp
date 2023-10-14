#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

class Category{
    public:
    //default
        Category();
        Category(string category);
        string getCategory();
        void setCategory(string inputCategory);
    
    private:
        string category;
};

Category::Category(){
    category = "";
}

Category::Category(string category){
    setCategory(category);
}

string Category::getCategory(){
    return category;
}

void Category::setCategory(string inputCategory){
    category = inputCategory;
}

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

class Map
{
     public:
     //Default Constructor
          Map();
          void spawnCategory(string category[50]);
          void spawnPointValues();
          void spawnCategoryDouble(string category1[50]);
          void spawnPointValuesDouble();
          void printMap();
          bool execute(string inputCategory, int pointValue);
          bool executeDouble(string inputCategory, int pointValue);

     //Data members
     private:
          string category[50];
          string category1[50];
          string map[50][50];
          int point[50][50];
          int jeopardy;
          int doubleJeopardy;
};

Map::Map()
{
    jeopardy = 200;
    doubleJeopardy = 400;
}

void Map::spawnCategory(string category[50]){
    for(int i = 0; i < 5; i++){
        map[0][i] = category[i];
    }
}

void Map::spawnPointValues(){
    for(int i = 1; i < 5; i++){
        for(int j = 0; j < 5; j++){
            point[i][j] = jeopardy;
        }
        jeopardy += 200;
    }
}

void Map::spawnCategoryDouble(string category1[50]){
    int j = 5;
    for(int i = 0; i < 5; i++){
        map[0][i] = category1[j];
        j++;
    }
}

void Map::spawnPointValuesDouble(){
    for(int i = 1; i < 5; i++){
        for(int j = 0; j < 5; j++){
            point[i][j] = doubleJeopardy;
        }
        doubleJeopardy += 400;
    }
}

void Map::printMap() {
    for(int i = 0; i < 71; i++){
        cout << "=";
    }
    cout << endl;
    cout << "|";
    for (int i = 0; i < 5; i++){
        cout << setw(12) << map[0][i] << " |";
    }
    cout << endl;
    for(int i = 0; i < 71; i++){
        cout << "=";
    }
    cout << endl;
    for(int i = 1; i < 5; i++){
        cout << "|";
        for(int j = 0; j < 5; j++){
            cout << setw(12) << point[i][j] << " |";
        }
        cout << endl;
        for(int i = 0; i < 71; i++){
            cout << "-";
        }
        cout << endl;
    }
}

bool Map::execute(string inputCategory, int pointValue){
    if(inputCategory == "memes"){
        if(pointValue == 200){
            if(point[1][0] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][0] = 0;
                return true;
            }
        }
        else if(pointValue == 400){
            if(point[2][0] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][0] = 0;
                return true;
            }
        }
        else if(pointValue == 600){
            if(point[3][0] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][0] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[4][0] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][0] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else if(inputCategory == "comp sci"){
        if(pointValue == 200){
            if(point[1][1] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][1] = 0;
                return true;
            }
        }
        else if(pointValue == 400){
            if(point[2][1] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][1] = 0;
                return true;
            }
        }
        else if(pointValue == 600){
            if(point[3][1] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][1] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[4][1] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][1] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else if(inputCategory == "music"){
        if(pointValue == 200){
            if(point[1][2] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][2] = 0;
                return true;
            }
        }
        else if(pointValue == 400){
            if(point[2][2] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][2] = 0;
                return true;
            }
        }
        else if(pointValue == 600){
            if(point[3][2] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][2] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[4][2] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][2] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else if(inputCategory == "crypto"){
        if(pointValue == 200){
            if(point[1][3] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][3] = 0;
                return true;
            }
        }
        else if(pointValue == 400){
            if(point[2][3] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][3] = 0;
                return true;
            }
        }
        else if(pointValue == 600){
            if(point[3][3] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][3] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[4][3] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][3] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else if(inputCategory == "animals"){
        if(pointValue == 200){
            if(point[1][4] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][4] = 0;
                return true;
            }
        }
        else if(pointValue == 400){
            if(point[2][4] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][4] = 0;
                return true;
            }
        }
        else if(pointValue == 600){
            if(point[3][4] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][4] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[4][4] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][4] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else{
        cout << "That is not one of the categories, make sure it is spelled correctly." << endl;
        return false;
    }
}

bool Map::executeDouble(string inputCategory, int pointValue){
    if(inputCategory == "theatre"){
        if(pointValue == 400){
            if(point[1][0] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][0] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[2][0] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][0] = 0;
                return true;
            }
        }
        else if(pointValue == 1200){
            if(point[3][0] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][0] = 0;
                return true;
            }
        }
        else if(pointValue == 1600){
            if(point[4][0] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][0] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else if(inputCategory == "disney"){
        if(pointValue == 400){
            if(point[1][1] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][1] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[2][1] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][1] = 0;
                return true;
            }
        }
        else if(pointValue == 1200){
            if(point[3][1] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][1] = 0;
                return true;
            }
        }
        else if(pointValue == 1600){
            if(point[4][1] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][1] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else if(inputCategory == "plants"){
        if(pointValue == 400){
            if(point[1][2] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][2] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[2][2] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][2] = 0;
                return true;
            }
        }
        else if(pointValue == 1200){
            if(point[3][2] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][2] = 0;
                return true;
            }
        }
        else if(pointValue == 1600){
            if(point[4][2] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][2] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else if(inputCategory == "brands"){
        if(pointValue == 400){
            if(point[1][3] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][3] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[2][3] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][3] = 0;
                return true;
            }
        }
        else if(pointValue == 1200){
            if(point[3][3] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][3] = 0;
                return true;
            }
        }
        else if(pointValue == 1600){
            if(point[4][3] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][3] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else if(inputCategory == "sports"){
        if(pointValue == 400){
            if(point[1][4] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[1][4] = 0;
                return true;
            }
        }
        else if(pointValue == 800){
            if(point[2][4] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[2][4] = 0;
                return true;
            }
        }
        else if(pointValue == 1200){
            if(point[3][4] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[3][4] = 0;
                return true;
            }
        }
        else if(pointValue == 1600){
            if(point[4][4] == 0){
                cout << "You have already answered that question" << endl;
                return false;
            }
            else{
                point[4][4] = 0;
                return true;
            }
        }
        else{
            cout << "That is an invalid point value" << endl;
            return false;
        }
    }
    else{
        cout << "That is not one of the categories, make sure it is spelled correctly." << endl;
        return false;
    }
}

class Questions{
    public:
    //default
        Questions();

        void setQuestion(string questionText);
        void setAnswer(string correctResponse);
        void setChoices(string choices);
        string getChoices();
        bool checkAnswer(string response) const;
        string getQuestion();
        string getAnswer();
    
    private:
        string question;
        string answer;
        string choices;
};

Questions::Questions(){
    question = "";
    answer = "";
    choices = "";
}  

void Questions::setQuestion(string questionText){
    question = questionText;
}

string Questions::getQuestion(){
    return question;
}

void Questions::setChoices(string inputChoices){
    choices = inputChoices;
}

string Questions::getChoices(){
    return choices;
}

void Questions::setAnswer(string correctResponse){
    answer = correctResponse;
}

string Questions::getAnswer(){
    return answer;
}

bool Questions::checkAnswer(string response) const{
    return response == answer;
}

class Scoreboard{ 
    public:
    //default
        Scoreboard();
    //parameterized
        Scoreboard(string playerName);

        string getPlayerName();
        void setPlayerName(string inputPlayer);
        void setMoneyGain(int inputMoney);
        void setMoneyLoss(int inputMoney);
        int getMoney();
        
    private:
        string playerName;
        int money;       
};

Scoreboard::Scoreboard(){
    playerName = "";
    money = 0;
}

Scoreboard::Scoreboard(string playerName){
    setPlayerName(playerName);
}

string Scoreboard::getPlayerName(){
    return playerName;
}

void Scoreboard::setPlayerName(string inputPlayer){
    playerName = inputPlayer;
}

void Scoreboard::setMoneyGain(int inputMoney){
    money += inputMoney;
}

void Scoreboard::setMoneyLoss(int inputMoney){
    money -= inputMoney;
}

int Scoreboard::getMoney(){
    return money;
}

/*Function split as an integer
Parameters are text as string, seperator as character, the array as string, and the size of the array as integer*/
int split(string text, char seperator, string arr[], int size){

    //If the length of the text, or the size is equal to 0, return 0
    if (text.length() == 0 || size == 0){
        return 0;
    }

    //Initalize number as integer equal to 0
    //Initalize len as integer equal to the length of the text
    //Initalize the word as a string variable, this will hold each word in the string
    int num = 0;
    int len = text.length();
    string word = "";

    //For loop with i set to 0, terminate when i reaches the length
    for (int i = 0; i < len; i++){

        /*If the text with position i does not equal the seperator, 
        input each character of the word until the seperator*/
        if (text[i] != seperator){
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

int main(){ 
    int choice4 = 0;
    while(choice4 != 2){
        Map map; //Create object called map of type Map
        map.spawnPointValues();
        string name;
        char choice; //For taking in menu options
        char choice2;
        int choice3 = 0;
        int bet = 1;
        Scoreboard scoreboard; //Create object called scoreboard of type scorebopard
        cout << "=================================\n"
        << "      Welcome to Jeopardy\n"
        << "A twist on the classic game show\n"
        <<"=================================" << endl;

        cout << "Before we begin, please enter your name:" << endl;
        cin >> name;
        cout << "Welcome, " << name << endl;
        cout << "Before we start, would you like to hear the rules? (Y/N)" << endl;
        cin >> choice;
        if(choice == 'N'){
            cout << "Ok, let the game begin!" << endl;
        }
        else{

            //Exit loop when user input N for no
            while(choice != 'N'){
                if (choice == 'Y'){
                    cout << "How to play: \n"
                    << "1. A 4 by 5 board will appear with 5 categories and point values for each category\n"
                    << "2. The player will pick a category and then pick a point value, and a question will be given\n"
                    << "3. If the answer is correct, the amount will be added to Ntheir total score,\n"
                    << "if it is incorrect, then that amount will be deducted from the total\n"
                    << "4. In the event of getting a daily double, the player can choose an amount to bet based of their total amount,\n"
                    << "if the player is correct, that amount will be added to the total, if the player is incorrect, that amount will be deducted\n"
                    << "5. After the first round, there will be a second round where all point values are doubled\n"
                    << "6. The final round will be final jeopardy where the player will be given the category and the question, the player will then\n"
                    << "choose an amount to bet. If they are correct, that amount will be added, if they are inccorrect, the amount will be deducted" << endl;
                    cout << "Are you ready to begin the game? (Y/N)" << endl;
                    cin >> choice2;
                    if(choice2 == 'Y'){
                        cout << "Ok, let the game begin!" << endl;
                        break;
                    }
                    else if(choice2 == 'N'){
                        cout << "Would you like to here the rules again? (Y/N)" << endl;
                        cin >> choice;
                        if(choice == 'N'){
                            cout << "Ok, let the game begin!" << endl;
                        }
                    }
                    else{
                        cout << "Please enter Y for yes or N for no." << endl;
                        cout << "Are you ready to begin the game? (Y/N)" << endl;
                        cin >> choice2;
                    }
                }
                else{
                    cout << "Please enter Y for yes or N for no." << endl;
                    cout << "Would you like to here the rules? (Y/N)" << endl;
                    cin >> choice;
                }
            }
        }
        cin.ignore();
        cout << "Let us see the first board" << endl;
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
            for(int i = 0; i < 6; i++){
                tempCategory[i] = category[i].getCategory();
            }

            //Print map
            map.spawnCategory(tempCategory);
            map.printMap();

            //Input category and point value (case insensitive)
            cout << "Please enter a category for your next question" << endl;
            getline(cin, inputCategory);
            string input = toLower(inputCategory);
            cout << "Now please enter the point value" << endl;
            cin >> pointValue;

            //If user input is invalid
            if(map.execute(input, pointValue) == false){
                i--;
                cin.ignore();
                continue;
            }
            else if(input == "memes"){

                //Read meme questions file
                string line = "";
                ifstream inFile("memeQuestions.txt");
                string arr[50];
                int numOfLines = 0;

                //For ouputting random line in file
                srand(time(0));
                int random = rand() % 23 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, ',', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multipNle choice answers, call member function 
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

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answer) == true){
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

                //For ouputting random line in file
                srand(time(0));
                int random = rand() % 18 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, ',', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multipNle choice answers, call member function 
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

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answer) == true){
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

                //For ouputting random line in file
                srand(time(0));
                int random = rand() % 25 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, ',', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multipNle choice answers, call member function 
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

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answer) == true){
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
                cout << "Success" << endl;
                cin.ignore();
            }
            else if(input == "animals"){
                //Read animal questions file
                string line = "";
                ifstream inFile("animalQuestions.txt");
                string arr[50];
                int numOfLines = 0;

                //For ouputting random line in file
                srand(time(0));
                int random = rand() % 25 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, ',', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multipNle choice answers, call member function 
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

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answer) == true){
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
        cout << "Great job, that is the end of the first round, your total money is now: " << scoreboard.getMoney() << endl;
        while(choice3 != 2){
            cout << "Would you like to continue to the second round or cash out now? (1. Continue, 2. Cash out)" << endl;
            cin >> choice3;
            if(choice3 == 1){
                cout << "Great, let us see the second board" << endl;
                break;
            }
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
        map.spawnPointValuesDouble();
        cin.ignore();
        for(int i = 0; i < 20; i++){ 
            string lineCategory = "";
            Questions question;
            Category category[50];
            string tempCategory[50];
            string answer;
            string inputCategory;
            int pointValue;
            int random = 0;
            int money = 0;
            int numOfCategories = 0;
            int num = 0;
            string fileCategory = "Category.txt";
            ifstream inFile(fileCategory);
            while(getline(inFile, lineCategory)){
                category[numOfCategories].setCategory(lineCategory);
                numOfCategories++;
            }
            for(int i = 5; i < 11; i++){
                tempCategory[i] = category[i].getCategory();
            }
            map.spawnCategoryDouble(tempCategory);
            map.printMap();

            cout << "Please enter a category for your next question" << endl;
            getline(cin, inputCategory);
            string input = toLower(inputCategory);
            cout << "Now please enter the point value" << endl;
            cin >> pointValue;
            if(map.executeDouble(input, pointValue) == false){
                i--;
                cin.ignore();
                continue;
            }
            else if(input == "theatre"){
                //Read theatre questions file
                string line = "";
                ifstream inFile("theatreQuestions.txt");
                string arr[50];
                int numOfLines = 0;

                //For ouputting random line in file
                srand(time(0));
                int random = rand() % 25 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, ',', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multipNle choice answers, call member function 
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

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answer) == true){
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

                //For ouputting random line in file
                srand(time(0));
                int random = rand() % 25 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, ',', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multipNle choice answers, call member function 
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

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answer) == true){
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
                cout << "Success" << endl;
                cin.ignore();
            }
            else if(input == "brands"){
                cout << "Success" << endl;
                cin.ignore();
            }
            else if(input == "sports"){
                //Read sport questions file
                string line = "";
                ifstream inFile("sportQuestions.txt");
                string arr[50];
                int numOfLines = 0;

                //For ouputting random line in file
                srand(time(0));
                int random = rand() % 25 + 1;
                
                //Terminate at end of file
                while(getline(inFile, line)){

                    //Calculate number of lines in file
                    numOfLines++;

                    //If the line number and the random number are equal
                    if(numOfLines == random){

                        //Call split function
                        num = split(line, ',', arr, 50);

                        //For multiple choice questions, number of splits are greater than 2
                        if(num > 2){

                            //arr of 0 is the question, call member function
                            question.setQuestion(arr[0]);
                            cout << question.getQuestion() << endl;

                            //For multiple choice answers
                            for(int i = 1; i < 5; i++){

                                //arr of 1 to 4 are the multipNle choice answers, call member function 
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

                        /*Check the answer using member function from questions class, 
                        if it is correct, add the point value they entered to the total money using scoreboard class
                        if it is incorrect, subtract that money from their total*/
                        if(question.checkAnswer(answer) == true){
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
        if(scoreboard.getMoney() > 0){
            cout << "Great job, that is the end of the second round, your total money is now: " << scoreboard.getMoney() << endl;
            while(choice3 != 2){
                cout << "Would you like to continue to final jeopardy or cash out now? (1. Continue, 2. Cash out)" << endl;
                cin >> choice3;
                if(choice3 == 1){
                    cout << "Great, let's go into final jeopardy" << endl;
                    break;
                }
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
            while(bet <= scoreboard.getMoney()){
                cout << "Please input a value to bet, you can bet a max of $" << scoreboard.getMoney() << endl;
                cin >> bet;
                if(bet > scoreboard.getMoney() || bet < 0){
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
                    split(line, ',', arr, 50);

                    //array of 0 is the question and array of 1 is the answer
                    question.setQuestion(arr[0]);
                    question.setAnswer(arr[1]);
                    cout << question.getQuestion() << endl;
                            
                    //Input answer
                    cout << "Your answer:" << endl;
                    cin.ignore();
                    getline(cin, answer);

                    /*Check the answer using member function from questions class, 
                    if it is correct, add the point value they entered to the total money using scoreboard class
                    if it is incorrect, subtract that money from their total*/
                    if(question.checkAnswer(answer) == true){
                        scoreboard.setMoneyGain(bet);
                        cout << "Correct, " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                    }
                    else{
                        scoreboard.setMoneyLoss(bet);
                        cout << "Incorrect, the correct answer is " << question.getAnswer() << ", " << name << "'s total amount is now $" << scoreboard.getMoney() << endl;
                    }
                }
            } 
            cout << "Congragulations, you have made it to the end of jeopardy, we hope you have enjoyed your time" << endl;
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
        while(choice4 != 2){
            cout << "If you would like to replay the game, press 1, otherwise press 2 to exit" << endl;
            cin >> choice4;
            if(choice4 == 1){
                break;
            }
            else if(choice4 == 2){
                cout << "Thank you for playing Jeopardy" << endl;
                return 0;
            }
            else{
                cout << "Please enter 1 to play again or 2 to exit" << endl;
            } 
        }
    } 
}