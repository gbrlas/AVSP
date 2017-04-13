#include<stdio.h>
int main()
{
	int n,s,p,t,arr[3][3],inp,i,count=0;
	scanf("%d",&t);
	int m=t;
	while(t--)
	{	count =0;
		scanf("%d %d %d",&n,&s,&p);
		int j=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&inp);
			if(p==0) {count++;}
			else if(p==1) {if(inp>=1) count++;}
			else	{
				if(inp>=(3*p-2)) count++;
				else if((inp>=(3*p-4))&&(s)) 
					{
					s--; count++;
					}
				}
		
		
		}
		/*
		for(i=0;i<n-s;i++)
		{
		arr[i][0]=inp[i]/3;
		arr[i][1]=inp[i]/3;
		arr[i][2]=inp[i]/3;
		if(inp[i]%3==1) arr[i][0]++;
		else if(inp[i]%3==2) {arr[i][0]++;arr[i][1]++;}
		
		if(arr[i][0]==p || arr[i][1]==p || arr[i][2]==p)
			count++;
		//printf("\n%d %d %d",arr[i][0],arr[i][1],arr[i][2]);*/
		printf("Case #%d: %d\n",m-t,count);
	}
	return 0;
}
