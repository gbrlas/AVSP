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

int b[4][4];

bool diag1(char c){
	forn(i,4){
		if (b[i][i]!=c && b[i][i]!='T') return false;
	}
	return true;
}

bool diag2(char c){
	forn(i,4){
		if (b[i][3-i]!=c && b[i][3-i]!='T') return false;
	}
	return true;
}

bool diag4(char c){
	return (diag1(c) || diag2(c));	
}

bool row(int i, char c){
	forn(j,4){
		if(b[i][j]!=c && b[i][j]!='T') return false;
	}
	return true;
}

bool col(int j, char c){
	forn(i,4){
		if(b[i][j]!=c && b[i][j]!='T') return false;	
	}
	return true;
}

bool row4(char c){	
	forn(i,4) {
		if(row(i,c)) return true;
	}
	return false;
}

bool col4(char c){	
	forn(i,4) {
		if(col(i,c)) return true;
	}
	return false;
}

bool gano(char c){
	return (row4(c) || col4(c) || diag4(c));
}

bool hayPunto(){
	forn(i,4) forn(j,4){
		if(b[i][j]=='.') return true;
	}
	return false;
}

int main() {		
	int T;	
	cin >> T;
	char e; int n=0;
	while(n++ < T) {		
		forn(i,4) forn(j,4){						
			cin >> e;
			
			b[i][j]=e;
		}		
		
		if(gano('X')){
			cout << "Case #" << n << ": X won" << endl; continue;
		}
		if(gano('O')){
			cout << "Case #" << n << ": O won" << endl; continue;
		}
		if(hayPunto()){
			cout << "Case #" << n << ": Game has not completed" << endl; continue;
		}
		cout << "Case #" << n << ": Draw" << endl; continue;
		
		
	}

	return 0;
}