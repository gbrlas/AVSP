#include<stdio.h>
#include<string.h>
#include<math.h>
int a[10000];
int temp[10000];
int b[1001];
int pc=0;
int was[100001];
void getprime()
{
	for(int i=2;i<=1000;i++)
	{
		if(temp[i]==0)
		{
			a[pc++]=i;
			for(int j=i*i;j<=1000;j+=i)
				temp[j]=1;
		}
	}
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("hi.txt","w",stdout);
	getprime();
	int c,ka=1;
	int i,j;
	scanf("%d",&c);
	while(ka<=c)
	{
		int aa,bb,p;
		memset(was,0,sizeof(was));
		scanf("%d%d%d",&aa,&bb,&p);
		for(i=aa;i<=bb;i++)
			b[i]=i;
		for(i=0;i<pc;i++)
		{
			if(a[i]>=p)
				break;
		}
		for(j=i;j<pc;j++)
		{
			if(a[j]>bb)
				break;
			for(int k=aa;k<=bb;k++)
			{
				for(int kk=aa+1;kk<=bb;kk++)
				{
					if(k%a[j]==0&&kk%a[j]==0)
					{
						if(b[k]<b[kk])
						{
							int tt=b[kk];
							for(int ki=aa;ki<=bb;ki++)
							{
								if(tt==b[ki])
						    	b[ki]=b[k];
							}
						}
						else
						{
							int tt=b[k];
							for(int ki=aa;ki<=bb;ki++)
							{
								if(tt==b[ki])
						    	b[ki]=b[kk];
							}
						}
					}
				}
			}
		}
		int s=0;
		for(i=aa;i<=bb;i++)
		{
			if(was[b[i]]==0)
			{
				was[b[i]]=1;
				s++;
			}
		}
		printf("Case #%d: %d\n",ka,s);
		ka++;
	}

}