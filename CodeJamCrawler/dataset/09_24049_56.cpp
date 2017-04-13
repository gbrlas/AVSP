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

char digits[20];

int main()
{
	int T;
	scanf("%d ", &T);

	FOR (t, 0, T) {

		memset(digits, 0, sizeof(digits));
		gets(digits);
		int l = strlen(digits);
		if (!next_permutation(digits, digits+l)) {
			int i;
			for (i = l; i >= 0; i--)
				digits[i+1] = digits[i];
			digits[0] = '0';
			i = 0;
			while (digits[i] == '0') i++;
			digits[0] = digits[i];
			digits[i] = '0';
		}

		printf("Case #%d: %s\n", t+1, digits);


	}
	
}
