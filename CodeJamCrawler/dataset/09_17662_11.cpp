#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int r,c;
int g[15][15],gg[15][15],ok[15][15],dist[10000000];
vector <pair<int,int> > dest,q[10000000];
map <vector<pair<int,int> >,bool> h;
bool able[4];

bool isConnected(int id)
{
	if(q[id].size()==1) return true;
	memset(gg,0,sizeof(gg));
	for(int i=0;i<q[id].size();++i) gg[q[id][i].first][q[id][i].second]=1;
	for(int i=0;i<q[id].size();++i)
	{
		bool flag=false;
		for(int k=0;k<4;++k)
		{
			int tx=q[id][i].first+dx[k],ty=q[id][i].second+dy[k];
			if(tx>-1&&tx<r&&ty>-1&&ty<c&&gg[tx][ty])
			{
				flag=true;
				break;
			}
		}
		if(flag==false) return false;
	}
	return true;
}

bool reachdest(vector<pair<int,int> > t)
{
	sort(t.begin(),t.end());
	return t==dest;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int zz,n;
	cin>>zz;
	for(int z=1;z<=zz;++z)
	{
		h.clear();
		dest.clear();
		q[0].clear();
		cin>>r>>c;
		string s;
		for(int i=0;i<r;++i)
		{
			cin>>s;
			for(int j=0;j<s.size();++j)
			{
				switch(s[j])
				{
					case '.': g[i][j]=0; break;
					case '#': g[i][j]=-1; break;
					case 'x': g[i][j]=0; dest.push_back(make_pair(i,j)); break;
					case 'o': g[i][j]=0; q[0].push_back(make_pair(i,j)); break;
					case 'w': g[i][j]=0; dest.push_back(make_pair(i,j)); q[0].push_back(make_pair(i,j)); break;
				}
			}
		}
		sort(dest.begin(),dest.end());
		h[q[0]]=true;
		dist[0]=0;
		int ans=-1;
		for(int head=0,tail=1;head<tail;++head)
		{
			if(reachdest(q[head]))
			{
				ans=dist[head];
				break;
			}
			bool cnn=isConnected(head);
			memset(ok,0,sizeof(ok));
			for(int i=0;i<q[head].size();++i) ok[q[head][i].first][q[head][i].second]=1;
			for(int i=0;i<q[head].size();++i)
			{
				for(int k=0;k<4;++k)
				{
					int tx=q[head][i].first+dx[k],ty=q[head][i].second+dy[k];
					able[k]=(tx>-1&&tx<r&&ty>-1&&ty<c&&g[tx][ty]!=-1&&ok[tx][ty]==0);
				}
				if(able[0]==true&&able[2]==true)
				{
					q[tail]=q[head];
					int tx=q[head][i].first+dx[0],ty=q[head][i].second+dy[0];
					q[tail][i]=make_pair(tx,ty);
					if(!h[q[tail]])
					{
						dist[tail]=dist[head]+1;
						if(cnn==false)
						{
							if(isConnected(tail))
							{
								h[q[tail]]=true;
								++tail;
							}
						}
						else
						{
							h[q[tail]]=true;
							++tail;
						}
					}
					
					q[tail]=q[head];
					tx=q[head][i].first+dx[2],ty=q[head][i].second+dy[2];
					q[tail][i]=make_pair(tx,ty);
					if(!h[q[tail]])
					{
						dist[tail]=dist[head]+1;
						if(cnn==false)
						{
							if(isConnected(tail))
							{
								h[q[tail]]=true;
								++tail;
							}
						}
						else
						{
							h[q[tail]]=true;
							++tail;
						}
					}
				}
				if(able[1]==true&&able[3]==true)
				{
					q[tail]=q[head];
					int tx=q[head][i].first+dx[1],ty=q[head][i].second+dy[1];
					q[tail][i]=make_pair(tx,ty);
					if(!h[q[tail]])
					{
						dist[tail]=dist[head]+1;
						if(cnn==false)
						{
							if(isConnected(tail))
							{
								h[q[tail]]=true;
								++tail;
							}
						}
						else
						{
							h[q[tail]]=true;
							++tail;
						}
					}
					
					q[tail]=q[head];
					tx=q[head][i].first+dx[3],ty=q[head][i].second+dy[3];
					q[tail][i]=make_pair(tx,ty);
					if(!h[q[tail]])
					{
						dist[tail]=dist[head]+1;
						if(cnn==false)
						{
							if(isConnected(tail))
							{
								h[q[tail]]=true;
								++tail;
							}
						}
						else
						{
							h[q[tail]]=true;
							++tail;
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}

