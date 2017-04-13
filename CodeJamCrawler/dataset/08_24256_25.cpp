#include <stdio.h>
#include <string.h>

int nums = 0;
int numq = 0;
char recordlast[100];

struct node
{
	char name[100];
	int n;
};
node S[100];
char Q[100][100];
int count = 0;
int result;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int numtest = 0;
	
	scanf("%d",&numtest);
	for(int i = 0;i < numtest;++i)
	{
		scanf("%d",&nums);
		gets(S[0].name);
		for(int j = 0; j< nums; ++j)
		{
			gets(S[j].name);
		}
		
		for(j=0;j<nums;++j)
		{
			S[j].n = 0;
		}
		
		scanf("%d",&numq);
		gets(Q[0]);
		//存放数据
		for(j =0; j < numq; ++j)
		{
			gets(Q[j]);
		}
		int temp;
		for(j = 0; j < numq;++j)
		{
			//对应计数器加
			for(int h = 0;h<nums;++h)
			{
				if(strcmp(Q[j],S[h].name) ==0)
				{
					S[h].n++;
					temp = h;
				}
			}
			count = 0;
			//查找为0的
			for(int k = 0; k<nums;k++)
			{
				if(S[k].n == 0)
				{
					count++;
					temp = k;
				}
			}
			
			//计数为0
			if(count == 0)
			{
				result++;
				for(int t = 0; t < nums; t++)
				{
					S[t].n = 0;
					if(t == temp)
					{
						S[t].n = 999999;
					}
				}
			}
			if(j == numq-1)
			{
				printf("Case #%d: %d\n",i+1,result);
			}
		}

		if(numq == 0)
        {
            printf("Case #%d: %d\n",i+1,result);
        }
		result = 0;
        for(int t = 0; t < nums; t++)
        {
            S[t].n = 0;
        }
	}
	return 0;
}



/*if(flag == nums-1)
{
//找到最后一个不为0的数据
for(int i =0; i<nums;++i)
{
if(S[i].n == 0)
{
strcpy(recordlast,S[i].name);
}
}
//找到数据的位置
int recordnowsearch;
for(i = 0;i<numq;++i)
{
if(strcmp(Q[i],recordlast) == 0)
{
recordnowsearch = i;
break;
}
}
		}*/