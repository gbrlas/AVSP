#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <limits.h>
using namespace std;

int ans2;

int solve()
{
  int line, line2;
  int grid[4][4], grid2[4][4];
  int ans = 0;

  cin >> line;
  line--;
  for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
	{
	  cin >> grid[i][j];
	}
    }
  cin >> line2;
  line2--;
  for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
	{
	  cin >> grid2[i][j];
	}
    }

  for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
	{
	  if(grid[line][i] == grid2[line2][j])
	    {
	      ans++;
	      ans2 = grid[line][i];
	    }
	}
    }

  return ans;
}



int main()
{
  int m;
  string s;

  cin >> s;
  istringstream istr(s);
  istr >> m;

  for(int i = 0; i < m; i++)
    {

      //      cout << "Case #" << (i + 1) << ": ";
      switch(solve())
	{
	case 0:
	  cout << "Case #" << (i + 1) << ": Volunteer cheated!" << endl;
	  break;
	case 1:
	  cout << "Case #" << (i + 1) << ": " << ans2 << endl;
	  break;
	default:
	  cout << "Case #" << (i + 1) << ": Bad magician!" << endl;
	  break;
	}
    }
  return 0;
}
