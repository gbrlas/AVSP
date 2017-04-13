#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define PB push_back

#define MAXN 10010
//#define MAXV 1030
//#define MAXP 12
//#define coutpoint7 setiosflags(ios::fixed)<<setprecision(7)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

int a[MAXN],d[MAXN],l[MAXN];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int TT;
	cin>>TT;
	for (int T=1;T<=TT;T++)
	{
		cout<<"Case #"<<T<<": ";
		int n,dist;
		bool ans=false;
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>d[i]>>l[i];
		cin>>dist;
		memset(a,0,sizeof(a));
		a[1]=d[1]*2;
		if (a[1]>=dist) ans=true;
		for (int i=1;i<n && (!ans);i++)
		{
			for (int j=i+1;j<=n && (!ans);j++)
			{
				if (d[j]<=a[i])
				{
					int temp=d[j]+min(d[j]-d[i],l[j]);
					if (temp>a[j])
					{
						a[j]=temp;
						if (a[j]>=dist) ans=true;
					}
				}
				else break;
			}
		}
		if (ans) cout<<"YES\n"; else cout<<"NO\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
