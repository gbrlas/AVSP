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

int main() {		
	int T; long long int t,r;	
	cin >> T;
	int n=0;
	while(n++ < T) {		
		cin >> r >> t;		
		long long int count=0;
		long long int p=(2*r) + 1;				
		while(t-p >= 0){			
			count++;
			t-=p;
			r+=2;
			p=(2*r) + 1;			
		}
		cout << "Case #" << n << ": " << count << endl;
	}

	return 0;
}