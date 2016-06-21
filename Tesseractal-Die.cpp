//
//  main.cpp
//  DiceLearningProject
//
//  Created by Tristan on 11/24/15.
//  Copyright © 2015 Tristan. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <sstream>

typedef struct
{
    //char cells[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};  //currently handing out whatever value it feels like from the ASCII code.  Works fine with integers.
    int cells[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int cellFaces[6] = {2, 3, 4, 5, 6, 7};
    
}tesseractCells;

int rollFaces ();

void rollCells (char &cellsResultChar, int &cellsResult);

bool rollAgain(std::string &optionSelect, bool &exit, char &cellsResultChar, int &cellsResult);

void menu (std::string &optionSelect, bool &exit);

char numToChar(char &cellsResultChar, int &cellsResult);

int main()
{
    std::string optionSelect;
    bool exit = false;
    int cellsResult;
    char cellsResultChar;
//    int cellsResult = 0;
//    int cellFaceResult = 0;
    
    srand(time(NULL));  //Prevents rand() from producing the same series of numbers for each range given.
    
    do
    {
//        std::cout << exit;
        exit = false;
        
        menu(optionSelect, exit);
        
        if (optionSelect == "faces" || optionSelect == "f")
        {
            exit = false;
            
            rollFaces();
            rollAgain(optionSelect, exit, cellsResultChar, cellsResult);
        }
        if (optionSelect == "cells" || optionSelect == "c")
        {
            exit = false;
            
            rollCells(cellsResultChar, cellsResult);//cellsResult, cellFaceResult);
            rollAgain(optionSelect, exit, cellsResultChar, cellsResult);

        }
        if (optionSelect == "quit" || optionSelect == "q")
        {
            exit = true;
        }
        else
        {
            std::cout << "¡Error! Please select a valid menu option:" << std::endl;
        }
    }
    while (exit == false);
    
    if (exit == true)
    {
//        std::cout << exit;
        std::cout << "Goodbye." << std::endl;
        return 1;
    }


    return 0;
}

void menu (std::string &optionSelect, bool &exit)
{
    
//    std::cout << "Exit is: " << exit;
    exit = false;
//    std::cout << exit;
    std::cout << "Roll standard faces?" << std::endl;
    std::cout << "Roll cell faces?" << std::endl;
    std::cout << "Quit?" << std::endl;
    
    getline (std::cin, optionSelect);

    
    return;
}

int rollFaces()//For now, facesResult is declared within this function.
{
    int facesResult;
    
    int faces[24] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    
    facesResult = rand() % faces[23];
    
    while (facesResult == 0)
    {
        facesResult = rand() % faces[23];
    }
    
    std::cout << "Your roll is: " << facesResult << std::endl;
    
    return 0;
}

void rollCells(char &cellsResultChar, int &cellsResult)
{
//    char cellsResult;
    int cellFaceResult;
    
//    int cells[8] = {1, 2, 3, 4, 5, 6, 7, 8};
//    int cellFaces [6] = {1, 2, 3, 4, 5, 6};
    tesseractCells roll;
    
    //std::cout << roll.cells[3] << std::endl;

    cellsResult = rand() % roll.cells [7];
    cellFaceResult = rand() % roll.cellFaces [5];
    
    while (cellsResult == 0)
    {
        cellsResult = rand() % roll.cells [7];
    }
    while (cellFaceResult == 0)
    {
        cellFaceResult = rand() % roll.cellFaces [5];
    }
    
    numToChar(cellsResultChar, cellsResult);

    std::cout << "Your roll is: " << cellFaceResult << "(" << cellsResultChar << ")" << std::endl;
    
    return;
}

bool rollAgain(std::string &optionSelect, bool &exit, char &cellsResultChar, int &cellsResult)
//This function prompts the user for input and returns it.  Roll again?
{
    
    std::cout << "Would you like to roll again?" << std::endl;
    
    menu(optionSelect, exit);
    
//    if (optionSelect  == "yes" || optionSelect == "y")
//    {
//        exit = false;
//        
//        std::cout << "Okay." << std::endl;
//        
//    }
    if (optionSelect == "faces" || optionSelect == "f")
    {
        exit = false;
        
        rollFaces();
        rollAgain(optionSelect, exit, cellsResultChar, cellsResult);
    }
    if (optionSelect == "cells" || optionSelect == "c")
    {
        exit = false;
        
        rollCells(cellsResultChar, cellsResult);//cellsResult, cellFaceResult);
        rollAgain(optionSelect, exit, cellsResultChar, cellsResult);
        
    }
    if (optionSelect == "no" || optionSelect == "n")
    {
        exit = true;
        
        std::cout << "Alright." << std::endl;
        return exit == true;
    }
//    else
//    {
//        std::cout << "Please answer yes or no." << std::endl;
////        exit = false;
//    }
    
    return exit;
}

char numToChar(char &cellsResultChar, int &cellsResult) //This function turns a random number generator into a random letter generator.
{

    char cellsCode[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    
    for (int i = 0; i < 8; i++)
    {
        if (cellsResult == i)
        {
            cellsResultChar = cellsCode[i];
        }
    }
    
    return cellsResultChar;
}


/***Development Notes***:
 /-*Later (higher cell count dice), should maybe have repeat numbers, or letter/number combinations that are meaningful in some way, to prevent absurd rolls?
 /-->On higher complexity dice, the repeated numbers on the (standard face roll for example) 
 /-->should have a letter associated with them, such as "Your roll is: 3(a)".
 /-*The 24-Cell should definitely be used as one of the polychorons.  It's composed of octahedral cells!
 /-*The 120-Cell should also be used.  It's bigger and more complex (still composed of dodecahedrons),
 /--> but it has a 3 dimensional analogue, unlike the 24-Cell.
 /-*The Penteract is the obvious first choice for a five dimensional die.  It will be a new challenge, since
 /-->incorporating the 4-faces will be a whole new layer of complexity.
 /---->To this end, use structs and/or multi-dimensional arrays.
 /-*When rolling for cells using higher (than four) dimensional dice, those cells may used differently depending
 /-->on their dimensional depth.
 /-BEFORE the 5-cube can be executed, it must be decided what it MEANS to roll the entire 4-face, and
 /-->implement that in the tesseract.
 /---->Is it roll standard faces, and roll cells, then store the results in an array 
 /---->and randomly select between them?  Should it include a function where every possibility
 /---->has its own number?
 /
 / ***ERROR REPORTS***:
 /-*Integers in arrays reduced by 1.  Cell faces displaying 0-5, and standard faces displaying 0-23.
 /-->What is going on?
 /-*The program stops accepting input after a reasonable, but altogether less than ideal number of
 /-->rolls.  Adequate for testing, but will need to be fixed eventually.
*/