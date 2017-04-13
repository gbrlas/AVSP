#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> pint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;


int r,c,m;
char a[5][5],b[5][5];
int cnt[5][5];
bool found;

int h(int i, int j)
{
	if (a[i][j]=='*')
		return -1;
	int cnt=0;
	if (i-1>=0&&j-1>=0&&a[i-1][j-1]=='*')
		cnt++;
	if (i-1>=0&&a[i-1][j]=='*')
		cnt++;
	if (j-1>=0&&a[i][j-1]=='*')
		cnt++;
	if (i+1<r&&a[i+1][j]=='*')
		cnt++;
	if (j+1<c&&a[i][j+1]=='*')
		cnt++;
	if (i+1<r&&j+1<c&&a[i+1][j+1]=='*')
		cnt++;
	if (i+1<r&&j-1>=0&&a[i+1][j-1]=='*')
		cnt++;
	if (i-1>=0&&j+1<c&&a[i-1][j+1]=='*')
		cnt++;
	return cnt;
}


pint tm;
bool check()
{
	pint fs=mp(-1,-1);
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
		{
			cnt[i][j]=h(i,j);
			if (cnt[i][j]==0)
				fs=mp(i,j);
		}
	if (fs.fi==-1)
	{
		int x=0;
		for (int i=0; i<r; i++)
			for (int j=0; j<c; j++)
				if (cnt[i][j]!=-1)
				{
					tm=mp(i,j);
					x++;
				}
		return x==1;
	}
	tm=fs;
	queue<pint> q;
	q.push(fs);
	int i,j;
	while (!q.empty())
	{
		fs=q.front();
		q.pop();
		if (fs.fi<0||fs.se<0||fs.fi>=r||fs.se>=c)
			continue;
		i=fs.fi,j=fs.se;
		if (cnt[i][j]==-1)
			continue;
		if (cnt[i][j]==0)
		{
			q.push(mp(i-1,j));
			q.push(mp(i,j-1));
			q.push(mp(i+1,j));
			q.push(mp(i,j+1));
			q.push(mp(i-1,j-1));
			q.push(mp(i+1,j+1));
			q.push(mp(i-1,j+1));
			q.push(mp(i+1,j-1));
		}
		cnt[i][j]=-1;
	}
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			if (cnt[i][j]!=-1)
				return false;
	return true;
}

void f(int i, int j, int m, char c1, char c2)
{
	if (found) return;
	if (m==0)
	{
		if (check())
		{
			found=true;
			for (int i=0; i<r; i++)
				for (int j=0; j<c; j++)
					b[i][j]=a[i][j];
			b[tm.fi][tm.se]='c';
		}
		return;
	}
	if (j==c) return;
	int ni=i+1,nj=j;
	if (ni==r)
		ni=0,nj++;
	f(ni,nj,m,c1,c2);
	a[i][j]=c1;
	f(ni,nj,m-1,c1,c2);
	a[i][j]=c2;
}

void f() //make m cells free
{
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			a[i][j]='*';
	found=false;
	f(0,0,m,'.','*');
}

void g() //set m mines
{
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			a[i][j]='.';
	found=false;
	f(0,0,m,'*','.');
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++)
	{
		scanf("%d %d %d",&r,&c,&m);
		printf("Case #%d:\n",t);
		if (m>r*c/2) //well instead of setting mines we can set free cells
			m=r*c-m,f();
		else //set mines as usual
			g();
		if (!found)
			printf("Impossible\n");
		else
			for (int i=0; i<r; i++,printf("\n"))
				for (int j=0; j<c; j++)
					printf("%c",b[i][j]);
	}
	return 0;
}
