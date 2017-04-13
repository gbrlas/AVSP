#include <iostream>
#include <string>
#include <cmath>

#include <iomanip>
#include <locale>
#include <sstream>

using namespace std;

bool isPalindrome(string st);

bool isPalindrome(string st)
{
	if ( st.size() == 1 )
		return true;
		
	for ( int i=0; i < st.size()/2; ++i ) {
		if ( st[i] != st[st.size() - 1 - i] )
			return false;
		if ( i == st.size()/2 - 1 )
			return true;
	}
}

int main()
{
	int testcases;
	cin >> testcases;
	
	for ( int k=1; k <= testcases; ++k ) {
		unsigned long long int  A, B;
		unsigned long long int lowerLimit, upperLimit;
		
		cin >> A;
		long double temp = sqrt(A);
		lowerLimit = ( temp - (long long int)(temp) )? (long long int)temp + 1: temp;
		
		cin >> B;
		upperLimit = (long long int)sqrt(B);
		
		long long int count = 0;
		for ( long long int i = lowerLimit; i <= upperLimit; ++i ) {
			string num = static_cast<ostringstream*>( &(ostringstream() << i) )->str();
			string numSquare = static_cast<ostringstream*>( &(ostringstream() << pow(i, 2)) )->str();
			
			if ( isPalindrome(num) )
				if ( isPalindrome(numSquare) )
					count++;
		}
		cout << "Case #" << k << ": " << count << endl;
	}
	return 0;
}