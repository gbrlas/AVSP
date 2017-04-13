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
#include<iomanip>
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
	//ofstream f1("B-small-attempt1.in",ios::trunc);
	scanf("%d",&T);
	while(T--)
	{
		double c,f,x;
		scanf("%lf%lf%lf",&c,&f,&x);
		double v=2,t=0,s=0;
		while(x>=c+c*v/f)
		{
			s=c/v;
			t+=c/v;
			v+=f;
			//DBG(t)
		}
		t+=x/v;
		printf("Case #%d: %.7lf\n",++ca,t);
		//f1<<"Case #"<<++ca<<": "<<setiosflags(ios::fixed)<<setprecision(8)<<t<<endl;
	}
	return 0;
}