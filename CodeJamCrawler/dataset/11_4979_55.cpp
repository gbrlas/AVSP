/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)


int main(){

	int t;
	scanf("%d",&t);
	REP(test,t)
	{
		int n;
		scanf("%d",&n);
		int a[100000];
		int check=0,total=0;
		REP(i,n)
		{
			scanf("%d",&a[i]);
			check^=a[i];
			total+=a[i];
		}

		if(check!=0)
			printf("Case #%d: NO\n",test+1);
		else
		{
			int minm=total;
			REP(i,n)
				if(check^a[i]==a[i])
				{
					if(a[i]<minm)
						minm=a[i];
				}
			printf("Case #%d: %d\n",test+1,total-minm);

		}
	}
	return 0;
}
