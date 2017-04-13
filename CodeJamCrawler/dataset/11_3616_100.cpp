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

double f[1100];
int n,ti,T;
int a[1100],b[1100];


int main(){
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		printf("Case #%d: ",ti);
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]),b[i]=a[i];
		sort(b,b+n);
		int m=0;
		for (int i=0;i<n;i++) if (a[i]==b[i]) m++;
		printf("%.6f\n",(double)n-m);
	}
    return 0;
}
