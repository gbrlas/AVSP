#include "stdafx.h"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <boost/regex.hpp>

using namespace std;

int grid[100][100];
int visited[100][100];

const int dy[4] = {-1,0,0,1}, dx[4]={0,-1,1,0};

int H,W;
int go(int y, int x)
{
  if (visited[y][x] != -1) return visited[y][x];

  int best = grid[y][x];
  int by,bx;
  for (int d = 0; d < 4; ++d)
  {
    int ny = dy[d]+y, nx = dx[d]+x;
    if (ny < (unsigned)H && nx < (unsigned)W && grid[ny][nx] < best)
    {
      best = grid[ny][nx];
      by = ny;
      bx = nx;
    }
  }
  
  assert( best != grid[y][x] );
  return visited[y][x] = go(by, bx);
}

int main()
{
  freopen("B-large.in", "rt", stdin);
  freopen("outputB.txt", "wt", stdout);

  int T;
  cin >> T;
  for (int Case = 0; Case < T; ++Case)
  {
    cin >> H >> W;

    for (int i = 0; i < H; ++i)
    {
      for (int j = 0; j < W; ++j)
      {
        cin >> grid[i][j];
      }
    }

    memset( visited, -1, sizeof( visited ) );

    int n = 0;
    for (int i = 0; i < H; ++i)
    {
      for (int j = 0; j < W; ++j)
      {
        bool ok = false;
        for (int d = 0; d < 4; ++d)
        {
          int y = i+dy[d], x = j+dx[d];
          if (y < (unsigned) H && x < (unsigned) W && grid[y][x] < grid[i][j])
          {
            ok = true;
            break;
          }
        }
        if (!ok)
        {
          visited[i][j] = n++;
        }
      }
    }

    for (int i = 0; i < H; ++i)
    {
      for (int j = 0; j < W; ++j)
      {
        if ( visited[i][j] == -1 )
        {
          go(i, j);
        }
      }
    }

    cout << "Case #" << Case+1 << ":" << endl;

    map<int,int> v;
    int c = 0;
    for ( int i = 0; i < H; ++i )
    {
      for ( int j = 0; j < W; ++j )
      {
        assert( visited[i][j] != -1 );
        if ( !v.count(visited[i][j]) )
        {
          v[visited[i][j]] = c++;
        }
        if (j != 0) cout << " ";
        cout << (char)(v[visited[i][j]]+'a');
      }
      cout << endl;
    }
  }

  return 0;
}
