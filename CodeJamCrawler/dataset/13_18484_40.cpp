#include <iostream>

using namespace std;
int main()
{
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small-attempt0.out","wt",stdout);

	int T;
	cin>>T;

	for(int i=1;i<=T;i++)
	{
		char arr[16];
		for(int iter=0;iter<16;iter++)
		{
			cin>>arr[iter];
		}

		bool isempty=false;
		int isdraw=0;
		for(int r=0;r<4;r++)
		{
			int xw=0;
			int ow=0;
			int tw=0;
			for(int c=0;c<4;c++)
			{
				char tmp=arr[r*4+c];
				if(tmp=='X')
				{
					xw++;
				}
				else if(tmp=='O')
				{
					ow++;
				}
				else if(tmp=='T')
				{
					tw++;
				}
				else
				{
					isempty=true;
				}
			}
			if(xw>3)
			{
				isdraw=1;
				break;
			}
			else if((xw==3)&&(tw==1))
			{
				isdraw=1;
				break;
			}
			if(ow>3)
			{
				isdraw=-1;
				break;
			}
			else if((ow==3)&&(tw==1))
			{
				isdraw=-1;
				break;
			}
		}

		if(isdraw==0)
		{
			for(int c=0;c<4;c++)
			{
				int xw=0;
				int ow=0;
				int tw=0;
				for(int r=0;r<4;r++)
				{
					char tmp=arr[r*4+c];
					if(tmp=='X')
					{
						xw++;
					}
					else if(tmp=='O')
					{
						ow++;
					}
					else if(tmp=='T')
					{
						tw++;
					}
					else
					{
						isempty=true;
					}
				}
				if(xw>3)
				{
					isdraw=1;
					break;
				}
				else if((xw==3)&&(tw==1))
				{
					isdraw=1;
					break;
				}
				if(ow>3)
				{
					isdraw=-1;
					break;
				}
				else if((ow==3)&&(tw==1))
				{
					isdraw=-1;
					break;
				}
			}
		}

		if(isdraw==0)
		{
			int xw=0;
			int ow=0;
			int tw=0;
			for(int m=0;m<4;m++)
			{
				char tmp=arr[m*4+m];
				if(tmp=='X')
				{
					xw++;
				}
				else if(tmp=='O')
				{
					ow++;
				}
				else if(tmp=='T')
				{
					tw++;
				}
				else
				{
					isempty=true;
				}
			}
			if(xw>3)
			{
				isdraw=1;
			}
			else if((xw==3)&&(tw==1))
			{
				isdraw=1;
			}
			if(ow>3)
			{
				isdraw=-1;
			}
			else if((ow==3)&&(tw==1))
			{
				isdraw=-1;
			}
		}

		if(isdraw==0)
		{
			int xw=0;
			int ow=0;
			int tw=0;
			for(int m=0;m<4;m++)
			{
				char tmp=arr[m*4+3-m];
				if(tmp=='X')
				{
					xw++;
				}
				else if(tmp=='O')
				{
					ow++;
				}
				else if(tmp=='T')
				{
					tw++;
				}
				else
				{
					isempty=true;
				}
			}
			if(xw>3)
			{
				isdraw=1;
			}
			else if((xw==3)&&(tw==1))
			{
				isdraw=1;
			}
			if(ow>3)
			{
				isdraw=-1;
			}
			else if((ow==3)&&(tw==1))
			{
				isdraw=-1;
			}
		}

		cout<<"Case #"<<i<<": ";
		if(isdraw>0)
		{
			cout<<"X won"<<endl;
		}
		else if(isdraw<0)
		{
			cout<<"O won"<<endl;
		}
		else if(isempty)
		{
			cout<<"Game has not completed"<<endl;
		}
		else
		{
			cout<<"Draw"<<endl;
		}
	}
	return 0;
}