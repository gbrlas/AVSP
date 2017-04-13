#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <functional>
#include <math.h>
using namespace std;
typedef pair<int,int> pii;
typedef __int64 ll;
#define MP(X,Y) make_pair(X,Y)
#define two(X) (1<<(X))//NOTES:two(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int)(x).size())
template<class T> inline T sqr(T x){return x*x;}
const double eps=1e-6;
const int maxn=512+5;
int m,n;
int board[maxn][maxn];
int tab[513];
bool check(int r,int c,int sz)
{
	if(r+sz-1>=m||c+sz-1>=n) return false;
	int i,j;
	if(board[r][c]<0) return false;
	int first=board[r][c];
	int cfirst=0;
	for (i=r;i<r+sz;i+=2) for(j=c;j<c+sz;j+=2) 
	{
		if(board[i][j]<0) return false;
		if(board[i][j]==first) cfirst++;
	}
	for (i=r+1;i<r+sz;i+=2) for(j=c+1;j<c+sz;j+=2) 
	{
		if(board[i][j]<0) return false;
		if(board[i][j]==first) cfirst++;
	}
	int second=1-first;
	int csecond=0;
	for (i=r;i<r+sz;i+=2) for(j=c+1;j<c+sz;j+=2) 
	{
		if(board[i][j]<0) return false;
		if(board[i][j]==second) csecond++;
	}
	for (i=r+1;i<r+sz;i+=2) for(j=c;j<c+sz;j+=2) 
	{
		if(board[i][j]<0) return false;
		if(board[i][j]==second) csecond++;
	}
	if(cfirst+csecond<(sz*sz)) return false;
	else
	{
		for (i=r;i<r+sz;i++) for (j=c;j<c+sz;j++)
		{
			board[i][j]=-1;
		}
		return true;
	}

}
void main()
{
	int t,caseid,i,j;
//	ifstream fin("C.in");
	ifstream fin("C-small-attempt0.in");
//	ifstream fin("C-small-attempt1.in");
//	ifstream fin("C-large.in");
	FILE* pout=fopen("C.out","w");	
	fin>>t;
    for (caseid=1;caseid<=t;caseid++)
    {
		fin>>m>>n;
		memset(tab,0,sizeof(tab));
		char tmp;
		for (i=0;i<m;i++) for(j=0;j<n/4;j++)
		{
			fin>>tmp;
			int t;
			if (isdigit(tmp))
			{
				t=tmp-'0';
			}
			else
			{
				t=tmp-'A'+10;
			}
			for (int k=3;k>=0;k--)
			{
				if(t&(1<<k)) board[i][4*j+3-k]=1;
				else board[i][4*j+3-k]=0;
			}
		}
		int sz=min(m,n);
		int ans=0;
		for (;sz>=1;sz--)
		{
			bool flag=false;
			for (i=0;i<m;i++) 
			{
				for (j=0;j<n;j++) 
					if (check(i,j,sz))
					{
						tab[sz]++;
						flag=true;
					}
			}
            if(flag) ans++;
		}
		fprintf(pout,"Case #%d: %d\n",caseid,ans);
		for (i=512;i>=1;i--) if(tab[i])
		{
			fprintf(pout,"%d %d\n",i,tab[i]);
		}
	}
	fin.close();
	fclose(pout);
}

