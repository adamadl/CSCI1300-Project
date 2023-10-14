#include "Map.h"
#include "Category.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main() {

    //Single Jeopardy
    Map map;  // create object called map of type Map
    string line = "";
    Category category[50];
    string tempCategory[50];
    string tempCategory1[50];
    int i = 0;
    string fileName1 = "Category.txt";
    ifstream inFile1(fileName1);
    while(getline(inFile1, line)){
        category[i].setCategory(line);
        i++;
    }
    for(int i = 0; i < 6; i++){
        tempCategory[i] = category[i].getCategory();
    }
    map.spawnCategory(tempCategory);
    map.spawnPointValues();
    map.printMap();  
    
    //Double Jeopardy
    for(int i = 5; i < 11; i++){
        tempCategory1[i] = category[i].getCategory(); 
    }
    map.spawnCategoryDouble(tempCategory1);
    map.spawnPointValuesDouble();
    map.printMap(); 
}