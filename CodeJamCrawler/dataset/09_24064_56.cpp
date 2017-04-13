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

int T;
string N, res;

void solve()
{
	vector <char> num;
	bool ok=true;
	int nu=0;
	for (int i=0; i<N.size(); i++)
	{
		num.push_back(N[i]);
		if (i!=0)
			ok &= (N[i]<=N[i-1]);
		if (N[i]=='0') nu++;
	}
	if (ok)
	{
		sort(num.begin(), num.end());
		res="";
		res+=num[nu];
		for (int i=0; i<nu+1; i++) res+='0';
		for (int i=nu+1; i<num.size(); i++)
			res += num[i];
	}
	else
	{
		next_permutation(num.begin(), num.end());
		res="";
		for (int i=0; i<num.size(); i++)
			res+=num[i];
	}

}

void write(int i)
{

	printf("Case #%d: ", i);
	printf("%s", res.c_str());
	if (i!=T) printf("\n");

}
int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	char buf[1000];
	string s;


	scanf("%d",&T);
	gets(buf);
	for (int i=0; i<T; i++)
	{
		gets(buf);
		N=buf;
		solve();
		write(i+1);
	}



	return 0;
}
