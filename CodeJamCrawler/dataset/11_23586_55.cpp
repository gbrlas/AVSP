#include<stdio.h>
int main()
{
	int i,j,t,n,seq[100],step;
	char ch[100];
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf(" %c %d",&ch[i],&seq[i]);
		int pre1=1,pre2=1,t1=0,t2=0,temp;
		for(i=0,step=0;i<n;i++)
		{
			if(ch[i]=='O')
			{
				temp=seq[i]-pre1;
				if(temp<0)
					temp=-temp;
				if(t1<t2)
				{
					temp-=t2-t1;
					if(temp<0)
						temp=0;
				}
				step+=temp+1;
				pre1=seq[i];
				t1=step;
			}
			else
			{
				temp=seq[i]-pre2;
				if(temp<0)
					temp=-temp;
				if(t2<t1)
				{
					temp-=t1-t2;
					if(temp<0)
						temp=0;
				}
				step+=temp+1;
				pre2=seq[i];
				t2=step;
			}
		}
		printf("Case #%d: %d\n",j,step);
	}
	return 0;
}
