#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <iomanip>
using namespace std;


double c, f, x, ans;

double calc(double num)
{
  double hoge = 0.0;

  
  if(c/num + x/(num + f) < x/num)
    {
      hoge = calc(num + f);
    }else{
    return x/num;
  }
  
  return (hoge + c/num);
}


int solve()
{

  cin >> c >> f >> x;

  ans = calc(2);


  cout << ans << endl;
  
  return 0;
}



int main()
{
  int m;
  string s;

  cout << setprecision(20); // 精度を 20桁に指定

  cin >> s;
  istringstream istr(s);
  istr >> m;

  for(int i = 0; i < m; i++)
    {

      cout << "Case #" << (i + 1) << ": ";
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
