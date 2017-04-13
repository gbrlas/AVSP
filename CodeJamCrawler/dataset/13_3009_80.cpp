#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define eps 1e-10
#define inf 0x3f3f3f3f

#define fr(x,y,z) for(int x = (y); x < (z); x++)

#define console cout
#define dbg(x) console << #x << " == " << x << endl
#define print(x) console << x << endl
#define PMASK(mask,tam) for(int i = tam - 1; i >= 0; i--) if(mask & (1<<i)) printf("1"); else printf("0"); printf("\n")
// BEGIN CUT HERE

char T[10][10];

void read(){
	for(int i = 0; i < 4; i++){
		scanf("%s",T[i]);
	}
}

void process(int c){

	bool temX = false;
	bool temO = false;
	bool temP = false;
	bool Xganhou = false;
	bool Oganhou = false;
	bool achouUmPonto = false;

	//linhas
	for(int i = 0; i < 4; i++){
		temX = false;
		temO = false;
		temP = false;
		
		for(int j = 0; j < 4; j++){
			temX |= (T[i][j] == 'X');
			temO |= (T[i][j] == 'O');
			temP |= (T[i][j] == '.');
		}
		
		Xganhou |= (!temO && !temP);
		Oganhou |= (!temX && !temP);
		achouUmPonto |= temP;
	}

	//colunas
	for(int j = 0; j < 4; j++){
		temX = false;
		temO = false;
		temP = false;
		
		for(int i = 0; i < 4; i++){
			temX |= (T[i][j] == 'X');
			temO |= (T[i][j] == 'O');
			temP |= (T[i][j] == '.');
		}
		
		Xganhou |= (!temO && !temP);
		Oganhou |= (!temX && !temP);
		achouUmPonto |= temP;
	}

	//1 - diagonal

	temX = false;
	temO = false;
	temP = false;
	
	for(int i = 0; i < 4; i++){
		temX |= (T[i][i] == 'X');
		temO |= (T[i][i] == 'O');
		temP |= (T[i][i] == '.');
	}
	
	Xganhou |= (!temO && !temP);
	Oganhou |= (!temX && !temP);
	achouUmPonto |= temP;

	//2 - diagonal

	temX = false;
	temO = false;
	temP = false;
	
	for(int i = 0; i < 4; i++){
		temX |= (T[i][3 - i] == 'X');
		temO |= (T[i][3 - i] == 'O');
		temP |= (T[i][3 - i] == '.');
	}
	
	Xganhou |= (!temO && !temP);
	Oganhou |= (!temX && !temP);
	achouUmPonto |= temP;

	if(Xganhou)
		printf("Case #%d: X won\n", c);
	else if(Oganhou)
		printf("Case #%d: O won\n", c);
	else if (achouUmPonto)
		printf("Case #%d: Game has not completed\n", c);
	else{
		printf("Case #%d: Draw\n", c);
	}

}

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("saida.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
		read();
		process(i+1);
	}

    return 0;
}
// END CUT HERE S
