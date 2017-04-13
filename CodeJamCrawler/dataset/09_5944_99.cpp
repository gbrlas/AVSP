#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef pair<int,int> pii;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool vis[10000];

vector<vector<pii> > adj;
int g[100][100];
int r,c;

void ff(int ind, int color)	{
	for(int i=0;i<adj[ind].size();i++)	{
		int nx = adj[ind][i].first, ny = adj[ind][i].second;
		if(vis[nx*c+ny]) continue;
		vis[nx*c+ny]=1;
		g[nx][ny]=color;
		ff(nx*c+ny, color);
	}
}

int main()	{
	
	freopen("2_large.in","rt",stdin);
	freopen("2_large.out","wt",stdout);
	
	int t;
	cin>>t;
	
	for(int tc=1;tc<=t;tc++)	{
	
		cin>>r>>c;
		
		memset(vis,0,sizeof(vis));
		adj.clear();
		adj.resize(r*c);
		
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>g[i][j];
		
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)	{
				int m=1000000;
				pii to;
				for(int k=0;k<4;k++)	{
					int nx=i+dx[k], ny=j+dy[k];
					if(nx<0 || ny<0 || nx>=r || ny>=c || g[nx][ny]>=g[i][j] || g[nx][ny]>=m) continue;
					m=g[nx][ny];
					to = pii(nx,ny);
				}
				if(m==1000000) continue;
				adj[i*c+j].push_back(to);
				adj[to.first*c+to.second].push_back(pii(i,j));
			}
		
		int cur=0;
		
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(!vis[i*c+j])
					vis[i*c+j]=1, g[i][j]=cur, ff(i*c+j, cur++);
		
		cout<<"Case #"<<tc<<":"<<endl;
		
		for(int i=0;i<r;i++)	{
			string seb="";
			for(int j=0;j<c;j++,seb=" ") cout<<seb<<char('a'+g[i][j]);
			cout<<endl;
		}
			
	}
	
	return 0;
}
