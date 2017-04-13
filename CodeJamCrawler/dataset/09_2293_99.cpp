#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct var
{
	long x,y;
};

long mat[1002][1002];
char color[1002][1002];
long dx[]={-1,0,0,1};
long dy[]={0,-1,1,0};
long h,w;
queue<var> q;
char now;

bool ok(long x,long y)
{
	if(x<1 || x>h || y<1 || y>w) return 0;
	else return 1;
}

void set(char cl)
{
	for(;!q.empty();q.pop())
		color[q.front().x][q.front().y] = cl;
}

var find(long x,long y)
{
	var res;
	long i;
	res.x = x,res.y = y;
	for(i=0;i<4;i++)
		if(ok(x+dx[i],y+dy[i]) && mat[x+dx[i]][y+dy[i]]<mat[res.x][res.y])
			res.x = x+dx[i],res.y = y+dy[i];

	return res;

}

void bfs(long i,long j)
{
	for(;!q.empty();q.pop());
	var temp;
	temp.x = i,temp.y = j;
	q.push(temp);

	for( ; ; )
	{
		temp = find(i,j);
		if(mat[temp.x][temp.y]>=mat[i][j])
		{
			set(now++);
			return;
		}
		else if(mat[temp.x][temp.y]<mat[i][j] && color[temp.x][temp.y])
		{
			set(color[temp.x][temp.y]);
			return;
		}
		else
		{
			i = temp.x,j = temp.y;
			q.push(temp);
		}
	}
}

int main()
{

	long tc,cs,i,j;

//	freopen("B-large.in","r",stdin);
//	freopen("b2.out","w",stdout);
	cin>>tc;

	for(cs=1;cs<=tc;cs++)
	{
		cin>>h>>w;

		memset(mat,0,sizeof(mat));
		memset(color,0,sizeof(color));

		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++)
				cin>>mat[i][j];
		now = 'a';
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				if(color[i][j]) continue;
				bfs(i,j);
			}
		}

		cout<<"Case #"<<cs<<":"<<endl;

		for(i=1;i<=h;i++)
		{
			cout<<color[i][1];
			for(j=2;j<=w;j++)
				cout<<" "<<color[i][j];
			cout<<endl;
		}

	}

	return 0;
}