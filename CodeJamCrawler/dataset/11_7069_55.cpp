//jonathanirvings template

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
jonathan ganteng banget;

#define TEST printf("tes\n");
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
#define LL long long

bool vowel(char a)
{
	if (a == 'Q') return true;
	if (a == 'W') return true;
	if (a == 'E') return true;
	if (a == 'R') return true;
	if (a == 'A') return true;
	if (a == 'S') return true;
	if (a == 'D') return true;
	if (a == 'F') return true;
	return false;
}

int t,n,a,b;
vector <char> s;
char x,y[5];
char vowels[8] = {'Q','W','E','R','A','S','D','F'};
string tukarz,hilangz;
bool cantukar[256][256],hilang[256][256];
char tukar[256][256];


int main()
{
	//freopen("magicka.in","r",stdin);
	//freopen("magicka.out","w",stdout);
	scanf("%d",&t);
	FORN(cases,1,t)
	{
		FORN(i,0,7) FORN(j,0,7) 
		{
			cantukar[vowels[i]][vowels[j]] = 0;
			hilang[vowels[i]][vowels[j]] = 0;
		}
		while (!s.empty()) s.pop_back();
		printf("Case #%d: ",cases);
		scanf("%d",&a);
		FORN(i,1,a)
		{
			scanf(" %s",y),tukarz = y;
			char tmp1 = tukarz[0];
			char tmp2 = tukarz[1];
			char tmp3 = tukarz[2];
			cantukar[tmp1][tmp2] = cantukar[tmp2][tmp1] = 1;
			tukar[tmp1][tmp2] = tukar[tmp2][tmp1] = tmp3;
		}
		scanf("%d",&b);
		FORN(i,1,b)
		{
			scanf(" %s",y),hilangz = y;
			char tmp1 = hilangz[0];
			char tmp2 = hilangz[1];
			hilang[tmp1][tmp2] = hilang[tmp2][tmp1] = 1;
		}
		scanf("%d ",&n);
		//cout << a << tukar << " " << b << hilang << endl;
		while (n--)
		{
			scanf("%c",&x);
			s.push_back(x);
			int sz = s.size();
			if (a && sz > 1)			
			{
				if (cantukar[s[sz-1]][s[sz-2]])
				{
					s.pop_back();
					s.pop_back();
					s.push_back(tukar[s[sz-1]][s[sz-2]]);
				}
			}
			sz = s.size();
			if (b && sz > 1)
			{
				//TEST;
				//printf("-----%d\n",cek);
				bool ada = 0;
				FORN(i,0,s.size()-2)
					if (hilang[s[i]][s[sz-1]]) 
					{
						ada = 1;
						break;
					}
				if (ada)
					while (!s.empty()) s.pop_back();
			}
		}
		int sz = s.size();
		printf("[");
		if (sz > 0) printf("%c",s[0]);
		FORN(i,1,sz-1) printf(", %c",s[i]);
		printf("]\n");
	}
}
