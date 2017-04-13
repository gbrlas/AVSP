#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR2(i,a,b) for (int i = (b)-1; i >= (a); --i)

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define $(x) int(x.size())
#define PB push_back

typedef pair<int,int> PII;
typedef long long ll;
typedef long double ld;

char tab[50][50];
int pole[50];

int bubblesort(int S)
{
	int res = 0;
	FOR (act, 0, S) {
		int j;
		for (j = act; pole[j] > act; j++);
		for (; j > act; j--) {
			swap(pole[j], pole[j-1]);
			res++;
		}
	}
	return res;
}

int main()
{
	int T;
	scanf("%d ", &T);

	FOR (t, 0, T) {

		int S;
		scanf("%d ", &S);
		
		FOR (s, 0, S) {
			scanf("%s", tab[s]);
			int i;
			for (i = S; i > 0 && tab[s][i-1] == '0'; i--);
			pole[s] = i-1;
		}
		
		printf("Case #%d: %d\n", t+1, bubblesort(S));

	}
	
}
