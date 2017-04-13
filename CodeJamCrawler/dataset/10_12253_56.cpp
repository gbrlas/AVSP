#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

#define maxx(a,b) (((a)>(b))?(a):(b))
#define ls(a,b) (((a)<(b))||(fabs(a-b)<1e-9))
double B,T;
int N,K;
double x[100],v[100];
const double ZERO = .0;
int p[100];
int get()
{
	int j=0;
	for(int i=N-1;i>=0;i--,j++)
		if(p[i]) { p[i] = 0; return j;}
	return -1;
}
inline int count()
{
	double mx = 0;
	double t;
	int j;
	int c = 0;
	for(int i=0;i<N;i++)
	{
		j = i;
		t = (B-x[j])/v[j];
		p[i] = ls(t,T);
	}
	int xx;
	for(int i=0;i<K;i++)
	{
		if( (xx=get())==-1 ) return -1;
		c+=xx;
		N--;
	}
	return c;
}

int main()
{
	freopen("in.txt","rt",stdin);
	freopen("__out.txt","wt",stdout);
	int TC;
	cin>>TC;
	for(int tc=1;tc<=TC;tc++)
	{
		cerr<<tc<<endl;
		cin>>N>>K>>B>>T;
		for(int i=0;i<N;i++)
			cin>>x[i];
		for(int i=0;i<N;i++)
			cin>>v[i];
		printf("Case #%d: ",tc);
		int ans;
		if( (ans = count())!=-1)
			printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}