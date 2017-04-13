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
		char s[10];
		scanf("%d ",&n);

		int x,op=1,bp=1,ot=0,bt=0,total=0;
		while(n--)
		{
			scanf("%s",s);
			scanf("%d",&x);
			int buf,dist;
			if(s[0]=='O')
			{
				buf=total-ot;
				dist=abs(op-x);
				if(buf>=dist)
					total+=1;
				else
					total+=((dist-buf)+1);
				op=x;
				ot=total;
			}
			else
			{
				buf=total-bt;
				dist=abs(bp-x);
				if(buf>=dist)
					total+=1;
				else
					total+=((dist-buf)+1);
				bp=x;
				bt=total;
			}

		}
		printf("Case #%d: %d\n",test+1,total); 
	}
	return 0;
}
