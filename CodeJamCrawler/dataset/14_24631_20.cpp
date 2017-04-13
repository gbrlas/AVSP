#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int task, CASE=0;
int n, m, a[100000];
bool b[100000];

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	
	for (scanf("%d", &task); task--;){
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; i++){
			scanf("%d", a+i);
			b[i] = false;
		}
		sort( a, a+n );

		int ret = 0;
		for (int i=n-1; i>=0; i--)
		if ( !b[i] ){
			int mm = -1;
			for (int j=0; j<i; j++)
			if ( !b[j] && a[j]+a[i]<=m ){
				mm=j;
			}else if ( a[j]+a[i]>m ){
				break;
			}

			if ( mm!=-1 ){
				b[mm] = true;
			}
			b[i] = true;
			ret++;
		}

		printf("Case #%d: %d\n", ++CASE, ret);
	}
	return 0;
}
