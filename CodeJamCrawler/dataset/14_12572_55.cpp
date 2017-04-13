#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

using namespace std;

#define ll long long
#define inf 2000000000
#define mod 1000000007
#define vv vector<int>
#define pp pair<int,int>
#define vvp vector<pp>
#define pb push_back
#define st set<int>
#define mp map<string,int>
#define pr(cn,x) ((cn).find(x)!=(cn).end()) 
#define tr(cn,it) for(typeof((cn).begin()) it=(cn).begin();it!=(cn).end();it++)

int main()
{
	int tc,i;
	double c,f,x,s,d,curr,next;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		d=2; s=c/d;
		curr=x/d; 
		d+=f;
		next=s+(x/d);
		while(next<=curr)
		{
			s+=(c/d);
			curr=next;
			d+=f;
			next=s+(x/d);
		}
		printf("Case #%d: %0.7lf\n",i,curr);
	}
	return 0;
}
