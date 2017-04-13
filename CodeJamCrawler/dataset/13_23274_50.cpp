#include<iostream>
using namespace std;
int main()
{
    int x,o,t;
	int flag;bool uc;
	char arr[4][4];
	int test;
	
	cin>>test;
	int c;
	for(c=0;c<test;c++)
	{
		flag=0;
		uc=false;
		
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) cin>>arr[i][j];
		
	
		//row
		for(int i=0;i<4;i++)
		{
			x=0;
			o=0;
			t=0;
			for(int j=0;j<4;j++)
			{
				x+=(arr[i][j]=='X')?1:0;
				o+=(arr[i][j]=='O')?1:0;
				t+=(arr[i][j]=='T')?1:0;
				if(arr[i][j]=='.')
					uc=true;
			}
			if(x+t==4)
			{
				cout<<"Case #"<<(c+1)<<": X won"<<endl;
				flag=1;break;
			}
			if(o+t==4)
			{
				cout<<"Case #"<<(c+1)<<": O won"<<endl;
				flag=1;break;
			}
			
		}
			
	
		//column
		for(int i=0; i<4 && flag!=1 ;i++)
		{
			x=0;
			o=0;
			t=0;
			for(int j=0;j<4;j++)
			{
				x+=(arr[j][i]=='X')?1:0;
				o+=(arr[j][i]=='O')?1:0;
				t+=(arr[j][i]=='T')?1:0;
			}
			if(x+t==4)
			{
				cout<<"Case #"<<(c+1)<<": X won"<<endl;
				flag=1;break;
			}
			if(o+t==4)
			{
				cout<<"Case #"<<(c+1)<<": O won"<<endl;
				flag=1;break;
			}
			
		}
			
			
		//first diagonal
			x=0;
			o=0;
			t=0;
			for(int j=0;j<4 && flag!=1;j++)
			{
				x+=(arr[j][j]=='X')?1:0;
				o+=(arr[j][j]=='O')?1:0;
				t+=(arr[j][j]=='T')?1:0;
			}
			if(x+t==4)
			{
				cout<<"Case #"<<(c+1)<<": X won"<<endl;
				flag=1;
			}
			if(o+t==4)
			{
				cout<<"Case #"<<(c+1)<<": O won"<<endl;
				flag=1;
			}
			
		//second diagonal
			x=0;
			o=0;
			t=0;
			for(int j=0;j<4 && flag!=1;j++)
			{
				x+=(arr[j][3-j]=='X')?1:0;
				o+=(arr[j][3-j]=='O')?1:0;
				t+=(arr[j][3-j]=='T')?1:0;
			}
			if(x+t==4)
			{
				cout<<"Case #"<<(c+1)<<": X won"<<endl;
				flag=1;
			}
			if(o+t==4)
			{
				cout<<"Case #"<<(c+1)<<": O won"<<endl;
				flag=1;
		
			}
			
			//no one won
			if(uc && flag!=1)
			{
				cout<<"Case #"<<(c+1)<<": Game has not completed"<<endl;
				flag=1;
			}
			
			if(flag!=1)
				cout<<"Case #"<<(c+1)<<": Draw"<<endl;
	
	}	  
	return 0;
}
