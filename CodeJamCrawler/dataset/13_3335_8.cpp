

#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
//#include <iomanip>
#include <cstdlib>
#include <vector>



using namespace std;

int compare( const void * a , const void * b)
{
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
}

int solve(unsigned int ci){

		string s;
  	int n;

		string letters[2];
		bool  bvowel = true;
		letters[0] = "aeiou";
		letters[1] = "bcdfghjklmnpqrstvwxyz";

		
	   
		
	  vector<int> itokens ;
	  
		

// Need fast algorythnm.  1 < L <= 10e6 very large!

		cin >> s >> n ;
//		cout << s << n << endl;

// basically a triangular number minus the bottom 

// convert the string into a set of vowel/consonnents
	
	int offset1 = 0 , offset2 ;
	bool isvowel ;
	itokens.push_back (0);

	for (unsigned i = 0  ; i< s.size()  ; i++){
		isvowel = ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' );
		if (bvowel == isvowel) {
				itokens[itokens.size()-1 ] = itokens[itokens.size()-1 ] + 1;
		} else {
			bvowel = isvowel ;
			itokens.push_back (1);
		}
	}

//	for(unsigned int i = 0 ; i < itokens.size() ; i++) cout << itokens[i] << "," ;
//	cout << endl ;

// for a consonent node we have length before times length in node
// length in node and times length after
// length before times length after

// once we have done a consonent node, it needs to be excluded for proceeding nodes

	int startnode = 0 ;
	int currentnode = 1;
	int l1 = 0 ;
	int l2 = 0 ;
	int li1 = 0 , li2 = 0;
	int result = 0 ;
	int temp ;


	for (currentnode = 1 ; currentnode < itokens.size() ; currentnode += 2 ){ 
		// fwa check current node can have consonents
		for( ;currentnode < itokens.size() ; currentnode += 2 )
			if (itokens[currentnode] >= n ) break ;
		if (currentnode >= itokens.size() ) break;

		for ( ; li1 < currentnode ; li1++ )  l1 += itokens[li1] , l2 += itokens[li1]   ;

		temp = itokens[currentnode] - n +1;
		result += ( l1 ) * (temp) ;  // before & first
		result += ((temp +1 ) * ( temp )) / 2; // in the node
		result += ( s.size() - l2 - itokens[currentnode]   ) * (temp) ;  //node & after
		result += ( l1 ) * ( s.size() - l2 - itokens[currentnode]   ); // before and after
		
		l1 = n -1;
		li1 ++ ;
		l2 += itokens[currentnode] ;
	
	}
//	cout << endl ;

	cout << "Case #" << ci << ": " ;
	cout << result << endl ;

	 return 0;
}

int main(){
	int c;
	cin >> c;
	
	for (unsigned int ci = 1 ; ci <= c ; ++ci ){
		solve (ci);
	}
	return 0;
}



