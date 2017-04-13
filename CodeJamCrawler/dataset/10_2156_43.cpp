// 2010A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>



using namespace std;

// K Number of times 
int _tmain(int argc, _TCHAR* argv[])
{
	


	int T = 0 ; // Number of test cases
	int N = 0 ; // Number of snappers
	int K = 0 ; // Number of snaps by user
	int Kon = 0 ; // Number of snaps for on


// Snappers, first instance of on
// 1,1
// 2,3
// 3 on power no, off on , on on power, off 
// 4 47 

// Problem is similar to tower of hanoi, with extra 1 for cycling
// 1 3 7 15 31 = 2 ^ (n) -1 
// 
	cin >> T ;

	for ( int i = 1 ; i <= T ; i++ ){
		cin >> N ;
		cin >> K ;
		K++;
		Kon = (int)pow((double)2,N)  ;

		cout << "Case #" << i << ": " <<  (K % Kon == 0 ? "ON" : "OFF") << endl ;
	
	}

	return 0;
}

