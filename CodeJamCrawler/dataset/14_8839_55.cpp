#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

int T;
double c,f,x;

int main()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  cin >>T;
  for (int ii=1;ii<=T;ii++)
    {
      cin >>c >>f >>x;
      double ans=0.0,now=2.0;
      for (;;)
	{
	  double t1=x/now;
	  double t2=x/(now+f)+c/now;
	  if (t2<t1)
	    {
	      ans+=c/now;
	      now+=f;
	    }
	  else break;
	}
      ans+=x/now;
      cout <<"Case #" <<ii <<": " <<fixed <<setprecision(7) <<ans <<endl;
    }
  return 0;
}
