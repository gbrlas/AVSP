#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int task, n, ret, ret2;
double a[2000], b[2000];

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d", &task);
	for (int CASE = 1; CASE<=task; CASE++){
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%lf", a+i);
		for (int i=0; i<n; i++)
			scanf("%lf", b+i);
		sort(a, a+n);
		sort(b, b+n);
		ret = ret2 = 0;
		for (int i=0, s=0; i<n; i++)
		if ( a[i]>b[s] ){
			ret2++;
			s++;
		}
		for (int i=n-1, s=n-1; i>=0; i--)
		if ( b[s]>a[i] ){
			ret++;
			s--;
		}
		printf("Case #%d: %d %d\n", CASE, ret2, n-ret);
	}
	return 0;
}
