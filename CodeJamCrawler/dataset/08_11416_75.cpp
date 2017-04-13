# include <stdio.h>
# include <string.h>
int n;
int ma[3][3]={
	{6,-4},
	{1,0},
};
int E[3][3]={
	{1,0},
	{0,1},
};
int n0[3]={6,2};

void cal(int m1[3][3],int m2[3][3],int m3[3][3])
{
	int i,j,k;
	memset(m3,0,sizeof(E));
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)	
		for(k=0;k<2;k++)
		{
			m3[i][j]+=m1[i][k]*m2[k][j];
			if(m3[i][j]>=1000)
				m3[i][j]%=1000;
			if(m3[i][j]<0)
				m3[i][j]+=1000;
		}
}

void cal2(int m1[3][3],int m2[3])	//multiply with n0[]
{
	int i,j;
	memset(m2,0,sizeof(n0));
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
	{
		m2[i]+=m1[i][j]*n0[j];
		if(m2[i]>=1000)
			m2[i]%=1000;
		if(m2[i]<0)
			m2[i]+=1000;
	}
}


void solve()
{
	n--;
	int temp1[3][3],temp2[3][3],nn[3],temp3[3][3];
	memcpy(temp1,E,sizeof(E));
	memcpy(temp3,ma,sizeof(E));
	while(n)
	{
		if(n&1)
		{
			cal(temp1,temp3,temp2);
			memcpy(temp1,temp2,sizeof(E));
		}
		cal(temp3,temp3,temp2);
		memcpy(temp3,temp2,sizeof(E));
		n>>=1;
	}
	cal2(temp1,nn);
	int res=nn[0]-1;
	res%=1000;
	if(res<0)
		res+=1000;
	printf("%03d\n",nn[0]-1);
}

int main()
{
	int T,i,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&n);
		printf("Case #%d: ",t);
		solve();
	}
	return 0;
}
