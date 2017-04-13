
#include <bits/stdc++.h>
#define scan1(_x) scanf("%d", &(_x))
#define scan2(_x,_y) scanf("%d%d", &(_x), &(_y))
#define scan3(_x,_y,_z) scanf("%d%d%d", &(_x), &(_y),&(_z))
#define F first
#define S second
#define pb push_back
#define makep make_pair
#define clr(_M,_v) memset((_M), (_v), sizeof (_M))
#define FOR(_i,_a,_b) for(int (_i) = (_a); (_i) < (_b); (_i)++)
#define FN(i,n) for(int i=0;i<n;i++)
#define MOD 1073741824
#define LOGN 30
using namespace std;
long double c,f,x; 
int main() {
	int tc;
	scan1(tc);
	FN(itc,tc)
	{
		cin>>c>>f>>x;
		int mini=(int)(floor((x*f-double(2)*c)/(f*c)));
		if(mini<0) mini=0;
		long double s1=0,s2=0;
		FN(i,mini)
		{
		    s1+=c/(2.0+i*f);
		}
		s2=s1+c/(2.0+mini*f);
		s1+=x/(2.0+mini*f);
		s2+=x/(2.0+(mini+1.0)*f);
		printf("Case #%d: %.7Lf\n",itc+1,min(s1,s2));
		
		
	}
}
