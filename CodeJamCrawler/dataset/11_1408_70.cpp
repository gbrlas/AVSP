#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    //freopen("in.txt","r",stdin);
	freopen("C-large.in","r",stdin);
	freopen("C-large-output.txt","w",stdout);
    int t=0, T, n;
	cin >> T;
	for (;t<T; t++) {
		cin >> n;
		vector<int> v(n);
		int xorn = 0, sum=0, mini = 1<<30;
		for(int i=0; i<n; i++) {
			cin >> v[i];
			mini = min(mini, v[i]);
			sum += v[i];
			xorn ^= v[i];
		}
		
		if ( xorn != 0)
			printf("Case #%d: NO\n", t+1);
		else
			printf("Case #%d: %d\n", t+1, sum - mini);
	}
    return 0;
}
