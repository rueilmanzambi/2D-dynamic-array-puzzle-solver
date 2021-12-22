// Programmer: Rueil Manzambi                Section: 109
// Data: May 3, 2021
// File: implementationFile.cpp
// Purpose: implementation file for header.h for homework 8. It contains the functions definitions
//          for the program

#include <iostream>
#include "header.h"

using namespace std;

// Description: Constructor for class skware. 
// Pre: It's only called with one argument
// Post: It uses the size of make a 2d-array of (size * size)
skware::skware(int size)
{
  m_size = size;
  m_ptr_board = new int * [size];

  for (int i = 0; i < size; i++)
    m_ptr_board[i] = new int [size];

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
      m_ptr_board[i][j] = rand() % (MAX_INPUT) + MIN_INPUT;
  }
}

// Description: Copy constructor for class skware
// Pre: None
// Post: copies the attributes of argument to the calling object
skware::skware(const skware & source)
{
  m_size = source.m_size;
  m_ptr_board = new int * [m_size];
  
  for (int i = 0; i < m_size; i++)
  {
    m_ptr_board[i] = new int[m_size];
    for (int j = 0; j < m_size; j++)
      m_ptr_board[i][j] = source.m_ptr_board[i][j];
  }
}

// Description: Destructor for class skware
// Pre: None
// Post: sends back dynamic memory to the free store
skware::~skware()
{
  for (int i = 0; i < m_size; i++)
  {
    delete [] m_ptr_board[i];
  }
  delete [] m_ptr_board;
}

// Description: copy assignment operator for class skware
// Pre: None
// Post: deletes what the calling object had and copies 
//       the attributes of the argument to the calling object and returns it
skware & skware:: operator = (const skware & source)
{
  m_size = source.m_size;
  
  for (int i = 0; i < m_size; i++)
    delete [] m_ptr_board[i];
  delete [] m_ptr_board;

  for (int i = 0; i < m_size; i++)
  {
    m_ptr_board[i] = new int[m_size];
    for (int j = 0; j < m_size; j++)
      m_ptr_board[i][j] = source.m_ptr_board[i][j];
  }
  return *this;
}

// Description: displays the puzzle with 5 empty places and replaces their values to -1
// Pre: the calling object and the argument have the same values
// Post: displays the puzzle with 5 empty places and replaces their values to -1 
//       for the calling object
void skware::display_puzzle(const skware & object)
{
  int is_replaced = 0;
  int rand_num_col;
  int row_sum_soln = 0;
  int col_sum_soln = 0;

  
  cout << endl;
  for (int i = 0; i < (m_size*FORMAT_OUTPUT_FOUR)+FORMAT_OUTPUT_ONE; i++)
    cout << "-";
  cout << endl;

  for (int i = 0; i < m_size; i++)
  {
    rand_num_col = rand() % m_size;
    cout << "| ";
    for (int j = 0; j < m_size; j++)
    {
      row_sum_soln += object.m_ptr_board[i][j];
      if (is_replaced < NUM_HIDDEN_VALUE)
      {
        if (j == rand_num_col)
        { 
          is_replaced++;
          cout << "  | ";
          m_ptr_board[i][j] = VALUE_FOR_REPLACE;
        }
        else
          cout << m_ptr_board[i][j] << " | ";
      }
      else
        cout << m_ptr_board[i][j] << " | ";
    }
    cout << " " << row_sum_soln << endl;
    row_sum_soln = 0;
    for (int k = 0; k < (m_size*FORMAT_OUTPUT_FOUR)+FORMAT_OUTPUT_ONE;k++)
      cout << "-";
    cout << endl;
  }
  for (int k = 0; k < m_size; k++)
  {
    for (int l = 0; l < m_size; l++)
      col_sum_soln += object.m_ptr_board[l][k];
    cout << " " << col_sum_soln << " ";
    col_sum_soln = 0;
  }
  cout << endl << endl;


  return;
}

// Description: finds the correct values for the missing spots
// Pre: The spots to replace must have the value -1
// Post: finds the correct values for the missing spots and prints
//       the correct puzzle
void skware::solve(skware & object, skware & temp)
{
  bool found = false;
  int num_found = 0;
  int col_sum_soln = 0;
  int row_sum_soln = 0;  


  for (int i = 1; ((i < (MAX_INPUT + MIN_INPUT))&&(!found)); i++)
  {
    for (int j = 1; ((j < (MAX_INPUT + MIN_INPUT))&&(!found)); j++)
    {
      for (int k = 1; ((k < (MAX_INPUT + MIN_INPUT))&&(!found)); k++)
      {
        for (int l = 1; ((l < (MAX_INPUT + MIN_INPUT))&&(!found)); l++)
        {
          for (int m = 1; ((m < (MAX_INPUT + MIN_INPUT))&&(!found)); m++)
          {
            num_found = NOTHING_FOUND;
            for (int o = 0; ((o < m_size) && !found); o++)
            {
              for (int p = 0; ((p < m_size) && !found); p++)
              {
                if (temp.m_ptr_board[o][p] == VALUE_FOR_REPLACE && num_found == NOTHING_FOUND)
                {
                  m_ptr_board[o][p] = i;
                  num_found++;
                }
                else if (temp.m_ptr_board[o][p] == VALUE_FOR_REPLACE && num_found == FIRST_FOUND)
                {
                  m_ptr_board[o][p] = j;
                  num_found++;
                }
                else if (temp.m_ptr_board[o][p] == VALUE_FOR_REPLACE && num_found == SECOND_FOUND)
                {
                  m_ptr_board[o][p] = k;
                  num_found++;
                }
                else if (temp.m_ptr_board[o][p] == VALUE_FOR_REPLACE && num_found == THIRD_FOUND)
                {
                  m_ptr_board[o][p] = l;
                  num_found++;
                }
                else if (temp.m_ptr_board[o][p] == VALUE_FOR_REPLACE && num_found == FOURTH_FOUND)
                {
                  m_ptr_board[o][p] = m;
                  num_found++;
                }
              }
            }
            if (num_found == NUM_HIDDEN_VALUE)
            {
              if (*this == object)
                found = true;
            }
          }
        }
      }
    }
  }
  // printing the puzzle
  cout << endl;
  for (int i = 0; i < (m_size*FORMAT_OUTPUT_FOUR)+FORMAT_OUTPUT_ONE; i++)
    cout << "-";
  cout << endl;
  
  for (int i = 0; i < m_size; i++)
  {
    cout << "| ";
    for (int j = 0; j < m_size; j++)
    {
      row_sum_soln += m_ptr_board[i][j];
      cout << m_ptr_board[i][j] << " | ";
    }
    cout << " " << row_sum_soln << endl;
    row_sum_soln = 0;
    for (int k = 0; k < (m_size*FORMAT_OUTPUT_FOUR)+FORMAT_OUTPUT_ONE;k++)
      cout << "-";
    cout << endl;
  }
  for (int k = 0; k < m_size; k++)
  {
    for (int l = 0; l < m_size; l++)
      col_sum_soln += m_ptr_board[l][k];
    cout << " " << col_sum_soln << " ";
    col_sum_soln = 0;
  }
  cout << endl << endl;

  return;
}


// Description: == operator for object of type skware
// Pre: calling object should be of type skware
// Post: compares if the calling object is equal to the arguement
//       returns false if they're not, returns true otherwise
bool skware::operator == (const skware & object)
{
  bool answer = true;
  int row_sum_source = 0;
  int row_sum_soln = 0;
  int col_sum_source = 0;
  int col_sum_soln = 0;


  if (m_size != object.m_size)
    answer = false;
  else
  {
    for (int i = 0; i < m_size; i++)
    {
      for (int j = 0; j < m_size; j++)
      {
        row_sum_source += m_ptr_board[i][j];
        row_sum_soln += object.m_ptr_board[i][j];
        col_sum_source +=  m_ptr_board[j][i];
        col_sum_soln += object.m_ptr_board[j][i];
      }
      if ((row_sum_source != row_sum_soln) || (col_sum_source != col_sum_soln))
        answer = false;
      row_sum_source = 0;
      row_sum_soln = 0;
      col_sum_source = 0;
      col_sum_soln = 0;
    }
  }
  return answer;
}

// Description: starts the game. It creates the skware with size and call other 
//              functions to print and solve the game
// Pre: None
// Post: It calls other functions to display and solve the puzzle
void start_game(const int size)
{
  char user_answer; 
  
  skware my_skware(size);
  skware soln(my_skware);

  cout << "Here's your puzzle...solve it you can! There can be multiple solutions." << endl;
  my_skware.display_puzzle(soln);
  skware temp_puzzle(my_skware);
  
  do
  {
    cout << "Do you want a solution ? ";
    cin >> user_answer;
  } while (user_answer != 'y' && user_answer != 'Y');

  my_skware.solve(soln, temp_puzzle);

  return;
}
