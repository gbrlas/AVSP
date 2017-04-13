#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define M 400010
#define N 1050
//#define ll long long
#define inf 0x3f3f3f3f
const double eps = 1e-8;

double a[M], b[M];
int n;
int vis[M];
int vis2[M];
int solve1()
{
	memset( vis, 0, sizeof(vis) );
	int ans = 0;
	for( int i = n - 1; i >= 0; --i ){
		int j = 0, k = 0;
		while( j < n ){
			if( !vis[j] && b[j] > a[i] ) break;
			++j;
		}
		if( j < n ){
			vis[j] = 1;
		}
		else{
			j = 0;
			while( !vis[j] ) ++j;
			vis[j] = 1;
			++ans;
		}
	}
	return ans;
}

int solve2( int x )
{
	int ans = 0;
	int i = 0, j = 0, k = n - 1;
	while( i < n ){
		if( a[i] < b[j] ){
			++i;
		}
		else{
			++i, ++j;
			++ans;
		}
	}
	return ans;
}
	
int main()
{
	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );
	int T, cas = 0;
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &n );
		for( int i = 0; i < n; ++i ) scanf( "%lf", a+i );
		for( int i = 0; i < n; ++i ) scanf( "%lf", b+i );
		sort( a, a+n );
		sort( b, b+n );
		int x = solve1();
		int y = solve2(x);
		printf( "Case #%d: %d %d\n", ++cas, y, x );
	}
}
/*
int n, m, k;
bool in( int x, int y )
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int vis[55][55];
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int num;
void dfs( int x, int y )
{
	queue<int> q;
	if( k == 0 ) return;
	q.push( x ), q.push( y );
	int x1, y1;
	++num;
	vis[x][y] = 0;
	while( !q.empty() ){
		x = q.front(), q.pop();
		y = q.front(), q.pop();
		for( int i = 0; i < 4; ++i ){
			x1 = x + dx[i];
			y1 = y + dy[i];
			if( !in( x1, y1 ) ) continue;
			if( vis[x1][y1] >= 0 ) continue;
			if( x1 <= 2 && y1 <= 2 ) continue;
			vis[x1][y1] = 0;
			++num;
			if( num >= k ) return;
			q.push( x1 ), q.push( y1 );
		}
	}
}


bool solve()
{
	if( n * m <= k ) return 0;
	memset( vis, -1, sizeof(vis) );
	num = 0;
	dfs( n, m );
	int x = 1, y = 1;
	int ha = 0;
	for( int i = 0; i < 8; ++i ){
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if( !in( x1, y1 ) ) continue;
		if( num < k ){
			++num;
			vis[x1][y1] = 0;
		}
	}
	int all = 0;
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= m; ++j ){
			if( vis[i][j] == -1 ){
				ha = 0;
				for( int k = 0; k < 8; ++k ){
					x = i + dx[k];
					y = j + dy[k];
					if( in( x, y ) && vis[x][y] >= 0 ) ++ha;
				}
				if( ha ){
					vis[i][j] = ha;
					++all;
				}
			}
		}
	if( vis[1][1] != -1 && all != 1 ) return 0;
	for( int i = 1; i <= n; ++i ){
		for( int j = 1; j <= m; ++j ){
			if( i == 1 && j == 1 ) printf( "c" );
			else if( vis[i][j] == -1 ) printf( "." );
			else if( vis[i][j] == 0 ) printf( "*" );
			else printf( ".");
		}
		puts( "" );
	}
	return 1;
}
int main()
{
	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );
	int T;
	int x, y, cas = 0;
	scanf( "%d", &T );
	while( T-- ){

		scanf( "%d%d%d", &n, &m, &k );
		printf( "Case #%d:\n", ++cas );
		if( !solve() ) puts( "Impossible" );
	}
		
}
*/
/*
#define mod 1000000007
int vv[M], nxt[M], cap[M], cc[M], h[N], e;
void add( int u, int v, int f, int c )
{
	vv[e] = v, nxt[e] = h[u], cap[e] = f, cc[e] = c, h[u] = e++;
	vv[e] = u, nxt[e] = h[v], cap[e] = 0, cc[e] = -c, h[v] = e++;
}
int dis[N], pre[N], vis[N];
int spfa( int s, int t )
{
	memset( dis, 0x3f, sizeof(dis) );
	memset( vis, 0, sizeof(vis) );
	queue<int> q;
	q.push( s );
	dis[s] = 0;
	int u, v;
	while( !q.empty() ){
		u = q.front(), q.pop();
		vis[u] = 0;
		for( int i = h[u]; i+1; i = nxt[i] ) if( cap[i] > 0 ) {
			v = vv[i];
			if( dis[v] > dis[u] + cc[i] ){
				dis[v] = dis[u] + cc[i];
				pre[v] = i;
				if( !vis[v] )
					vis[v] = 1, q.push( v );
			}
		}
	}
	return dis[t] != inf;
}

int solve( int s, int t )
{
	int ans = 0;
	int v, mins;
	while( spfa( s, t ) ){
		v = t;
		mins = inf;
		while( v - s ){
			v = pre[v];
			mins = min( mins, cap[v] );
			v = vv[v^1];
		}
		ans += mins * dis[t];
		v = t;
		while( v - s ){
			v = pre[v];
			cap[v] -= mins;
			cap[v^1] += mins;
			v = vv[v^1];
		}
	}
	return ans;
}
int a[110][110];
int dp[1011][1011];

int main()
{
	int T;
	int n, v, m;
	int cas = 0;
	scanf( "%d", &T );
	while( T-- ){
		cin>>n>>m;
		memset( h, -1, sizeof(h) ), e = 0;
		for( int i = 1; i <= n; ++i ){
			for( int j = 1; j <= m; ++j ){
				scanf( "%d", &v );
				a[i][j] = v;
				add( i, j+n, 1, v );
			}
		}
		int s = n + n + m + m + 1, t = s + 1;
		for( int i = 1; i <= n; ++i ){
			add( s, i, 1, -100000 );
			add( s, i+n+m, n, 0 );
			for( int j = 1; j <= m; ++j )
				add( i+n+m, j+n, 1, a[i][j] );
		}
		for( int j = 1; j <= m; ++j ){
			add( n+j, t, 1, -100000 );
			add( n+n+m+j, t, 1, 0 );
			for( int i = 1; i <= n; ++i )
				add( i, j+n+n+m, 1, a[i][j] );
		}
		int ans = solve( s, t ) + 100000 * ( n + m );
		printf( "Case %d: %d\n", ++cas, ans / 2 );
	}
				
}
*/