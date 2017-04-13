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
typedef long long int LL;
#define mod 1000000007

int main(){

	int t;
	scanf("%d",&t);
	FOR(test,1,t+1)
	{
		int n;
		scanf("%d\n",&n);
		char s[110][110];
		REP(i,n)
		{
			REP(j,n)
			{
				scanf("%c",&s[i][j]);
			}
			scanf("\n");
		}

		//loop for WP

		int total[110]={0},win[110]={0};
		double wp[110]={0},owp[110]={0},oowp[110]={0};
		REP(i,n)
		{
			REP(j,n)
			{
				if(s[i][j]=='1')
				{
					total[i]++;
					win[i]++;
				}
				else if(s[i][j]=='0')
				{
					total[i]++;
				}

			}
			if(total[i]==0)
				wp[i]=0;
			else
				wp[i]=1.0*win[i]/total[i];
		}


		//loop for owp
		
		REP(i,n)
		{
			int ctr=0,tot[110]={0},w[110]={0};
			REP(j,n)
			{
				if(s[i][j]!='.')
				{
					REP(k,n)
					{
						if(k==i)
							continue;
						if(s[j][k]=='1')
						{
							tot[ctr]++;
							w[ctr]++;
						}
						else if(s[j][k]=='0')
							tot[ctr]++;
					}
					if(tot[ctr])
						owp[i]+=(1.0*w[ctr]/tot[ctr]);
					ctr++;
				}
			}
			if(ctr)
				owp[i]/=ctr;
			else
				owp[i]=0;

		}


		//loop for oowp

		REP(i,n)
		{
			int ctr=0;
			REP(j,n)
			{
				if(s[i][j]!='.')
				{
					oowp[i]+=(1.0*owp[j]);
					ctr++;
				}
			}
			if(ctr)
				oowp[i]/=ctr;
			else
				oowp[i]=0;
		}

		printf("Case #%d:\n",test);
		REP(i,n)
		{
			double ans=0.25*wp[i]+0.5*owp[i]+0.25*oowp[i];
			printf("%.12lf\n",ans);
		}
	}
	return 0;
}
