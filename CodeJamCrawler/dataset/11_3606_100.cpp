#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

int sum,ma,x;
int n,ti,T;

int main(){
	scanf("%d",&T);
	for (ti=1;ti<=T;ti++){
		printf("Case #%d: ",ti);
		scanf("%d",&n);
		x=0;
		sum=0;
		ma=100000000;
		for (int i=0;i<n;i++){
			int j;
			scanf("%d",&j);
			x^=j;
			sum+=j;
			ma=min(ma,j);
		}
		if (x==0) printf("%d\n",sum-ma);
		else printf("NO\n");
	}
    return 0;
}
