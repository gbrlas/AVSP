#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag[105];
char sea[105][105];
char que[1005][105];

int cek(int s,int q,int tan)
{
	int i,j,k,max,temp;
	max=0;
	for(j=0;j<s;j++)
	{
		for(k=tan;k<q;k++)
		{
			if(strcmp(sea[j],que[k])==0)break;
		}
		flag[j]=k;	
		if(flag[j]>max)
		{
			max=flag[j];
		
		}	
	}
	
	return max;
}
int main()
{
	int n,tan,jum;
	int i,j,k,l;
	int s,q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d\n",&s);
		for(j=0;j<s;j++)
		{
			gets(sea[j]);
		}
		scanf("%d\n",&q);
		for(j=0;j<q;j++)
		{
			gets(que[j]);
		}
		tan=0;jum=0;
		do{
			tan=cek(s,q,tan);
			jum++;
		}while(tan<q);
		printf("Case #%d: %d\n",i+1,jum-1);
		
	}
	return 0;
}
