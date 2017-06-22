//============================================================================
// Name        : perfect-sum-problem_geeksforgeeks.cpp
// Author      : Sourav Mukherjee
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : "http://practice.geeksforgeeks.org/problems/perfect-sum-problem/0"
//                        in C++, Ansi-style
// Reference   : "https://www.youtube.com/watch?v=zKwwjAkaXLI"
//                        Logic of Dynamic program need to be implemented.
// In-progress.
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int findCount(int T, int sum, long *a)
{
  int counter = 0;
  for (int it = 0; it < T; it++)
    {

      long localSum = 0;
      for (int jt = it; jt < T; jt++)
        {
          localSum = localSum + a[jt];
          if (localSum == sum)
            {
              counter++;
              break;
            }
        }

    }
  return(counter);
}

int main(){
    long T = 0, sum = 0,it = 0;
    //long *b = (long*) malloc(T*sizeof(long));
    long* a = (long*) malloc(T*sizeof(long));
    cout << "Enter the array length--> ";
    cin >> T;
    cout << "Enter the sum to be checked--> ";
    cin >> sum;
    for (it = 0; it < T; it++)
      {
        long val;
        cout << "  Enter the value "<< it <<" in the array \n      ";
        cin >> val;
        a[it] = val;
        //cout << a[it] << "\n" ;
      }
    int ret = findCount(T,sum, a);
    cout << "Count of all the subset--> "<< ret << endl;
    cout << "\n Ending the program \n";
    return 0;
  }

/*
 cin >> n >> sum;
 for(i =0;i <= T; i++){
 for(j =0 ;j < n ;j++){
 cout << "Enter "<< j ;
 cin >> a[j];
 }
 for(j =0 ;j < n ;j++){
 b[j] = sum - a[j];
 cout << b[j] << "**";
 }
 cout  << endl;
 }*/
