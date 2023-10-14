// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <iostream>
#include <ctype.h>

using namespace std; 

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
 
#endif