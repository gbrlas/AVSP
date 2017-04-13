#include <stdio.h>
#include <memory.h>

int h, w, map[105][105], rank[20005], father[20005], no = 1, alti[20005];
int nextx[4] = {-1, 0, 0, 1};
int nexty[4] = {0, -1, 1, 0};
bool visited[20005]; 

void initSet()
{

	int n=h*w;
	for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
			{
  			   rank[i*w+j]=1;
			   father[i*w+j]=i*w+j;
			}
}

int findSet( int x )
{
 int root=x;
 while(root!=father[root])root=father[root];
 
 int j=father[x];
 while(j!=root)
 {
        father[x]=root;
		x=j;
		j=father[x];
 }
 return root;

//if( x != father[x] )
//{
//father[x] = findSet(father[x]);
//}
//return father[x];
}

void unionSet( int x, int y )
{
x = findSet(x);
y = findSet(y);
if( x == y ) return;
if( rank[x] < rank[y] ) father[x] = y;
else father[y] = x;
if( rank[x] == rank[y] ) rank[x]++;
}

bool overpass( int x, int y )
{
if( x<=0 || x>h || y<=0 || y>w ) return true;
return false;
}

void Merge()
{
	int i, j, k;
	for(i=1; i<=h; ++i)
	{
		for(j=1; j<=w; ++j)
		{
			int Min = map[i][j], dir = -1;
			for(k=0; k<4; ++k)
			{
				int tx = i + nextx[k];
				int ty = j + nexty[k];
				if( overpass(tx, ty) ) continue;
				if( map[tx][ty] < Min )
				{
					Min = map[tx][ty];
					dir = k;
				}
	}
		int tx = i + nextx[dir];
		int ty = j + nexty[dir];
		if( dir != -1 ) unionSet(i*w+j, tx*w+ty);
		}
	}
}

void Output()
{
memset(visited, 0, sizeof(visited));
int i, j, now = 0;
for(i=1; i<=h; ++i)
{
for(j=1; j<=w; ++j)
{
int f = findSet(i*w+j);
if( !visited[f] )
{
visited[f] = true;
alti[f] = now++;
}
if( j != 1 ) putchar(' ');
printf("%c", alti[f] + 'a');
}
putchar('\n');
}
}

int main()
{

int t;
scanf("%d", &t);
while( t-- )
{
scanf("%d %d", &h, &w);
int i, j;
for(i=1; i<=h; ++i)
{
for(j=1; j<=w; ++j)
{
scanf("%d", &map[i][j]);
}
}
initSet();
Merge();
printf("Case #%d:\n", no++);
Output();
}
return 0;
}
