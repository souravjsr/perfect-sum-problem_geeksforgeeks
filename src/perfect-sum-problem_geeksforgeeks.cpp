//============================================================================
// Name        : perfect-sum-problem_geeksforgeeks.cpp
// Author      : Sourav Mukherjee
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : "http://practice.geeksforgeeks.org/problems/perfect-sum-problem/0"
//                        in C++, Ansi-style.
// Reference   : "https://www.youtube.com/watch?v=zKwwjAkaXLI"
//                        Logic of Dynamic program need to be implemented.
// In-progress.
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int num_of_user_input = 0, sum = 0, row = 0, col = 0;
int* arr_user_input = new int[row];
int** multDimension_arr = new int*[row];

void
get_user_input()
{
  cout << "--------------------------" << endl;
  for (int i = 0; i < num_of_user_input; i++)
    {
      cout << "The " << i << " value: \t";
      cout << arr_user_input[i] << endl;
    }
}

void
set_user_input()
{
  cout << "--------------------------" << endl;
  for (int i = 0; i < num_of_user_input; i++)
    {
      cin >> arr_user_input[i];
    }
}

void
get_multi_dimension_array()
{
  cout << "--------------------------" << endl;
  for (int r = 0; r < row; r++)
    {
      for (int c = 0; c < col + 1; c++)
        {
          cout << multDimension_arr[r][c] << "\t";
        }
      cout << endl;
    }
}

void
set_multi_dimension_array()
{
  cout << "--------------------------" << endl;
  for (int r = 0; r < row; r++)
    {
      multDimension_arr[r] = new int[col + 1];
    }
  for (int r = 0; r < row; r++)
    {
      for (int c = 0; c < col + 1; c++)
        {
          if ((r == 0) && (c > 0))
            {
              multDimension_arr[r][c] = c - 1;
            }
          else if ((r > 0) && (c == 0))
            {
              cout << r << "==" << arr_user_input[4] << endl;
              multDimension_arr[r][c] = arr_user_input[r-1];
              //cin >> multDimension_arr[r][c] ;
            }
          else
            {
              multDimension_arr[r][c] = 888;
            }
          multDimension_arr[0][0] = 999;
        }
    }
}

int
main(int argc, char* argv[])
{
  cout << " Enter the number of element --> \t";
  cin >> num_of_user_input;
  cout << " Enter the sum --> \t";
  cin >> sum;
  col = sum + 1; //8
  row = num_of_user_input + 1;
  set_user_input();
  get_user_input(); //This is for my debug purpose.
  set_multi_dimension_array();
  get_multi_dimension_array();
  for (int r = 0; r < num_of_user_input; r++)
    {
     delete[] multDimension_arr[r];
    }
  delete[] multDimension_arr;
  delete[] arr_user_input;
}
