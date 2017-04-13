#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

#define maxx(a,b) (((a)>(b))?(a):(b))
#define ls(a,b) (((a)<(b))||(fabs(a-b)<1e-9))
double B,T;
int N;
double x[100],v[100];
const double ZERO = .0;
int p[100];
inline int count()
{
	double mx = 0;
	double t;
	int j;
	int c = 0;
	for(int i=N-1;i>=0;i--)
	{
		j = p[i];
		t = (B-x[j])/v[j];
		mx = maxx( t , mx);
		if( ls(mx,T) ) c++;
		else break;
	}
	return c;
}

int get()
{
	int r = 0;
	for(int i=0;i<N;i++)
		if(r+= abs(p[i] - i ));
	return r/2;
}
int a[100];
inline int get2()
{
	memcpy(a,p,sizeof(p));
	int i,j;
	int r = 0;
	for(j=0;j<N;j++)
		for(i=0;i<N-1;i++)
			if(a[i]>a[i+1])
			{
				swap(a[i],a[i+1]);
				r++;
			}
			return r;


}
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int TC;
	int k;
	cin>>TC;
	for(int tc=1;tc<=TC;tc++)
	{
		cerr<<tc<<endl;
		cin>>N>>k>>B>>T;
		for(int i=0;i<N;i++)
			cin>>x[i];
		for(int i=0;i<N;i++)
			cin>>v[i];
		for(int i=0;i<N;i++)
			p[i] = i;
		int ans = INT_MAX;
		//int ans = 0;
		bool f;
		do{
			if( count() >= k)
			{
				ans = min(get2(),ans);
				//break;
			}
			//ans++;
		}while(next_permutation(p,p+N));
		printf("Case #%d: ",tc);
		if(ans < INT_MAX)
			printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}