#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <iomanip>
using namespace std;


int r, c, m;
int r2, c2, m2;
char map[10][10];

int swap(int *x, int *y)
{
  *x ^= *y;
  *y ^= *x;
  *x ^= *y;
  
  return 0;
}

void muripo()
{
  cout << "Impossible" << endl;
}

void show()
{
  map[0][0] = 'c';
  if(r > c)
    {
      for(int i = 0; i < r; i++)
	{
	  for(int j = 0; j < c; j++)
	    {
	      cout << map[j][i];
	    }
	  cout << endl;
	}
    }else{
    for(int i = 0; i < r; i++)
      {
	for(int j = 0; j < c; j++)
	  {
	    cout << map[i][j];
	  }
	cout << endl;
      }
  }
}

int tume()
{
  
  if(r2 == c2 && m2 == r2 - 1)
    {
      map[r2 - 2][c2 - 1] = '*';
      m2--;
    }
  
  for(int i = 0; i < m2; i++)
    {
      map[r2 - 1][c2 - 1 - i] = '*';
    }
  
  return 0;
}

int solve()
{
  for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < 10; j++)
	{
	  map[i][j] = '*';
	}
    }
  cin >> r >> c >> m;
  r2 = min(r, c);
  c2 = max(r, c);
  m2 = m;

  if(r2 == 1)
    {
      for(int i = 0; i < c2 - m2; i++)
	{
	  map[r2 - 1][i] = '.';
	}
      show();
      return 0;
    }
  

  while(1)
    {
      if(r2 <= m2)
	{
	  m2 -= r2;
	  c2--;
	  if(r2 > c2)
	    {
	      swap(&r2, &c2);
	    }
	}else{
	break;
      }
    }
  for(int i = 0; i < r2; i++)
    {
      for(int j = 0; j < c2; j++)
	{
	  map[i][j] = '.';
	}
    }
  if(c2 == r2)
    {
      if(c2 == 1)
	{
	  show();
	  return 0;
	}
      if(c2 == 2)
	{
	  if(m2 == 1)
	    {
	      muripo();
	      return 0;
	    }else{
	    show();
	    return 0;
	  }
	}
      if(c2 == 3)
	{
	  if(m2 == 2)
	    {
	      muripo();
	      return 0;
	    }else{
	    tume();
	    show();
	    return 0;
	  }
	}
      if(c2 >= 4)
	{
	  tume();
	  show();
	  return 0;
	}
    }
  if(c2 != r2)
    {
      if(r2 == 1)
	{
	  muripo();
	  return 0;
	}
      if(r2 == 2)
	{
	  if(m2 == 0)
	    {
	      show();
	      return 0;
	    }else{
	    muripo();
	    return 0;
	  }
	}
      if(r2 >= 3)
	{
	  tume();
	  show();
	  return 0;
	}
    }

  return 0;
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

      cout << "Case #" << (i + 1) << ":" << endl;;
      solve();
      /*
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
      */
    }
  return 0;
}
