#include<stdio.h>

int i,n,t,cs,O,B,wait,val,ans,f1,f2,dis;
char ch;
struct cell
{
	int Clr;
	int Btn;
};

cell robot[105];

int ABS(int a, int b)
{
	return (a>b)?(a-b):(b-a);
}

int main()
{
//	freopen("A-small-attempt0","r",stdin);
//	freopen("A.out","w",stdout);

	scanf("%d",&t);
	for(cs=1; cs<=t; cs++)
	{
		scanf("%d",&n);

		wait = ans = 0;
		B = O = 1;
		getchar();

		scanf("%c%d",&ch,&val);
		getchar();

		f1=f2=0;
		if(ch=='O')	
		{
			f1=1;
			wait = ABS(val,O) + 1;
			O = val;
			ans = wait;
		}
		else if(ch=='B')
		{

			f2=1;
			wait = ABS(val,B) + 1;
			B = val;
			ans = wait;

		}
		for(i=2; i<=n; i++)
		{
			scanf("%c%d",&ch,&val);
					getchar();

			if(ch=='O')
			{
				f2=0;
				if(f1==1)
				{
					wait = wait + ABS(val,O) + 1;
					ans = ans + ABS(val,O) + 1;
				}
				
				else{

				if(wait>=ABS(val,O))
				{
					ans = ans + 1;
					dis = 1;
				}
				else
				{
					dis =  ABS(val,O) + 1- wait;
					ans = ans + dis;
					
				}
				
				if(f1==0)
				{
					wait = dis;
					f1=1;
				}
				}
				O=val;
				
			}

			if(ch=='B')
			{
				f1=0;
				if(f2==1)
				{
					wait = wait + ABS(val,B) + 1;
					ans = ans + ABS(val,B) + 1;
				}
				
				else{

				if(wait>=ABS(val,B))
				{
					ans = ans + 1;
					dis = 1;
				}
				else
				{
					dis =  ABS(val,B) + 1 - wait;
					ans = ans + dis;
					
				}
				
				if(f2==0)
				{
					wait = dis;
					f2=1;
				}
				}
				B=val;
				
			}
		}

		printf("Case #%d: %d\n",cs,ans);
	}
	return 0;
}