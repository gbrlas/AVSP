#include<iostream.h>
#include<conio.h>

using namespace std;

int main()
{
	int t,i,pd,pg,j,flag;
	double n;
	freopen("A-large.in","rt",stdin);
	freopen("A-large-out","wt",stdout);
	cin>>t;
	for(i=0;i<t;i++)
	{	flag=0;
		cin>>n>>pd>>pg;
		for(j=1;j<=n;j++)
		{
			int k;
			for(k=0;k<=j;k++)
			{
				if(((k*100.0)/j)==pd)
				{
					flag=1;
					goto x;
				}
			}
		}
		x:
		if(flag==1&&((pd==100||pg<100)))
		{
			if(pg==0&&pd!=0)
			goto y;
			cout<<"Case #"<<i+1<<": Possible\n";
	
		}
		else
		{
			y:
			cout<<"Case #"<<i+1<<": Broken\n";
		}
}
	
	//getch();
	return 0;
}

	
				
