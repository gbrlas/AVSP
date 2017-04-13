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

int n,m;
int A[111][111];

void read(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &A[i][j]);
		}
	}
}

void process(int c){
	bool possible = true;

	int maxInRow[111];
	int maxInCol[111];

	for(int i = 0; i < n; i++){
		maxInRow[i] = 0;
		for(int j = 0; j < m; j++){
			maxInRow[i] = ( maxInRow[i] < A[i][j] ) ? A[i][j] : maxInRow[i];
		}
	}

	for(int j = 0; j < m; j++){
		maxInCol[j] = 0;
		for(int i = 0; i < n; i++){
			maxInCol[j] = ( maxInCol[j] < A[i][j] ) ? A[i][j] : maxInCol[j];
		}
	}

	for(int i = 0; i < n; i++){	
		for(int j = 0; j < m ;j++){
			if(A[i][j] < maxInRow[i] && A[i][j] < maxInCol[j]) possible = false;
		}
	}

	if(possible){
		printf("Case #%d: YES\n",c);
	}
	else{
		printf("Case #%d: NO\n",c);
	}

}

// BEGIN CUT HERE
int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("saida.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
		read();
		process(i+1);
	}
    return 0;
}
// END CUT HERE 
