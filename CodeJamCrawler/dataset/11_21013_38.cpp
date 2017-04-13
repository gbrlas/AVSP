#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int box[501][501];
int Addx[501][501],Addy[501][501];
int Add[501][501];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-ans-small313.txt","w",stdout);

	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int R,C,D;
		cin>>R>>C>>D;
		for(int j=1;j<=R;j++)
		{
			string s;
			cin>>s;
			for(int k=1;k<=C;k++)
			{
				box[j][k]=s[k-1]-'0';
			}
		}
		int EPS=0.0000000001;
		int bigg=0;
		memset(Addx,0,sizeof(Addx));
		memset(Addy,0,sizeof(Addy));
		memset(Add,0,sizeof(Add));
		for(int row=1;row<=R;row++)
		{
			
			for(int col=1;col<=C;col++)
			{
				Add[row][col]=Add[row-1][col-1];
				Addx[row][col]=Addx[row-1][col-1];
				Addy[row][col]=Addy[row-1][col-1];
				for(int ti=1;ti<=col;ti++)
				{
					Addx[row][col]+=box[row][ti]*row;
					Addy[row][col]+=box[row][ti]*ti;
					Add[row][col]+=box[row][ti];
				}
				for(int tj=1;tj<row;tj++)
				{
					Addx[row][col]+=box[tj][col]*tj;
					Addy[row][col]+=box[tj][col]*col;
					Add[row][col]+=box[tj][col];
				}
			}
		}
		
		for(int len=3;len<=min(R,C);len++)
		{
			for(int row=1;row<=R-len+1;row++)
			{
				for(int col=1;col<=C-len+1;col++)
				{
					//row,row+len-1;  col,col+len-1
					int veryallx=Addx[row+len-1][col+len-1]-Addx[row-1][col+len-1]-Addx[row+len-1][col-1]+Addx[row-1][col-1];
					int veryally=Addy[row+len-1][col+len-1]-Addy[row-1][col+len-1]-Addy[row+len-1][col-1]+Addy[row-1][col-1];
					veryallx-=box[row][col]*row+box[row][col+len-1]*row+box[row+len-1][col]*(row+len-1)+box[row+len-1][col+len-1]*(row+len-1);
					veryally-=box[row][col]*col+box[row][col+len-1]*(col+len-1)+box[row+len-1][col]*(col)+box[row+len-1][col+len-1]*(col+len-1);
					int Addall=Add[row+len-1][col+len-1]-Add[row-1][col+len-1]-Add[row+len-1][col-1]+Add[row-1][col-1];
					Addall-=box[row][col]+box[row][col+len-1]+box[row+len-1][col]+box[row+len-1][col+len-1];
					if(veryallx*2==Addall*(row+row+len-1)&&veryally*2==Addall*(col+col+len-1))
					{
							//if(i==14&&bigg>=9)
							bigg=len;
							
					}
				}
			}
		}
		cout<<"Case #"<<i<<": ";
		if(bigg==0)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<bigg<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}