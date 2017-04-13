#include <cstdio>

using namespace std;

int n, m;
int mat[101][101];
int sol[101][101];
int lett;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void load() {
  scanf( "%d%d", &n, &m );
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < m; ++j ) {
      scanf( "%d", &mat[i][j] );
      sol[i][j] = -1;
    }
}

int spread( int r, int s ) {
  if( sol[r][s] != -1 ) return sol[r][s];
  
  int br = -1, bs = -1;

  for( int i = 0; i < 4; ++i ) {
    int nr = r+dx[i], ns = s+dy[i];
    if( nr < 0 || ns < 0 || nr >= n || ns >= m || mat[nr][ns] >= mat[r][s] ) continue;
    if( br == -1 || mat[nr][ns] < mat[br][bs] ) {
      br = nr;
      bs = ns;
    }
  }
    
  return sol[r][s] = ( br == -1 ? lett++ : spread( br, bs ) );
}

void solve() {
  lett = 0;
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < m; ++j ) {
      if( sol[i][j] == -1 ) 
	spread( i, j );
      printf( "%c%s", sol[i][j]+'a', ( j == m-1? "\n" : " " ) );
    }
}

int main() {
  int ntp;

  scanf( "%d", &ntp );
  for( int i = 0; i < ntp; ++i ) {
    load();
    printf( "Case #%d:\n", i+1 );
    solve();
  }

  
  return 0;
}
