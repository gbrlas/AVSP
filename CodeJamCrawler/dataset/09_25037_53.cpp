#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); ++(i))
#define all(a) (a).begin(),(a).end()
#define INF 100000
int alt[100][100];
int store[100][100];
int m,n;
int d1[]={-1,0,0,1};
int d2[]={0,-1,1,0};
int glob;

int dfs(int x,int y)
{
	if(store[x][y]!=-1) return store[x][y];
	int mini=INF;
	int finali=-1,finalj=-1;
	FOR(r,0,4)
	{
		if( (x+d1[r]<m) && (x+d1[r]>=0) && (y+d2[r]>=0) && (y+d2[r]<n) )
		{
			if(alt[x+d1[r]][y+d2[r]]<mini)
			{
				mini=alt[x+d1[r]][y+d2[r]];
				finali=x+d1[r];
				finalj=y+d2[r];
			}
		}
	}
	if(mini>=alt[x][y]){finali=-1;finalj=-1;}
	if(finali==-1 && finalj==-1)
	{
		if(store[x][y]==-1)
		{
			store[x][y]=glob;
			glob++;
		}
		return store[x][y];
	}
	else
	{
		store[x][y]=dfs(finali,finalj);
		return store[x][y];
	}
}

int main()
{
	ifstream fin("C:\\B-small.in");
	ofstream fout("C:\\B.out");
	int t;
	fin>>t;
	FOR(k,0,t)
	{
		glob=0;
		memset(alt,-1,sizeof(alt));
		memset(store,-1,sizeof(store));
		fin>>m>>n;
		FOR(i,0,m)
		{
			FOR(j,0,n)
			{
				fin>>alt[i][j];
			}
		}
		FOR(i,0,m)
		{
			FOR(j,0,n)
			{
				if(store[i][j]!=-1)continue;
				dfs(i,j);
			}
		}
		fout<<"Case #"<<k+1<<": "<<endl;
		FOR(i,0,m)
		{
			FOR(j,0,n)
				fout<<(char)(store[i][j]+'a')<<" ";
			fout<<endl;
		}
	}
}