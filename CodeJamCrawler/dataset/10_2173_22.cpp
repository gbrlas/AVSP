// 2010C1A.cpp : Defines the entry point for the console application.
//

#include <StdAfx.h>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
	
{


	int T ;

	cin >> T ;

	for ( int iT = 1 ; iT <= T ; iT ++ ){
		int W;
		cin >> W ;

		long *B1 = 0 ;
		long *B2 = 0 ;
		long interscetions =0;

		B1 = new long[W];
		B2 = new long[W];
		

		

		for (int iW = 0 ; iW < W ; iW ++ ){
			cin >> B1[iW] >> B2[iW];
			

			for (int intersect = 0 ; intersect < iW ; intersect++ ){
				if (( B1[iW] > B1[intersect])  ^  (B2[iW] > B2[intersect] ))
					interscetions ++ ;
			}
		
			
		}
		cout << "Case #" << iT << ": " << interscetions << endl;
	}

	return 0;
}

