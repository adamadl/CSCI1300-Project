// CSCI1300 Fall 2021
// Authors: Adam Adl and Sena Uctuk
// Recitation: 216 - Pragna Mandadi
// Project 3: Jeopardy 

#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>

using namespace std;
class Category{
    public:
    //Default Constructor
        Category();

    //Setter
        void setCategory(string inputCategory);

    //Getter
        string getCategory();
    
    //Data Members
    private:
        string category;
};
#endif