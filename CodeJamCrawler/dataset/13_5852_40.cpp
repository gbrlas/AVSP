#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
 
#define forn(i,n) 	 for(int i=0; i<(int)n; i++)
#define fornd(i,n) 	 for(int i=n-1; i>=0; i--)
#define fornx(i,x,n) 	 for(int i=x; i<(int)n; i++)

//#define MOD 1000000007LL

using namespace std;
 
typedef vector<int>  vint;

bool isPalindrome(int i){	
	vint digits; int l=0;
	while(i>0){
		int r=i%10;
		digits.push_back(r); l++;
		i-=r; i/=10;
	}		
	forn(i,l/2){
		if(digits[i] != digits[l-i-1]) return false;
	}	
	return true;
}

int main() {		
	int T,A,B;	
	cin >> T;
	int N=0;
	while(N++ < T) {
		int COUNT=0;
		cin >> A >> B;
		fornx(i,A,B+1){
			int a=sqrt(i);
			if(a*a < i) continue;
			if(isPalindrome(sqrt(i)) && isPalindrome(i)) COUNT++;			
		}
		
		cout << "Case #" << N << ": " << COUNT << endl;
	}

	return 0;
}