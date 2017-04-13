#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <numeric>
#include <cstdio>
#include <memory.h>

using namespace std;   

#define SZ(a) ((int)(a).size())
#define SQR(a) ((a)*(a))
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)
#define FILL(a, b) memset(a, b, sizeof(a))
#define FHAS(a, b) (find((a).begin(), (a).end(), (b))!=(a).end())
#define HAS(a, b) ((a).find(b) != (a).end())
#define HASB(a, b) (((a) & (1 << (b)))>0)

template<class A, class B> A convert(B x) {stringstream s; s << x; A r; s >> r; return r;}

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;

const string prob = "B";

char line[1<<10];

int getHash(int t1, int t2) {
	return t1*26+t2;
}

int main() {

	freopen((prob+".in").c_str(), "r", stdin);
	freopen((prob+".out").c_str(), "w", stdout);

	int tc, gl=1; scanf("%d", &tc);

	while (tc --> 0)
	{
		int d, c ,n;
		int matr[26][26]; FILL(matr, -1);
		set<int> s;
		VI curr;

		scanf("%d", &c);
		FOR(i, 0, c)
		{
			char op[10]; scanf("%s", op);
			matr[op[0]-'A'][op[1]-'A'] = op[2]-'A';
			matr[op[1]-'A'][op[0]-'A'] = op[2]-'A';
		}
		scanf("%d", &d);
		FOR(i, 0, d)
		{
			char op[10]; scanf("%s", op);
			s.insert(getHash(op[0]-'A', op[1]-'A'));
			s.insert(getHash(op[1]-'A', op[0]-'A'));
		}
		scanf("%d", &n);
		scanf("%s", line);

		FOR(i, 0, n)
		{
			int ch = line[i]-'A';
			curr.push_back(ch);

			if (SZ(curr)>1 && matr[curr[SZ(curr)-1]][curr[SZ(curr)-2]]!=-1)
			{
				int t = matr[curr[SZ(curr)-1]][curr[SZ(curr)-2]];
				curr.pop_back(); curr.pop_back();
				curr.push_back(t);
				continue;
			}

			FOR(j, 0, SZ(curr)-1)
				if (HAS(s, getHash(curr[j], curr.back())))
				{
					curr.clear();
					break;
				}
		}

		printf("Case #%d: ", gl++);
		printf("[");
		FOR(i, 0, SZ(curr))
		{
			if (i) printf(", ");
			printf("%c", curr[i]+'A');
		}
		printf("]\n");
	}

	return 0;
}