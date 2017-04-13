#include<iostream.h>
#include<conio.h>

int main()
{
	int t,r,c,i,j,k,flag,b,d[6][6];
	char a[6][6];
	freopen("A-small-attempt1.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
	cin>>t;
	for(i=0;i<t;i++)
	{	
		flag=1;
		cin>>r>>c;
		b=0;
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				cin>>a[j][k];
				if(a[j][k]=='#')
				{
					b++;
					d[j][k]=1;
				}
				else
				d[j][k]=0;
			}
		}
		if(b%4!=0)
		{
			flag=0;
			goto end;
		}
		else
		{
			for(j=0;j<r-1;j++)
			{
				for(k=0;k<c-1;k++)
				{
					if(d[j][k]==1)
					{
						if(d[j+1][k]!=1||d[j][k+1]!=1||d[j+1][k+1]!=1)
						{
							flag=0;
							goto end;
						}
						else
						{
							d[j][k]=d[j+1][k]=d[j][k+1]=d[j+1][k+1]=0;
							a[j][k]='/';
							a[j+1][k+1]='/';
							a[j+1][k]='\\';
							a[j][k+1]='\\';
						}
					}
				}
			}
		}
		end:
		cout<<"Case #"<<i+1<<":\n";
		if(flag==0)
		cout<<"Impossible\n";	
		else
		{
			for(j=0;j<r;j++)
			{
				for(k=0;k<c;k++)
				{
					cout<<a[j][k];
				
				}
				cout<<"\n";
			}
		}
	}
	getch();
	return 0;
}	
