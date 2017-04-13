#include <stdio.h>
#include <math.h> 
#include <iostream>
#include <sstream> 
#include <set> 
#include <map> 
#include <vector> 
#include <list> 
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

long double slenn(long double a1, long double a2, long double a3)
{
   return a1*a1+a2*a2+a3*a3;
}
long double lenn(long double a1, long double a2, long double a3)
{
   return sqrt(a1*a1+a2*a2+a3*a3);
}
long double scal(long double a1, long double a2, long double a3,
				 long double b1, long double b2, long double b3)
{
   return a1*b1+a2*b2+a3*b3;
}


long double o1, o2, o3;
long double v1, v2, v3;
long double lo, lv, slo, slv;
long double t, d;

void ReadFlies()
{
   int N;
   cin>>N;//3..500
   int sa1=0, sa2=0, sa3=0; //enough for 5000*500
   int sb1=0, sb2=0, sb3=0;
   for(int i=1;i<=N;++i) {
      int a1, a2, a3;
	  cin >> a1 >> a2 >> a3;
	  sa1+=a1;
	  sa2+=a2;
	  sa3+=a3;
	  int b1, b2, b3;
	  cin >> b1 >> b2 >> b3;
	  sb1+=b1;
	  sb2+=b2;
	  sb3+=b3;      
   }
   o1 = sa1/(long double)N;
   o2 = sa2/(long double)N;
   o3 = sa3/(long double)N;

   v1 = sb1/(long double)N;
   v2 = sb2/(long double)N;
   v3 = sb3/(long double)N;

   lo = lenn(o1, o2, o3);
   lv = lenn(v1, v2, v3);
   slo = slenn(o1, o2, o3);
   slv = slenn(v1, v2, v3);

   long double scala = scal(-o1, -o2, -o3, v1, v2, v3);
   long double cosa = scala/lo/lv;
   
   if (slo == 0) {
	   t=0;
	   d=0;
   }
   else if(cosa<=0 || slv == 0) {
      t=0;
	  d=lo;
   }
   else if(cosa>=1) {
	   d=0;
	   t=lo/lv;
   }
   else {
      t=scala/slv;
	  d=lo*sin(acos(cosa));
   }

}

void PrintResult(int i)
{
    	cout <<"Case #" << i << ": ";
		cout << setprecision(8) << fixed << d << " " << t;
		cout << endl;
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	int N;
	cin>>N;

	for(int i=1;i<=N;++i)
	{
		ReadFlies();
		PrintResult(i);
	}
	return 0;
}
