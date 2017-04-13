// gcj33.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std; 

int spe[1000005];
int main()
{
	freopen ( "A-large.in", "r", stdin );
	freopen ( "out1.out", "w",stdout);
	int turn,x,s,r,n;
	double t;
	int B[1005],E[1005],w[1005];
	scanf("%d",&turn);
	for(int tt=1;tt<=turn;tt++)
	{
		scanf("%d%d%d%lf%d",&x,&s,&r,&t,&n);
		for(int i=0;i<x;++i)
			spe[i] = s;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&B[i],&E[i],&w[i]);
			for(int j=B[i];j<E[i];++j)
				spe[j] += w[i];
		}
		sort(spe,spe+x);

		double res = 0;
		for(int i=0;i<x;++i)
		{
			if(r>s && t>0)
			{
				double tp = (double)1/(spe[i] + r - s);
				if(tp <= t) {res += tp;t-=tp;}
				else {res += t + ((double)1-t*(spe[i] + r - s))/spe[i];t-=tp;}
			}
			else
			res+=(double)1/spe[i];
		}

		printf("Case #%d: %.7f\n",tt,res);
		
	}
	return 0;
}

