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

long long square[20000];
int p = 0;

long long A,B;
int S[3];
long long myPow10[16] = {1, 10, 100, 1000, 10000, 100000, 1000000LL, 10000000LL, 100000000LL, 1000000000LL, 10000000000LL, 100000000000LL, 1000000000000LL, 10000000000000LL, 100000000000000LL, 1000000000000000LL};

bool ePal(long long cand){
	int c = 1;

	while(myPow10[c] <= cand) c++;
	
	long long bottom = cand;
	for(int i = 0; i < c/2; i++){
		if(bottom%10 != (cand/myPow10[c - 1 - i] )%10) return false;
		bottom /= 10;
	}
	
	return true;
}

void getAll(int l){

	long long upper = 0;
	long long lower = 0;

	for(int i = 0; i < l; i++){
		upper += S[i]*myPow10[l-1 - i];
		lower += S[i]*myPow10[i];
	}

	if(l>0){
		long long pPar = upper*myPow10[l] + lower;
		long long parS = pPar*pPar;
		if(ePal(parS))
			square[p++] = parS;
	}
	
	for(int j = 0; j < 10; j++){
		long long pImpar = upper*myPow10[l+1] + j*myPow10[l] + lower;
		long long imparS = pImpar*pImpar;
		if(ePal(imparS))
			square[p++] = imparS;
	}
}

void sufixo(int tam){
	if(tam <= 3){
		getAll(tam);
		for(int j = 1; j <= 9; j++){
			S[tam] = j;
			sufixo(tam+1);
		}
	}
}

int bb(long long x){
	int ini = 0;
	int fim = p-1;
	int meio;

	while(fim - ini > 1){
		meio = (fim + ini)/2;
		if(square[meio] <= x) ini = meio;
		else fim = meio;
	}
	
	if(square[fim] <= x) return fim+1;
	else return ini+1;
}

void read(){
	scanf("%lld %lld", &A, &B);
}

void process(int c){
	printf("Case #%d: %d\n", c, bb(B) - bb(A-1));
}

// BEGIN CUT HERE
int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("saida.txt","w",stdout);

    int t;

    scanf("%d",&t);

	sufixo(0);
	sort(square, square + p);
//	for(int i = 0; i < p; i++)
	//	printf("%lld\n", square[i]);

    for(int i = 0; i < t; i++){
		read();
		process(i+1);
	}
    return 0;
}
// END CUT HERE 
