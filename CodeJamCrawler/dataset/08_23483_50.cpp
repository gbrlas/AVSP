#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

typedef long long int64 ;
int N, T, NA, NB, A, B;
vector <int> tda, tab, tdb, taa;
vector<int> ta,tb;


void read()
{
	scanf("%d", &T);
	scanf("%d", &NA);
	scanf("%d", &NB);
	int h,m;
	tda.clear(); tab.clear(); tdb.clear(); taa.clear();
	for (int i=0; i<NA; i++)
	{
		scanf("%d:%d", &h, &m);
		tda.push_back(h*60+m);
		scanf("%d:%d", &h, &m);
		tab.push_back(h*60+m);
	}
	for (int i=0; i<NB; i++)
	{
		scanf("%d:%d", &h, &m);
		tdb.push_back(h*60+m);
		scanf("%d:%d", &h, &m);
		taa.push_back(h*60+m);
	}

}
void addta(int i)
{
	for (int j=i; j<ta.size(); j++)
		ta[j]++;
}
void remta(int i)
{
	for (int j=i; j<ta.size(); j++)
		ta[j]--;
}

void addtb(int i)
{
	for (int j=i; j<tb.size(); j++)
		tb[j]++;
}
void remtb(int i)
{
	for (int j=i; j<tb.size(); j++)
		tb[j]--;
}

void solve()
{
	A=0; B=0;
	vector <int> times;
	for (int i=0; i<NA; i++)
	{times.push_back(tda[i]); times.push_back(tab[i]+T);}
	for (int i=0 ; i<NB; i++)
	{times.push_back(tdb[i]); times.push_back(taa[i]+T);}	

	sort(times.begin(), times.end());

	map <int, int> tms;
	for (int i=0; i<times.size(); i++)
		tms.insert(make_pair(times[i], tms.size()));
	ta.clear(); tb.clear();
	ta.resize(tms.size()); tb.resize(tms.size());

	vector <pair<int, int>> AB, BA;
	for (int i=0 ;i<NA; i++)
		AB.push_back(make_pair(tda[i], tab[i]+T));

	for (int i=0 ;i<NB; i++)
		BA.push_back(make_pair(tdb[i], taa[i]+T));
	sort(AB.begin(), AB.end());
	sort(BA.begin(), BA.end());
	int ca=0, cb=0;
	while ((ca<NA)&&(cb<NB))
	{
		if (AB[ca].first<BA[cb].first)
		{
			if (ta[tms[AB[ca].first]]==0)
			{
			//	addta(tms[AB[ca].first]);
				A++;
			}
			else
				remta(tms[AB[ca].first]);
			addtb(tms[AB[ca].second]);
			ca++;
		}
		else 
		{
			if (tb[tms[BA[cb].first]]==0)
			{
			//	addtb(tms[BA[cb].first]);
				B++;
			}
			else
				remtb(tms[BA[cb].first]);
			addta(tms[BA[cb].second]);
			cb++;
		}
	}
	if (ca<NA)
		for (int i=ca; i<NA; i++)
		{
			if (ta[tms[AB[i].first]]==0)
				A++;
			else remta(tms[AB[i].first]);
		}
	if (cb<NB)
		for (int i=cb; i<NB; i++)
		{
			if (tb[tms[BA[i].first]]==0)
				B++;
			else remtb(tms[BA[i].first]);
		}




}

void write(int i)
{
	if (i>1)
		printf("\nCase #%d: %d %d", i, A, B);
	else 
		printf("Case #%d: %d %d", i, A, B);
}
int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	scanf("%d", &N);
	for (int i=0; i<N; i++)
	{
		read();
		solve();
		write(i+1);
	}
	return 0;
}
