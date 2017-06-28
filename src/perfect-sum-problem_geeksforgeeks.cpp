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

/*
* Sample O/P:
*  Enter the number of element -->      5
*  Enter the sum -->      11
*  --------------------------
*  2
*  3
*  7
*  8
*  10
*  --------------------------
*  --------------------------
*  999     0       1       2       3       4       5       6       7       8       9       10      11
*  2       1       0       1       0       0       0       0       0       0       0       0       0
*  3       1       0       1       1       0       1       0       0       0       0       0       0
*  7       1       0       1       1       0       1       0       1       0       1       1       0
*  8       1       0       1       1       0       1       0       1       1       1       1       1
*  10      1       1       1       1       1       1       0       1       1       1       1       1
*  Total number of subsets present: --> 2
*/
#include <iostream>
#include <string>
using namespace std;

int num_of_user_input, sum, row, col;
int* arr_user_input;
int** multDimension_arr;

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

int
check_value(int cur_row, int cur_col)
{
  if (cur_row == 1)
    {
      if (multDimension_arr[cur_row][0] == multDimension_arr[0][cur_col])
        {
          return 1;
        }
    }
  else
    {
      if (multDimension_arr[cur_row][0] == multDimension_arr[0][cur_col])
        {
          return 1;
        }
      else
        {
          if (multDimension_arr[cur_row - 1][cur_col] == 1)
            {
              return 1;
            }
          else if (multDimension_arr[cur_row - 1][cur_col
              - (multDimension_arr[cur_row][0])] == 1)
            {
              return 1;
            }
        }

    }
  return 0;
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
              multDimension_arr[r][c] = arr_user_input[r - 1];
            }
          else if ((c == 1) && (r != 0))
            {
              multDimension_arr[r][c] = 1;
            }
          else
            {
              if (check_value(r, c) == 1)
                {
                  multDimension_arr[r][c] = 1;
                }
              else
                {
                  multDimension_arr[r][c] = 0;
                }
            }
          multDimension_arr[0][0] = 999;
        }
    }
}

int
subset_checker()
{
  cout << "--> ";
  int counter = 0;
  for (int it = 1; it < row; it++)
    {
      (multDimension_arr[it][sum + 1] == 1) ? counter++ : 0;
    }
  return counter;
}

int
main(int argc, char* argv[])
{
  num_of_user_input = 0;
  sum = 0;
  row = 0;
  col = 0;
  cout << " Enter the number of element --> \t";
  cin >> num_of_user_input;
  cout << " Enter the sum --> \t";
  cin >> sum;
  col = sum + 1;
  row = num_of_user_input + 1;
  arr_user_input = new int[row];
  multDimension_arr = new int*[row];
  set_user_input();
  //get_user_input(); //This is for my debug purpose.
  set_multi_dimension_array();
  get_multi_dimension_array();
  cout << "Total number of subsets present: " << subset_checker();
  for (int r = 0; r < num_of_user_input; r++)
    {
      delete[] multDimension_arr[r];
    }
  delete[] multDimension_arr;
  delete[] arr_user_input;
}
