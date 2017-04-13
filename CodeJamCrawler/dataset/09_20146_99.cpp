#include<iostream>
using namespace std;
main()
{
	int n;
	cin>>n;
	int v=0;
	int x,y;
	int cnt=0,mini,prx,pry;
		int lastx=-1,lasty=-1,num=0;
	while(n--)
	{
		num++;
		cout<<"Case #"<<num<<":"<<endl;
		cnt=0;
		v++;
		cin>>x>>y;
		int ar[x][y];
		char sink[x][y];
		for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
		{
			cin>>ar[i][j];
			sink[i][j]=':';
		}
		int lastx,lasty;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				lastx=i;
				lasty=j;
				mini=ar[i][j];
			//	mini--;
				prx=i;
				pry=j;
				while(1)
				{
					mini--;
					//prx=ar[lastx;
					if(lastx!=x-1&&ar[lastx+1][lasty]<=mini)
					{
						mini=ar[lastx+1][lasty];
						prx=lastx+1;
						pry=lasty;
					}
					if(lasty!=y-1&&ar[lastx][lasty+1]<=mini)
					{
						mini=ar[lastx][lasty+1];
						prx=lastx;
						pry=lasty+1;
					}
					if(lasty!=0&&ar[lastx][lasty-1]<=mini)
					{
						mini=ar[lastx][lasty-1];
						prx=lastx;
						pry=lasty-1;
					}
					if(lastx!=0&&ar[lastx-1][lasty]<=mini)
					{
						mini=ar[lastx-1][lasty];
						prx=lastx-1;
						pry=lasty;
					}
					if(lastx==prx&&lasty==pry)
					{
						if(sink[prx][pry]==':')
						{
							sink[prx][pry]='a'+cnt;
							cnt++;
						}

						cout<<sink[prx][pry];
						if(j>=y-1)
							cout<<endl;
						else cout<<" ";
						break;
					}
					else
					{
						lastx=prx;
						lasty=pry;
					}

				}
			}
		}
	}
}
		



