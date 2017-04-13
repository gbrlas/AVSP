// 2010C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{


	int T = 0 ;
	long R = 0 ;
	long k = 0 ;
	long N = 0 ;

	long* groups = 0 ;
	long g ;
	long passengers ;
	long total ;
	long gmax ;

	cin >> T ;

	for ( int i = 1 ; i <= T ; i++ ){
		
		cin >> R;
		cin >> k;
		cin >> N;

		groups = new long[N];

		for ( int j = 0 ; j < N ; j++) {
			cin >> groups[j] ;
		}

		g = 0;
		total = 0;

		for ( int j = 0 ; j < R ; j++){
			
			passengers = 0;

			for ( gmax = 0; gmax < N ; gmax++,  g++  ){

				if ( passengers + groups[ g % N ] > k) 
					{ break; }
	
				passengers += groups[ g % N ] ;
			}

			total += passengers ;
		}

		cout << "Case #" << i << ": " << total << endl;

	}

	


	return 0;
}

