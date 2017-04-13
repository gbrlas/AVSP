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


int L,D,N, ans;
vector <string> words;

bool match(string pat, string s)
{
	int j=0, state=0;
	for (int i=0; i<pat.size(); i++)
	{
		if (state==0 && pat[i]=='(')
			state = 1;
		else if (state==0 && pat[i]==s[j])
			j++;
		else if (state==0 && pat[i]!=s[j])
			return false;
		else if (state==1 && pat[i]==')')
			return false;
		else if (state==1 && pat[i]==s[j])
		{   state = 2;j++;}
		else if (state==2 && pat[i]==')')
			state=0;
	}
	return true;
}



void solve(string s)
{
	ans = 0;
	for (int i=0; i<words.size(); i++)
		if (match(s,words[i])) ans++;
}

void write(int i)
{
	if (i!=N+1)
		printf("Case #%d: %d\n", i, ans);
	else
		printf("Case #%d: %d", i, ans);

}
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	char buf[1000];
	string s;


	scanf("%d%d%d",&L, &D, &N);
	gets(buf);
	for (int i=0; i<D; i++)
	{
		gets(buf);
		s=buf;
		words.push_back(s);
	}


	for (int i=0; i<N; i++)
	{
		gets(buf);
		s=buf;
		solve(s);
		write(i+1);
	}
	return 0;
}
