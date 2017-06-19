//============================================================================
// Name        : perfect-sum-problem_geeksforgeeks.cpp
// Author      : Sourav Mukherjee
// Version     : 0.2
// Copyright   : Your copyright notice
// Description : "http://practice.geeksforgeeks.org/problems/perfect-sum-problem/0" in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
        long T = 0,n = 0, sum = 0, i = 0, j = 0;
        long *a = (long*) malloc(n*sizeof(long));
        long *b = (long*) malloc(n*sizeof(long));
	cin >> T >> n >> sum;
	for(i =0;i <= T; i++){
	    for(j =0 ;j < n ;j++){
	        cout << "Enter "<< j ;
	        cin >> a[j];
	    }
	    for(j =0 ;j < n ;j++){
                cout << a[j];
            }
	}

	return 0;
}
