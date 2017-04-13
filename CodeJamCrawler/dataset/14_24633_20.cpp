#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

multiset<int> a;
set<int>::iterator I, II;
int task, CASE=0;
int n, m;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	
	for (scanf("%d", &task); task--;){
		scanf("%d%d", &n, &m);
		a.clear();
		for (int i=0; i<n; i++){
			int x;
			scanf("%d", &x);
			a.insert( x );
		}

		int ret=0;
		while (a.size()>0){
			I = a.end();
			I--;
			II = a.upper_bound( m-*I );
			if ( II!=a.begin() ){
				II--;
				if ( II==I && II!=a.begin() ) II--;
				if ( II!=I && *II + *I <=m ){
					a.erase( II );
				}
			}

			a.erase( I );
			ret++;
		}
		printf("Case #%d: %d\n", ++CASE, ret);
	}
	return 0;
}
