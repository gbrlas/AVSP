#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> pint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;


double c,f,x;

double g(double m, double h)
{
	if (h>=x)
		return 0;
	double ans=__builtin_inf();
	if (m<20*x)
	{
		if (h>=c)
			ans=g(m+f,h-c);
		else
			ans=(c-h)/m+g(m,c);
	}
	ans=min(ans,(x-h)/m);
	return ans;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++)
	{
		printf("Case #%d: ",t);
		scanf("%lf %lf %lf",&c,&f,&x);
		if (x<=c)
			printf("%.7lf\n",x/2);
		else
			printf("%.7lf\n",g(2,0));
	}
	return 0;
}
