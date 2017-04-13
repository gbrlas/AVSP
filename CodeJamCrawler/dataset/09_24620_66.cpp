#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	fstream fin("B-large.in");
	fstream fout("out.txt",fstream::out);
	int times=0,h=0,w=0;
	fin>>times;
	for(int i = 1;i<=times;i++) 
	{
		fin>>h;
		fin>>w;
		vector < vector<int> > field (w, vector<int> (h));
		for(int y=0;y<h;y++){
			for(int x=0;x<w;x++)
			{
				fin >> field[x][y];
			}
		}
		vector < vector<char> > sol (w, vector<char> (h,'-'));
		int pos[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
		char let = 'a'-1;
		queue<int> q;
		bool finished = false;
		while(!finished)
		{
			for(int y=0;y<h;y++)
				for(int x=0;x<w;x++)
				{
					if(sol[x][y]=='-')
					{
						q.push(x);
						q.push(y);
					}
				}
			if(!q.empty())
			{
				int x = q.front();
				q.pop();
				int y = q.front();
				q.pop();
				let++;
				sol[x][y]=let;
				bool finish = false;
				while(!finish)
				{
					if(q.empty())
						finish =true;
					int nx=x, ny=y,px=-1,py=-1;
					while(nx!=px || ny!=py)
					{
						px=nx;
						py=ny;
						int v = field[px][py];
						for(int i=0;i<4;i++)
						{
							int tx = px+pos[i][0];
							int ty = py+pos[i][1];
							if(tx>=0 && tx<w && ty>=0 && ty<h 
								&& field[tx][ty]<=v && field[px][py]!=field[tx][ty])
							{
								v = field[tx][ty];
								nx=tx;
								ny=ty;
							}
						}
					}
					if(sol[x][y]!='-')
						sol[nx][ny] = sol[x][y];
					if(sol[nx][ny]!='-')
						sol[x][y] = sol[nx][ny];
					if(!finish)
					{
						x = q.front();
						q.pop();
						y = q.front();
						q.pop();
					}
				}
			}
			else
				finished = true;
		}
		fout<<"Case #"<<i<<":\n";
		for(int y=0;y<h;y++)
		{
			for(int x=0;x<w;x++)
				fout<<sol[x][y]<<" ";
			fout<<endl;
		}
	}
	return 0;
}