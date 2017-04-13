#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int N;
int R[105];
int P[105];
int O[105];
int B[105];
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small-attempt0.out","w",stdout);
	int T,i,Case=0;
	char r;int p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		O[0]=B[0]=0;
		for(i=0;i<N;i++)
		{
			scanf(" %c%d",&r,&p);
			if(r=='O')
				R[i]=1;
			else
				R[i]=0;
			P[i]=p;
			if(R[i]==0)
				B[++B[0]]=p;
			else
				O[++O[0]]=p;
		}
		int op=1,bp=1;
		int no=0,nb=0;
		int step;
		int all=0;
		for(i=0;i<N;i++)
		{
			if(R[i]==0)
			{
				step=abs(bp-P[i])+1;
				all+=step;
				bp=P[i];nb++;
				if(abs(O[no+1]-op)<=step)
					op=O[no+1];
				else
					op=(op>O[no+1]?op-step:op+step);
			}
			else
			{
				step=abs(op-P[i])+1;
				all+=step;
				op=P[i];no++;
				if(abs(B[nb+1]-bp)<=step)
					bp=B[nb+1];
				else
					bp=(bp>B[nb+1]?bp-step:bp+step);
			}
		}
		printf("Case #%d: %d\n",++Case,all);
	}
	return 0;
}