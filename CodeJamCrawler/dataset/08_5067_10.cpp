#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream.h>
inline double dis(int a,int b,int c,int d)
{
	return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}
inline double DIFF(double a,double b)
{
	if (fabs(a-b)<0.000000001) return 1;
	else return 0;
}

inline double BIGGER(double a,double b)
{
	if ((b-a)>0.0000001) return 1;
	else return 0;
}

inline double GETS(double a)
{
	if (fabs(a)<0.000000001) return 0;
	else return a;
}


int main()
{
	char ch[5000];
	int i,j,k,cas,CASNO;
	double square;
	int a[3],b[3],c[3],N,M,A;
	double ab,bc,ac,sum;
	int flag;

	freopen("B-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	//gets(ch); sscanf(ch,"%d",&CASNO);
	scanf("%d",&CASNO);
	for (cas=1;cas<=CASNO;cas++)
	{

		scanf("%d %d %d",&N,&M,&A);
		if (BIGGER( (double)N*(double)M/(double)2 , (double)A / (double)2)==1) { printf("Case #%d: IMPOSSIBLE\n",cas); continue; }
		for (a[1]=0;a[1]<=N;a[1]++)
		for (a[2]=0;a[2]<=M;a[2]++)
		for (b[1]=0;b[1]<=N;b[1]++)
		for (b[2]=0;b[2]<=M;b[2]++)
		for (c[1]=0;c[1]<=N;c[1]++)
		for (c[2]=0;c[2]<=M;c[2]++)
		{
			flag=0;
			if (a[1] == b[1] && a[2] == b[2] && a[1] == c[1] && a[2] == c[2] && b[1] == c[1] && b[2] == c[2]) continue;
			ab = dis(a[1],a[2],b[1],b[2]);
			bc = dis(b[1],b[2],c[1],c[2]);
			ac = dis(a[1],a[2],c[1],c[2]);
			sum = (ab+bc+ac)/2;
			square = sqrt(sum*GETS(sum-ab)*GETS(sum-bc)*GETS(sum-ac));

			if (DIFF(square,(double)A / (double)2)==1)
			{
				flag=1;
				printf("Case #%d: %d %d %d %d %d %d\n",cas,a[1],a[2],b[1],b[2],c[1],c[2]);
				goto top;
			}
		}
top:
		if (flag==0)	printf("Case #%d: IMPOSSIBLE\n",cas);


	}
	return 1;
}
	