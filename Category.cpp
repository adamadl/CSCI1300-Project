// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy

#include "Category.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor - sets category to empty string
Category::Category(){
    category = "";
}

//Sets category to the input category
void Category::setCategory(string inputCategory){
    category = inputCategory;
}

//Returns category
string Category::getCategory(){
    return category;
}