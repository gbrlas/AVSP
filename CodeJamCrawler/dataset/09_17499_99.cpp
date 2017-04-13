#include <iostream>
#include <fstream>
using namespace std;

int area[100][100];
char res[100][100];
char ch;

void calc(int x,int y)
{
	if (res[x][y]!='*') return;
	int dx=0;
	int dy=0;
	if (area[x+dx][y+dy]>area[x][y-1])
	{
		dx=0;
		dy=-1;
	} 
	if (area[x+dx][y+dy]>area[x-1][y])
	{
		dx=-1;
		dy=0;
	} 
	if (area[x+dx][y+dy]>area[x+1][y])
	{
		dx=+1;
		dy=0;
	} 
	if (area[x+dx][y+dy]>area[x][y+1])
	{
		dx=0;
		dy=1;
	}
	
	if (dx==0 && dy==0)
	{
		ch++;
		res[x][y]=ch;
	} else
	{
		calc(x+dx,y+dy);
		res[x][y]= res[x+dx][y+dy];
	}



}



int main()
{
	int n,i,h,w;

	ifstream fin;
	ofstream fout;
	fin.open ("input.txt");
	fout.open ("output.txt");
	

	fin>> n;
	for (int i=0;i<n;i++ )
	{
		ch='a'-1;
		fin>> h>> w;
		for (int x=0; x<=w; x++){ area[x][0] = 10001; area[x][h+1] = 10001;	}
		for (int y=0; y<=h; y++){ area[0][y] = 10001; area[w+1][y]	= 10001;	}
		
			
		for (int y=1; y<=h; y++)
			for(int x=1; x<=w; x++)
			{
				fin>>area[x][y];
				res[x][y]='*';
			}

		for (int y=1; y<=h; y++)
			for(int x=1; x<=w; x++)
				if (res[x][y]=='*')
					calc(x,y);

		fout<<"Case #"<<i+1<<":"<<endl;
		for (int y=1; y<=h; y++)
		{
			for(int x=1; x<=w; x++)
				fout<<res[x][y]<<" ";
			fout<<endl;
		}

	}





	fout.close();
	fin.close();
	return 0;
}