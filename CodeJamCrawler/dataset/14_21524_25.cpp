#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

#define inf 0x3f3f3f3f
#define min(a,b) a<b? a:b


int main()
{

	int t,caso=1;
	double c,f,x;
	scanf("%d",&t);
	while(t--){
		scanf("%lf %lf %lf",&c,&f,&x);
		double ans =  (double)inf;
		double tempo = 0;
		double cook = 2.0;
		while(ans > tempo + x/cook){
			ans = min(ans,tempo + x/cook);
			tempo += c/cook;
			cook += f;		
		}
		
		printf("Case #%d: %.7lf\n",caso++,ans);
	}



	return 0;
}
