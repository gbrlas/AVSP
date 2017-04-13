#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

struct dis_joint_set{

	vector<int> p,r;
	int cmp;
	dis_joint_set(int N)
	{
		p.resize(N+1);
		r.resize(N+1);
		clear();
		cmp = N;
		cerr<<"djs of size "<<N<<" created\n";
	}
	void clear()
	{
		for(int i=0;i<(int)p.size();i++)
		{
			p[i] = i;
			r[i] = 0;
		}
	}
	int find(int x)
	{
		if( x == p[x] ) return x;
		return p[x] = find( p[x] );
	}

	void merg(int px,int py)
	{
		px = find(px);
		py = find(py);
		if( px == py ) return ;
		cmp--;
		if( r[px] == r[py] )
		{
			r[px]++;
			p[py] = px;
		}
		else if( r[px] > r[py] )
			p[py] = px;
		else 
			p[px] = py;             
	}

};

int a[105][105];
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("Bout.txt","wt",stdout);
	int TC,i,j,x,y,w,h,nx,ny,best;
	scanf("%d",&TC);
	for(int t=1;t<=TC;t++)
	{
		scanf("%d %d",&h,&w);
		for(x=0;x<h;x++)
			for(y=0;y<w;y++)
				scanf("%d",&a[x][y]);
		dis_joint_set djs(w*h);
		for(x=0;x<h;x++){
			for(y=0;y<w;y++)
			{
				j = -1;
				best = 1000000000;
				for(i=0;i<4;i++)
				{
					nx = x+dx[i];
					ny = y+dy[i];
					if(nx<0||ny<0||nx>=h||ny>=w) continue;
					if(a[nx][ny]<a[x][y] && a[nx][ny]<best)
					{
						best = a[nx][ny];
						j = i;
					}
				}
				if(j!=-1)
				{
					nx = x+dx[j];
					ny = y+dy[j];
					djs.merg(x*w+y,nx*w+ny);
				}
			}
		}
		map<int,char> m;
		printf("Case #%d:\n",t);
		for(x=0;x<h;x++)
		{
			for(y=0;y<w;y++)
			{
				i = djs.find(x*w+y);
				if(m.find( i ) == m.end() )
				{
					j = (int)m.size();
					m[i] = (char)('a'+j);
				}
				if(y)
					printf(" ");
				printf("%c",m[i]);
			}
			printf("\n");
		}
	}
	return 0;
}