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
const int maxn=50+5;
char board[maxn][maxn];
int n,k;
bool R,B;
void check(int i,int j)
{
	int cntR,cntB;
	if (j+k-1<n)
	{
		cntR=cntB=0;
		for (int endj=j;endj<=j+k-1;endj++)
		{
			if(board[i][endj]=='R') cntR++;
			if(board[i][endj]=='B') cntB++;
		}
		if(cntR==k) R=true;
		if(cntB==k) B=true;
	}
	if (i+k-1<n&&j+k-1<n)
	{
		cntR=cntB=0;
		for (int d=0;d<k;d++)
		{
			if(board[i+d][j+d]=='R') cntR++;
			if(board[i+d][j+d]=='B') cntB++;
		}
		if(cntR==k) R=true;
		if(cntB==k) B=true;
	}
	if (i+k-1<n)
	{
		cntR=cntB=0;
		for (int endi=i;endi<=i+k-1;endi++)
		{
			if(board[endi][j]=='R') cntR++;
			if(board[endi][j]=='B') cntB++;
		}
		if(cntR==k) R=true;
		if(cntB==k) B=true;
	}
	if (i-k+1>=0&&j+k-1<n)
	{
		cntR=cntB=0;
		for (int d=0;d<k;d++)
		{
			if(board[i-d][j+d]=='R') cntR++;
			if(board[i-d][j+d]=='B') cntB++;
		}
		if(cntR==k) R=true;
		if(cntB==k) B=true;
	}
}
void main()
{
	int t,caseid,i,j;
//	ifstream fin("A.in");
	ifstream fin("A-small-attempt0.in");
//	ifstream fin("A-small-attempt1.in");
//	ifstream fin("A-large.in");
	FILE* pout=fopen("A.out","w");	
	fin>>t;
    for (caseid=1;caseid<=t;caseid++)
    {
		fin>>n>>k;
		for (i=0;i<n;i++) for(j=0;j<n;j++)
		{
			fin>>board[i][j];
		}
		char other[maxn][maxn];
        for (i=0;i<n;i++)
        {
			char tmp[maxn];
			int top=n-1;
			for (j=n-1;j>=0;j--)
			{
				if(board[i][j]!='.')
					tmp[top--]=board[i][j];
			}
			for (j=0;j<=top;j++)
			{
				tmp[j]='.';
			}
			memcpy(other[i],tmp,sizeof(char)*n);
        }
		for (i=0;i<n;i++) for (j=0;j<n;j++)
		{
			board[j][n-1-i]=other[i][j];
		}
		R=B=false;
		for (i=0;i<n;i++) for (j=0;j<n;j++)
		{
			check(i,j);
		}
		if(R&&B)
			fprintf(pout,"Case #%d: Both\n",caseid);
		else if((!R)&&B)
			fprintf(pout,"Case #%d: Blue\n",caseid);
		else if(R&&(!B))
			fprintf(pout,"Case #%d: Red\n",caseid);
		else 
			fprintf(pout,"Case #%d: Neither\n",caseid);
	}
	fin.close();
	fclose(pout);
}

