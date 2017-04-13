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


int heights[20028], label[20028];
char basins[20028];

int root(int index)
{
	if (label[index] == index) return index;
	label[index] = root(label[index]);
	return label[index];
}

void unio(int a, int b)
{
	label[root(b)] = root(a);
}

// nwes
int dr[] = {-1, 0, 0, 1};
int ds[] = {0, -1, 1, 0};

#define pp(r,s) ((S+2)*(r) + (s))

int main()
{
	int T;
	scanf("%d ", &T);

	FOR (t, 0, T) {
		printf("Case #%d:\n", t+1);

		int R, S;
		scanf("%d %d ", &R, &S);

		memset(basins, 0, sizeof(basins));
		FOR (r, 0, R+2)
			FOR (s, 0, S+2) {
				label[pp(r,s)] = pp(r,s);

				if (r == 0 || r == R+1 || s == 0 || s == S+1)
					heights[pp(r,s)] = 100000;
				else
					scanf("%d ", &heights[pp(r,s)]);
		}

		int nwes[4];

		FOR (r, 1, R+1)
			FOR (s, 1, S+1) {
				FOR (i, 0, 4)
					nwes[i] = heights[pp(r+dr[i],s+ds[i])];
				
				int m = 0;
				FOR (i, 0, 4) if (nwes[i] < nwes[m]) m = i;

				if (nwes[m] < heights[pp(r,s)])
					unio(pp(r+dr[m],s+ds[m]), pp(r,s));
		}

		char next='a';
		FOR (r, 1, R+1) {
			FOR (s, 1, S+1) {
				if (basins[root(pp(r,s))] == 0)
					basins[root(pp(r,s))] = next++;
				printf("%c ", basins[root(pp(r,s))]);
			}
			putchar('\n');
		}



	}
	
}
