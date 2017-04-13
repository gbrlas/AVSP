#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<cmath>
#include<assert.h>
using namespace std;
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#define ll long long
#define ull unsigned long long
#define inf 1001001001
#define mod 1000000007
#define pii pair<int,int>
#define vi vector<int>
#define VS vector<string>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define N 110
#define pi 3.14159265358979323846
#define DBG(vari) cerr<<#vari<<"="<<(vari)<<endl;
#define FOREACH(i,t) for(typeof(t.begin()) i=t.begin();i!=t.end();i++)


int main()
{
	int T,i,j,k,ca=0,n,m;
	ofstream f("A-small-attempt2.in",ios::trunc);
	scanf("%d",&T);
	while(T--)
	{
		int v[17]={0};
		for(i=0;i<2;i++)
		{
			scanf("%d",&m);
			for(j=0;j<4;j++)
			for(k=0;k<4;k++)
			{
				int x;
				scanf("%d",&x);
				if(j==m-1)v[x]+=i+1;
			}
		}
		for(i=1,m=0;i<=16;i++)
		if(v[i]==3)m++,k=i;
		f<<"Case #"<<++ca<<": ";
		if(m==1)f<<k;
		else if(m==0)f<<"Volunteer cheated!";
		else f<<"Bad magician!";
		f<<"\n";
	}
	return 0;
}