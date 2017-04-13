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
string tukar,hilang;

int main()
{
	//freopen("magicka.in","r",stdin);
	//freopen("magicka.out","w",stdout);
	scanf("%d",&t);
	FORN(cases,1,t)
	{
		while (!s.empty()) s.pop_back();
		printf("Case #%d: ",cases);
		scanf("%d",&a);
		if (a) scanf(" %s",y),tukar = y;
		scanf("%d",&b);
		if (a)
		{
			if (!vowel(tukar[0])) swap(tukar[0],tukar[2]);
			if (!vowel(tukar[1])) swap(tukar[1],tukar[2]);
		}
		if (b) scanf(" %s",y),hilang = y;
		scanf("%d ",&n);
		//cout << a << tukar << " " << b << hilang << endl;
		while (n--)
		{
			scanf("%c",&x);
			s.push_back(x);
			int sz = s.size();
			if (a && sz > 1)			
			{
				//printf("tes%d\n",sz);
				char tukara = tukar[0];
				char tukarb = tukar[1];
				if ((s[sz-1]==tukara&&s[sz-2]==tukarb) || (s[sz-1]==tukarb&&s[sz-2]==tukara))
				{
					//TEST;
					s.pop_back();
					s.pop_back();
					s.push_back(tukar[2]);
				}
			}
			sz = s.size();
			if (b && sz > 1)
			{
				char tmp = s[s.size()-1];
				int cek = -1;
				//TEST;
				if (tmp == hilang[0]) cek = 1;
				if (tmp == hilang[1]) cek = 0;
				sz = sz - 2;
				//printf("-----%d\n",cek);
				if (cek > -1)
				{
					bool ada = 0;
					FORN(i,0,s.size()-2)
						if (s[i] == hilang[cek]) {ada = 1;break;}
					if (ada)
						while (!s.empty()) s.pop_back();
				}
			}
		}
		int sz = s.size();
		printf("[");
		if (sz > 0) printf("%c",s[0]);
		FORN(i,1,sz-1) printf(", %c",s[i]);
		printf("]\n");
	}
}
