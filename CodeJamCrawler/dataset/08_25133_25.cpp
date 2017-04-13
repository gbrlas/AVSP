#include<stdio.h>
__int64 c(__int64 x)
{
	if(x<3)return 0;
	return x*(x-1)*(x-2)/6;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A.out.txt","w",stdout);
	int pk,k;
	scanf("%d",&pk);
	for(k=1;k<=pk;k++)
	{	
		__int64 n,A,B,C,D,x0,y0,M;
		int i,j;
		__int64 X,Y;
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d",&n,&A,&B,&C,&D,&x0,&y0,&M);
		__int64 t[3][3]={0};
		X = x0, Y = y0;
		t[X%3][Y%3]++;
		for(i=1;i<n;i++)
		{
			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
			t[X%3][Y%3]++;
		}
		__int64 tot=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				tot+=c(t[i][j]);
			tot+=t[i][0]*t[i][1]*t[i][2];
		}
		for(i=0;i<3;i++)
			tot+=t[0][i]*t[1][i]*t[2][i];
		tot+=t[0][0]*t[1][1]*t[2][2];
		tot+=t[0][0]*t[1][2]*t[2][1];
		tot+=t[0][1]*t[1][0]*t[2][2];
		tot+=t[0][1]*t[1][2]*t[2][0];
		tot+=t[0][2]*t[1][0]*t[2][1];
		tot+=t[0][2]*t[1][1]*t[2][0];
		printf("Case #%d: %I64d\n",k,tot);
	}
	return 0;
}

