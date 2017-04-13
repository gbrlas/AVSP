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
int N, S, Q, ans;
vector <string> se, qu;


string Trim(const string& s, string sep="\n")
{
	string tmp;
	int i = s.find_first_not_of(sep), j = s.find_last_not_of(sep);
	
	if (j==string::npos) 
	{
		if (i==string::npos) return"";
		tmp= s.substr(i);
		return tmp;
	}
	if (i==string::npos) i=0;
	tmp=s.substr(i, j-i+1);
	return tmp;
}

void read()
{
	char buf[200];
	string tmp;
	se.clear();
	qu.clear();
	scanf("%d", &S);
	gets(buf);
	for (int j=0; j<S; j++)
	{
		gets(buf);
		tmp=buf;
		tmp=Trim(tmp);
		se.push_back(tmp);
	}
	scanf("%d", &Q);
	gets(buf);
	for (int j=0; j<Q; j++)
	{
		gets(buf);
		tmp=buf;
		tmp=Trim(tmp);
		qu.push_back(tmp);
	}
}

void solve()
{
	map <string, int> eng;
	ans=0;
	for (int i=0; i<S; i++)
	{
		eng.insert(make_pair(se[i], i));
	}
	vector <int> ord;
	for (int i=0; i<Q; i++)
	{
		if (eng.find(qu[i])!=eng.end())
			ord.push_back(eng[qu[i]]);
		else ord.push_back(-1);
	}
	bool used[200];
	int curq=0, curs=-1, cnt;
	while (true)
	{
		for (int i=0; i<S; i++)
			used[i]=false;
		cnt=0;
		if (curs>=0) {used[curs]=true; cnt=1;}
		while ((cnt<S)&&(curq<Q))
		{
			if (ord[curq]!=-1)
				if (used[ord[curq]]==false)
				{
					used[ord[curq]]=true;
					cnt++;
				}
			curq++;
		}
		if (cnt==S)
		{
			if (curs!=-1) ans++;
			curs=ord[curq-1];			
		}
		else if (curs==-1) {ans=0; break;}
		else {ans++; break;}
	}
}

void write(int i)
{
	if (i>1)
		printf("\nCase #%d: %d", i, ans); 
	else 
		printf("Case #%d: %d", i, ans); 
}
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	scanf("%d", &N);
	for (int i=0; i<N; i++)
	{
		read();
		solve();
		write(i+1);
	}
	return 0;
}
