// Programmer: Rueil Manzambi                Section: 109
// Data: May 3, 2021
// File: main.cpp
// Purpose: main file for homework 8. It contains a program that uses dynamic memory
//          to create a 2d array puzzle. It deletes some values of the puzzle, then
//          starts solving it until the correct values are found. 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"

using namespace std;

int main()
{
  int size;
  char player_answer;
  bool want_to_play;
  srand(time(0));
  
  cout << "\n\t\t\tWelcome to the magic skware" << endl;
  cout << "\t\t\t---------------------------\n" << endl;

  do
  {
    do 
    {
      cout << "Would you like to play ?(y/n): ";
      cin >> player_answer;
    } while (player_answer != 'y' && player_answer != 'Y' && player_answer != 'n' && player_answer != 'N');  
    
    if (player_answer == 'y' || player_answer == 'Y')
    {
      do
      {
        cout << "Please, enter the size of the skware [6,10], inclusive: "; 
        cin >> size;
        if (size < MIN_SIZE_GRID || size > MAX_SIZE_GRID)
          cout << "Please, enter a valid size..." << endl;
      } while (size < MIN_SIZE_GRID || size > MAX_SIZE_GRID);
      
      start_game(size);
    }
    else
      want_to_play = false;   

  } while (want_to_play);


  
  cout << "\nThanks for using our magic skware.....bye!\n" << endl;

  return 0;
}
