#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define pub(x) push_back(x)
#define x first
#define y second
#define MP make_pair
typedef long long ll;
bool opp[100][100];
char mak[100][100];
char s[1000];
vector<char> v;
int main()
{
	freopen("b0.in", "r", stdin);
	freopen("b0.txt", "w",stdout);
	int task; scanf("%d", &task);
	for (int cas = 1; cas <= task; ++cas)
	{
		printf("Case #%d: ", cas);
		memset(opp, 0, sizeof opp);
		memset(mak, 0, sizeof mak);
		int C, D; scanf("%d", &C);
		for (int i = 1; i <= C; ++i)
		{
			scanf("%s", s); 
			mak[s[0]][s[1]] = mak[s[1]][s[0]] = s[2];
		}
		scanf("%d", &D);
		for (int i = 1; i <= D; ++i)
		{	
			scanf("%s", s);
			opp[s[0]][s[1]] = opp[s[1]][s[0]] = true;
		}
		int m; scanf("%d", &m);
		scanf("%s", s);
		
		v.clear();
		
		for (int i = 0; i < m; ++i)
		{
			bool done = false;
			if (!v.empty())
			{
				char t = mak[v.back()][s[i]];
				if (t > 0) { v[v.size() - 1] = t; done = true;}
			}
			if (!done)
			for (size_t k = 0; k < v.size(); ++k)
				if (opp[v[k]][s[i]])
				{
					v.clear();
					done = true;
					break;
				}
			if (!done)
				v.pub(s[i]);
		}
		printf("[");	
		for (size_t i = 0; i < v.size(); ++i)
		{
			if (i > 0) printf(", ");
			printf("%c", v[i]);
		}
		puts("]");
	}
	return 0;
}

