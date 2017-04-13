#include<stdio.h>
int numberofmax(int *surp,int *norm,int p,int num,int sur);
void main()
{
	int runs=0;
	int num=0;
	int sur=0;
	int lim=0;
	scanf("%d",&runs);
	int* result = malloc(runs*sizeof(int));
	int tempr=runs;
	while(runs>0)
	{
		int i=0;
		scanf("%d %d %d",&num,&sur,&lim);
		int *inp = malloc(num*sizeof(int));
		for(i=0;i<num;i++)
			scanf("%d",&inp[i]);
		int *norm = malloc(num*sizeof(int));
		int *surp = malloc(num*sizeof(int));
		
		for(i=0;i<num;i++)
		{
			if(inp[i]==0)
			{
				norm[i]=0;
				surp[i]=0;
				
			}
			else
			{	
			if(inp[i]%3==0)
			{
				norm[i] = inp[i]/3;
				surp[i] = inp[i]/3+1;
			}
			else if(inp[i]%3==1)
			{
				norm[i] = inp[i]/3+1;
				surp[i] = inp[i]/3+1;
			}
			else
			{
				norm[i] = inp[i]/3+1;
				surp[i] = inp[i]/3+2;
			}
			}
		}
		
			result[tempr-runs] = numberofmax(surp,norm,lim,num,sur);
			runs--;
	}
	
	int i=0;
	for(i=0;i<tempr;i++)
	{
		printf("Case #%d: %d\n",i+1,result[i]);
	}
}
int numberofmax(int *surp,int *norm,int p,int num,int sur)
{
	int i=0;
	int count=0;
	int max=0;
	if(sur==0)
	{
		for(i=0;i<num;i++)
		{
			if(norm[i]>=p)
				count++;
		}
		return count;
	}
	else if(sur==1)
	{
		//printf("Here\n");
		for(i=0;i<num;i++)
		{
			if(i==0)
			{
				if(surp[i]>=p)
					count++;
				continue;
			}
			if(norm[i]>=p)
				count++;
		}
		//printf("%d\n",count);
		if(max<count)
			max = count;
		count=0;
		for(i=0;i<num;i++)
		{
			if(i==1)
			{
				if(surp[i]>=p)
					count++;
				continue;
			}
			if(norm[i]>=p)
				count++;
		}
		if(max<count)
			max = count;
		count=0;
		if(num==3)
		{
		for(i=0;i<num;i++)
		{
			if(i==2)
			{
				if(surp[i]>=p)
					count++;
				continue;
			}
			if(norm[i]>=p)
				count++;
		}
		if(max<count)
			max = count;
		}
		
		return max;
	}
	else
	{
		for(i=0;i<num;i++)
		{
			if(i==0)
			{
				if(norm[i]>=p)
					count++;
				continue;
			}
			if(surp[i]>=p)
				count++;
		}
		if(max<count)
			max = count;
		count=0;
		for(i=0;i<num;i++)
		{
			if(i==1)
			{
				if(norm[i]>=p)
					count++;
				continue;
			}
			if(surp[i]>=p)
				count++;
		}
		if(max<count)
			max = count;
		count=0;
		if(num==3)
		{
		for(i=0;i<num;i++)
		{
			if(i==2)
			{
				if(norm[i]>=p)
					count++;
				continue;
			}
			if(surp[i]>=p)
				count++;
		}
		if(max<count)
			max = count;
		}
		
		return max;
	}
}
		
				
	
		

				
		
