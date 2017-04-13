#define _HAS_ITERATOR_DEBUGGING 0

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <map>
#include <set>
#include <bitset>

using namespace std;

int main()
{
  freopen( "A-small-attempt0.in", "rt", stdin );
  freopen( "a.out", "wt", stdout );

  string line;

  int T;
  {
    getline(cin, line);
    istringstream(line) >> T;
  }
  for (int t = 0; t < T; ++t )
  {
    int n;
    {
      getline(cin, line);
      istringstream(line) >> n;
    }

    vector<string> v;
    for (int i = 0; i < n; ++i)
    {
      getline(cin, line);
      v.push_back( line );
    }

    int ret = 0;

    for (;;)
    {
      bool found = false;
      for (int i = 0; i < n; ++i)
      {
        int j;
        for (j = n-1; j >= 0; --j)
        {
          if ( v[i][j] == '1' ) break;
        }
        if (j > i)
        {
          assert( i != n-1);
          bool here = false;
          for (int k = i+1; k < n; ++k)
          {
            int l;
            for (l = n-1; l >= 0; --l)
            {
              if ( v[k][l] == '1' ) break;
            }
            if ( l < j )
            {
              here = true;
              for ( int a = k; a > i; --a )
              {
                ++ret;
                v[a].swap( v[a-1] );
              }
              break;
            }
          }
          assert( here );

          found = true;
          break;
        }
      }

      if (!found) break;
    }

    cout << "Case #" << (t+1) << ": " << ret << endl;
  }
  return 0;
}
