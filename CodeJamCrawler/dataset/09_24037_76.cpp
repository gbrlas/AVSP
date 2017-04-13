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

char welcome[] = "welcome to code jam";
int length;
int counts[30];
char line[1024];

int main()
{
	length = strlen(welcome);

	int T;
	scanf("%d ", &T);

	FOR (t, 0, T) {

		memset(counts, 0, sizeof(counts));
		counts[0] = 1;

		gets(line);
		int l = strlen(line);


		FOR (i, 0, l) {
			for (int c = length; c > 0; c--) {
				if (line[i] == welcome[c-1]) {
					counts[c] += counts[c-1];
					counts[c] %= 10000;
				}
			}
		}

		printf("Case #%d: %04d\n", t+1, counts[length]);


	}
	
}
