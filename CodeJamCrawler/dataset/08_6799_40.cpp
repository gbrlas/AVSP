#include	<cstdio>
#include	<iostream>
#include	<vector>
#include	<string>
#include	<cmath>
#include	<algorithm>
#include	<conio.h>
#include	<windows.h>

using namespace std;

bool satisfied[2000];
int fs[2000][2];
int state[2000];
vector < vector < pair <int,int > > > f;
vector < pair <int,int> > in;

int satisfy(int num)
{
	satisfied[num]=true;
	for(int x=0;x<f[num].size();x++)
	{
		fs[f[num][x].first][f[num][x].second]--;
	}
	return 0;
}

int main()
{
	int c,d;
	cin >> c;
	for(d=0;d<c;d++)
	{
		int n,m,t;
		int x,y;
		bool impossible;
		impossible=false;
		cin >> n;
		cin >> m;

		memset(satisfied,false,sizeof(satisfied));
		memset(fs,0,sizeof(fs));
		memset(state,0,sizeof(state));
		f.clear();

		for(x=0;x<m;x++)
		{
			cin >> t;
			in.clear();
			for(y=0;y<t;y++)
			{
				int p,q;
				cin >> p >> q; p--;
				in.push_back(make_pair(p,q));
				fs[p][q]++;
			}
			f.push_back(in);
		}

		for(x=0;x<m && impossible==false;x++)
		{
			bool flag=true;
			for(y=0;y<f[x].size() && flag;y++)
			{
				if(state[f[x][y].first]==f[x][y].second) flag=false;
			}
			if(flag)
			{
				bool f2=true;
				for(y=0;y<f[x].size() && f2;y++)
				{
					if(f[x][y].second==1)
					{
						state[f[x][y].first]=1;
						f2=false;
						x=-1;
					}
				}
				if(f2) impossible=true;
			}
		}

		if(impossible) 	cout << "Case #" << d+1 << ": "<< "IMPOSSIBLE" << endl;
		else
		{
			cout << "Case #" << d+1 << ": ";
			for(x=0;x<n;x++)
			{
				cout << state[x] << " ";
			}
			puts("");
		}
	}
	getch();
	return 0;
}
