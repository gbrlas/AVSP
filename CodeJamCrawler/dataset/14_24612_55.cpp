#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int task;
double c, f, x;

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d", &task);
	for (int CASE = 1; CASE<=task; CASE++){
		scanf("%lf%lf%lf", &c, &f, &x);
		double ret = x/2.0, t = 0, current;
		for (int i=1; i<=int(x*3+1); i++){
			t += c/(2+(i-1)*f);
			current = t+x/(2+f*i);
			if ( current<ret ) ret = current;
		}
		printf("Case #%d: %.7lf\n", CASE, ret);
	}
	return 0;
}
