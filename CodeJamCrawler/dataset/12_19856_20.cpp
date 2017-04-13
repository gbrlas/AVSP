#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

#define PB push_back

//#define MAXN 10010
//#define MAXV 1030
//#define MAXP 12
#define coutpoint6 setiosflags(ios::fixed)<<setprecision(6)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

LL a[12];
long double x[12],y[12];

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int TT;
	cin>>TT;
	for (int T=1;T<=TT;T++)
	{
		cout<<"Case #"<<T<<": ";
		srand(time(NULL));
		LL xx,yy;
		int n;
		cin>>n>>xx>>yy;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		bool flag=true;
		do
		{
			for (int i=1;i<=n;i++)
			{
				x[i]=((LL(rand())*LL(rand()))%xx)+double(rand()%10000)/10000;
				y[i]=((LL(rand())*LL(rand()))%yy)+double(rand()%10000)/10000;
			}
			flag=true;
			for (int i=1;i<n && flag;i++)
				for (int j=i+1;j<=n && flag;j++)
				{
					if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) < (a[i]+a[j])*(a[i]+a[j]))
						flag=false;
				}
		}while (!flag);
		for (int i=1;i<=n;i++)
		{
			cout<<coutpoint6<<x[i]<<' '<<coutpoint6<<y[i];
			if (i!=n) cout<<' ';
		}
		cout<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
