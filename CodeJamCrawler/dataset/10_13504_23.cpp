#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

#define MAX(a,b,c,d) max(max(a,b),max(a,b))

//bool useif[55][55];
vector<vector<char> > data;
char now;
int N,K;
int way[4][2]={1,-1,1,0,1,1,0,1};
map<char,bool> rp;

bool in(int i,int j)
{
	if(i>=0 && i<N && j>=0 && j<N)
		return true;
	return false;
}

int dfs(int i,int j,int k,int m)
{
	if(k>=K)
		return K;
    if (in(i,j) && data[i][j]==now)
    {
        return dfs(i+way[m][0],j+way[m][1],k+1,m);
    }
	else
		return k;
}

void solve()
{
	/*
	for (int i=0;i<55;i++)
	{
		memset(useif[i],0,55*sizeof(bool));
	}*/
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			int len=0;
			if(data[i][j]!='.')
			{
				now=data[i][j];
				for(int m=0;m<4;m++)
				len=max(len,dfs(i+way[m][0],j+way[m][1],1,m));			
			}
			if(len>=K)
				rp[now]=true;

		}

	}

}

int main()
{
	ifstream fin("A-large.in");
	ofstream fout("out.txt");
	int T;
	fin>>T;
	for(int i=0;i<T;i++)
	{
        fin>>N>>K;
		data.clear();
		rp['R']=false;
		rp['B']=false;
		data.assign(N,vector<char>(N,0));
		for (int j=0;j<N;j++)
		    for (int k=0;k<N;k++)
				fin>>data[j][k];
		for (int j=0;j<N;j++)
		{
			int k=N-1;
			int t=N-1;
			while (k>=0)
			{
				if(data[j][k]!='.')
				{
					if(t>k)
					{
						data[j][t]=data[j][k];
						data[j][k]='.';
					}
					t--;
				}
				k--;
			}
		}
		solve();
		if(!rp['R'] && !rp['B'])
		{
            fout<<"Case #"<<(i+1)<<": "<<"Neither"<<endl;
			continue;
		}
		if(rp['R'] && rp['B'])
		{
			fout<<"Case #"<<(i+1)<<": "<<"Both"<<endl;
			continue;
		}
		if(rp['R'] && !rp['B'])
		{
			     fout<<"Case #"<<(i+1)<<": "<<"Red"<<endl;
				 continue;
		}
		if(!rp['R'] && rp['B'])
		{
                 fout<<"Case #"<<(i+1)<<": "<<"Blue"<<endl;
				 continue;
		}
	}
	//cin.get();
	return 0;
}