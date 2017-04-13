#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <map>
#include <set>

using namespace std;

set<string> lut[10];
string state;
int L,D,N;

int go( const vector<string>& v, int a )
{
  if ( a == L ) return 1;
  int ret = 0;

  for ( int i = 0; i < v[a].size(); ++i )
  {
    state[a] = v[a][i];
    if ( lut[a].count( state.substr( 0, a + 1 ) ) )
    {
      ret += go( v, a + 1 );
    }
  }

  return ret;
}

int main()
{
  freopen( "A-large.in", "rt", stdin );
  freopen( "a.out", "wt", stdout );

  string line;
  getline( cin, line );
  {
    istringstream iss( line );
    iss >> L >> D >> N;
  }

  state.resize( L );

  for ( int i = 0; i < D; ++i )
  {
    getline( cin, line );
    for ( int j = 0; j < L; ++j )
    {
      lut[j].insert( line.substr( 0, j+1 ) );
    }
  }

  for ( int i = 0; i < N; ++i )
  {
    getline( cin, line );

    vector<string> v;
    for ( int j = 0; j < line.size(); )
    {

      if ( line[j] == '(' )
      {
        int k = line.find( ')', j );
        v.push_back( line.substr( j + 1, k - j - 1 ) );
        j = k + 1;
      }
      else 
      {
        v.push_back( string( 1, line[j] ) );
        ++j;
      }
    }

    int ret = go(v, 0);
    cout << "Case #" << (i+1) << ": " << ret << endl;
  }
  return 0;
}
