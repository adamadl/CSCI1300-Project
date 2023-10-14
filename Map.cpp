// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#include "Map.h"
#include <iomanip>

using namespace std; 

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
    else if(inputCategory == "geography"){
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