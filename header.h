// Programmer: Rueil Manzambi                Section: 109
// Data: May 3, 2021
// File: header.h
// Purpose: header file for main file for homework 8. It contains the class definition 
//          and functions prototypes for the program

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN_SIZE_GRID = 6;
const int MAX_SIZE_GRID = 10;
const int MIN_INPUT = 1;
const int MAX_INPUT = 7;
const int NUM_HIDDEN_VALUE = 5;
const int FOR_TRUE = 1;
const int FOR_FALSE = 0;
const int PROBABILITY_TRUE_FALSE = 2;
const int VALUE_FOR_REPLACE = -1;
const int FORMAT_OUTPUT_ONE = 1;
const int FORMAT_OUTPUT_FOUR = 4;
const int NOTHING_FOUND = 0;
const int FIRST_FOUND = 1;
const int SECOND_FOUND = 2;
const int THIRD_FOUND = 3;
const int FOURTH_FOUND = 4;
const int FIFTH_FOUND = 5;


class skware
{
  private:
    int m_size;
    int ** m_ptr_board;

  public:
    skware(int size);
    skware(const skware & source);
    ~skware();
    skware & operator = (const skware & source);
    void display_puzzle(const skware & object);
    void solve(skware & object, skware & temp);
    bool operator == (const skware & object);
};

void start_game(const int size);


#endif
