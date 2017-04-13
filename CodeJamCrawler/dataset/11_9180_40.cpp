#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;

#define SMALL
#define LARGE

char g[50][50];
int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};
char red[] = {'/','\\','\\','/'};

int main()	{

	freopen("1.in","r",stdin);
	
#ifdef SMALL	
	freopen("1_small.in","r",stdin);
	freopen("1_small.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("1_large.in","r",stdin);
	freopen("1_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		int r,c;
		cin>>r>>c;
		for(int i=0;i<r;i++) 
			for(int j=0;j<c;j++)
				cin>>g[i][j];

		cout<<"Case #"<<tt<<":"<<endl;

		for(int i=0;i<r;i++) 
			for(int j=0;j<c;j++) {
				if(g[i][j] == '.') continue;
				if(g[i][j] != '#') continue;
				for(int k=0;k<4;k++) {
					int ni = i+dx[k], nj = j+dy[k];
					if(ni < 0 || nj < 0 || ni >= r || nj >= c || g[ni][nj] != '#') 
						goto INVALID;
					g[ni][nj] = red[k];
				}
			}

		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) 
				cout<<g[i][j];
			cout<<endl;
		}
		cerr<<"finished "<<tt<<endl;
		continue;

INVALID:
		cout<<"Impossible"<<endl;

		cerr<<"finished "<<tt<<endl;
	}

	return 0;
}
