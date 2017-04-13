
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

//#include <boost/multiprecision/cpp_int.hpp> 
using namespace std;



int main(){

	int c ;
//	char imin[128] ,imax[128] ;
	unsigned long long imin , imax ;

	unsigned long long rootmin , rootmax ;

	char root[64];
	char sq[128];

	string srootmin , srootmax , sroot ;

//	string sroot;

	bool beven;
	int rootmid ;

	cin >> c;

// generate pallendromes for a range
// we only need to know the numbers in a range from the square root
// too many to hold in ram, but arnt that many palindromes
// build a list for the entire range?

// since a palindrome is the same each way, we can generate the palendrome 
// by using 'half' a string then copying the digits.  So the max of 1E100
// srt to 1E50 to string 1E25.  Even & odd need doing seperately!

	int result ;
	int db_solcount ;

	for (int ci = 1 ; ci <= c ; ci++ ){
		result = 0;
		db_solcount = 0;

		cin >> imin >> imax ;
		//cout << y << " " << x << endl;
		rootmin = sqrt(imin);
		if (rootmin * rootmin < imin) rootmin++;

		rootmax = sqrt(imax);

		srootmin = static_cast<ostringstream*>( &(ostringstream() << rootmin ) )->str();
		srootmax = static_cast<ostringstream*>( &(ostringstream() << rootmax ) )->str();

		sroot = srootmin ;
			

// Iterate the pallendromes - start by generating them!
		int rootlength = sroot.length();
//		cout << "rootmin " << srootmin << " rootmax " << srootmax << endl ;
		beven =  rootlength % 2 == 0 ;
		rootmid = int(rootlength / 2) - (beven?1:0);

// check the starting value for a posible first paldm
// the root min is likely not a pallendrome but to convert it to one, we may create
// a value below the current root min
// this block sets up the min as a pallendrome and sets the value one lower than
// the iteration block (like a minus 1).  The iteration block always starts by adding one

		int icharpos ;
		bool bIgnore = false; // replicating the digits may result in a pallandrome
			// lower than the root.  

		for (int icharpos = 0 ; icharpos <= rootmid ; icharpos++){
			if (sroot[icharpos] < sroot[rootlength - 1 - icharpos]) bIgnore = true;
			sroot[rootlength - 1 - icharpos] = sroot[icharpos];
		}

		if (!bIgnore){
			sroot[rootlength - 1 - rootmid] = --sroot[rootmid];
		}

// Iterate all the pallandromes 
			
		for (;;){
		
// calulate the next pallandrome.  Irerate the digits for carry

			for ( icharpos = rootmid ; icharpos >=0 ; icharpos--){
				if(sroot[icharpos] == '9' ){
					sroot[icharpos] = '0';
					sroot[rootlength - 1 - icharpos ] = sroot[icharpos] ;
				} else {
					sroot[icharpos]++;
					sroot[rootlength - 1 - icharpos ] = sroot[icharpos] ;
					break;
				}
				
// if the carry results in a longer number
				if (icharpos == 0 ){
					if(beven) rootmid++;
					rootlength++;
					beven = !beven ;
					sroot[0] = '1' ; 
					sroot = sroot + '1' ;
				}
			}

// Check if above root max
			if ( sroot.length() > srootmax.length()) break;					
			if ( sroot.length() == srootmax.length()) {
				for( icharpos = 0 ; icharpos < rootlength ; icharpos++ )
					if ((sroot[icharpos]) != (srootmax[icharpos]) ) 
						 break;
				if (sroot[icharpos] > srootmax[icharpos]) break;
			}

// not really the way I want to convert it.
// check the sqaure is pall
			db_solcount ++ ;

			std:stringstream ss;
			ss << sroot;
			unsigned long long ull_idf , sq ;
			ss >> ull_idf;

			// more complex check
			sq = ull_idf * ull_idf ;
			string pall = static_cast<ostringstream*>( &(ostringstream() << sq ) )->str();

			result++;			
			for( icharpos = 0 ; icharpos < pall.length()/2 ; icharpos++ )
                                if ((pall[icharpos]) != (pall[pall.length() - 1 - icharpos] ) ){
					result--;
	                                break;
				}

			
//			cout << "Check value " <<sroot << " -> " <<  sq  << ", " << pall << "res count " << result << endl ;
		}

		cout << "Case #" << ci << ": " ;
		cout << result << endl ;
	}

	return 0;
}


