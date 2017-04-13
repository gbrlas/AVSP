#include<stdio.h>
#include<stdlib.h>
int main()
{////
	FILE *fp,*op;
	fp=fopen("A-small-attempt1.in","r");
	op=fopen("output.txt","w");
	int i,j,k,t,T,r,count=0,ans;
	fscanf(fp,"%d",&T);
//	scanf("%d",&T);
	while(count<T)
	{
		ans=0;
		fscanf(fp,"%d%d",&r,&t);
//		scanf("%d%d",&r,&t);
		/*
		if(r==1)
		{	fprintf(op,"Case #%d: 1\n",count+1);
			count++;
			continue;
		}*/
		for(i=r+1;(t-=(i*i-(i-1)*(i-1)))>=0;i+=2)
		{
			ans++;
		}
		fprintf(op,"Case #%d: %d\n",count+1,ans);
	//	printf("Case #%d: %d\n",count+1,ans);
		count++;
	}
}