#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int task, CASE=0;
int n, a[100000], b[100000];
vector<int>L;
vector<int>R;

int calc( vector<int>a, bool option ){
	int ret = 0;
	for (int i=0; i<a.size(); i++)
	for (int j=i+1; j<a.size(); j++)
		if ( option && a[i]>a[j] || !option && a[i]<a[j] )
			ret++;
	return ret;
}

int main()
{
	freopen("B-small-attempt3.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &task); task--;){
		scanf("%d", &n);
		int X = -1;
		for (int i=0; i<n; i++){
			scanf("%d", a+i);
			if ( X==-1 || a[i]>a[X] )
				X = i;
		}

		int ret = 1000000000, current;
		for (int mask=0; mask<(1<<n); mask++){
			current = 0;
			L.clear(); R.clear();
			for (int i=0; i<n; i++){
				if ( (1<<i)& mask ){
					b[i] = true;
					L.push_back( a[i] );
				}
				else
				{
					b[i] = false;
					R.push_back( a[i] );
				}
			}

			for (int x=0; x<n; x++)
			for (int y=x+1; y<n; y++)
			if ( !b[x] && b[y] )
				current++;

			current += calc(L, true)+calc(R, false);
			ret = min( ret, current );
		}
		printf("Case #%d: %d\n", ++CASE, ret);
	}
	return 0;
}
