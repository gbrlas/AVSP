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
#define INF 1000000000
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)


int main(){

	int t;

	double a[1000010],offset;
	scanf("%d",&t);
	FOR(test,1,t+1)
	{
		int n,xy;double d,z;
		scanf("%d%lf",&n,&d);
		int ctr=1;
		FOR(i,1,n+1)
		{
			scanf("%lf%d",&z,&xy);
			REP(j,xy)
				a[ctr++]=z;

		}

		sort(&a[1],&a[ctr]);
		a[0]=-1000000000;
		double start=0,end=1000000000;
		double mid=(start+end)/2.0,prev,cur;

		

		//	printf("%lf\n",min(1.11,1.1));
		while(end-start>1e-8)
		{

			prev=a[0];
			mid=(start+end)/2.0;
			bool np=false;
			FOR(i,1,ctr)
			{
				cur=a[i];

				if(cur-prev>d)
				{
					cur-=min(cur-prev-d,mid);
					prev=cur;
					continue;
				}
				if(cur+mid-prev<d)
				{
					np=true;
					break;
				}
				cur+=(d-(cur-prev));
				prev=cur;
			}
			if(np==true)
				start=mid;
			else
				end=mid;
		}

		printf("Case #%d: %.8lf\n",test,(start+end)/2.0);

	}
	return 0;
}

