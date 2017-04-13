#include <fstream>

using namespace std;

int n,m;
int grid[50][50];
int cblue;

void replace(int x, int y)
{
	grid[x][y]=2;
	grid[x][y+1]=3;
	grid[x+1][y]=3;
	grid[x+1][y+1]=2;
}

bool check(int x, int y)
{
	return (grid[x][y]==1 && grid[x][y+1]==1 && grid[x+1][y]==1 && grid[x+1][y+1]==1);
}

bool solve()
{
	for(int i=0;i<n;i++)
	{
		for(int y=0;y<m;y++)
		{
			if(grid[i][y]==1)
			{
				if(check(i,y))
				{
					replace(i,y);
					cblue-=4;
				}else{
					return false;
				}
			}
		}
	}
	if(cblue==0)
	{
		return true;
	}
	return false;
}

int main()
{
	ifstream f("in.txt");
	ofstream f2("out.txt");


	int T;
	f>>T;

	for(int Case = 0; Case < T; Case++)
	{
		f>>n>>m;

		cblue = 0;

		char tc;
		for(int i=0;i<n;i++)
		{
			for(int y=0;y<m;y++)
			{
				f>>tc;
				if(tc=='.')
				{
					grid[i][y]=0;
				} else {
					grid[i][y]=1;
					cblue++;
				}
			}
		}
		if(cblue%4==0)
		{
			//solve
			bool rez = solve();
			if(rez)
			{
				f2<<"Case #"<<Case+1<<":"<<endl;
				for(int i=0;i<n;i++)
				{
					for(int y=0;y<m;y++)
					{
						if(grid[i][y]==0)
							f2<<".";
						if(grid[i][y]==2)
							f2<<"/";
						if(grid[i][y]==3)
							f2<<"\\";
					}
					f2<<endl;
				}
			} else {
				f2<<"Case #"<<Case+1<<":"<<endl;
				f2<<"Impossible"<<endl;
			}
		}else{
			f2<<"Case #"<<Case+1<<":"<<endl;
			f2<<"Impossible"<<endl;
		}
	}

	f.close();
	f2.close();
	return 0;
}