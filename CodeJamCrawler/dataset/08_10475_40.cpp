#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

pair<long long,long long> a[100005];
int main()
{
	freopen("in.in","rt",stdin);
	freopen("out.txt","wt",stdout);

	long long n, A, B, C, D, x0, y0 , M;
	long long X,Y,cc=0;
	int i,j,k;
	int TC;
	cin>>TC;
	for(int tc=1;tc<=TC;tc++)
	{
		cin>>n>>A>> B>> C>> D>> x0>> y0 >> M;
		int ans = 0;
		cc=0;
		X = x0, Y = y0;
		a[cc++] = make_pair(X,Y);
		//print X, Y
		for ( i = 1 ;i< n;i++)
		{
			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
			a[cc++] = make_pair(X,Y);
		}
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(i!=j)
					for(k=j+1;k<n;k++)
						if(i!=k && j!=k)
							if( ( a[i].first+a[j].first+a[k].first ) % 3 == 0
								&& ( a[i].second+a[j].second+a[k].second ) % 3 == 0 )
								ans++;
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
