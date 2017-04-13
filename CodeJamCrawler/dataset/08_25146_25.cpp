#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char str[1009];
char ns[1009];
int perm[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
//int perm[4]={2,0,3,1};
int main()
{
	int pk;
	int j;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small.txt","w",stdout);
	scanf("%d",&pk);
	for(j=1;j<=pk;j++)
	{
		int k;
		scanf("%d",&k);
		scanf("%s",str);
		int len=strlen(str);
		int i;
		int min=0x7FFFFF;
		do
		{
			for(i=0;i<len;i++)
				ns[i]=str[i-i%k+perm[i%k]];
			//printf("%s\n",ns);
			int tot=1;
			for(i=1;i<len;i++)
				if(ns[i]!=ns[i-1])
					tot++;

			if(tot<min)min=tot;

		}
		while(next_permutation(perm,perm+k));
		printf("Case #%d: ",j);
		printf("%d\n",min);
	}
	return 0;
}