#include<iostream>
#include<sstream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define INF 0xffffff
#define LL  long long
#define maxx(a, b) ((a > b)? a: b)
#define minn(a, b) ((a < b)? a: b)

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for ( int t = 1 ; t <= T ; t++ ){
		double c,f,x;
		cin >> c >> f >> x;
		double Cockie = 0;
		double per = 2;
		double req = 0;
		while (1 ){
			if ( x / per < ( ( x/(per+f) ) + (c/per) ) )
			{
				req += x/per;
				printf("Case #%d: %.7f\n",t,req);
				break;
			}
			else{
				 req += c/per;
				 per += f;
			}
		}
	}
	return 0;
}