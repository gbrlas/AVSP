#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long LL;
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
int t;
int main()
{
	//freopen("CCA.out","w",stdout);
	scanf("%d", &t);
	for(int h=1;h<=t;h++)
	{
		double sek = 2;
		double c,x, f;
		scanf("%lf%lf%lf", &c, &f, &x);
		double mini = x/2;
		double now = 0;
		while(1)
		{
			//printf("%lf\n", mini);
			double tim = now + c/sek;
			double ti = tim + x/(sek+f);
			if(mini-ti > EPS)
			{
				mini = ti;
				now = tim;
				sek+=f;
			}
			else break;
		}
		printf("Case #%d: %.10lf\n", h,mini);
	}
	return 0;
}
