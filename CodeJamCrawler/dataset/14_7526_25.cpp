#include<iostream>
#include<vector>
#include<cmath>
using namespace std;



double calcTime(double C, double F, double X, int n)
{
  double sol = 0.0;
  for (int i = 0; i < n; ++i)
  {
    sol += C/(2+i*F);
  }
  sol += X/(2+n*F);
  return sol;
}

int isSol(double C, double F, double X, int n, int minN, int maxN)
{
  
  double t = calcTime(C, F, X, n);
  double t1 = calcTime(C, F, X, n + 1);
  //cout << " >>> for n = " << n << " "  << t << " " << t1 << " ";
  if (t1 < t) return 1;
  return -1;
  
}

int main()
{
    int T;
    cin >> T;
    cout.precision(7);
    cout.setf(ios::fixed);
    for (int tCase = 1; tCase <= T; tCase++)
    {
      double C, F, X;
      cin >> C >> F >> X;
      double baseTime = calcTime(C, F, X, 0);
      int minN = 0;
      int maxN = (X/C) + 1;
      bool maxExpandable = true;
      int n = (minN + maxN)/2;
      
      bool done = false;
      while(not done)
      {
	int sol = isSol(C, F, X, n, minN, maxN);
	//cout << sol << endl;
	if (sol == 1)
	{
	  if (maxExpandable) maxN += 2*(maxN - n);
	  minN = n;
	  n = (minN + maxN)/2;
	}
	if (sol == -1)
	{
	  maxExpandable = false;
	  maxN = n;
	  n = (minN + maxN)/2;
	}
	if (n == minN or n == maxN) done = true;
	
	
      }
      
      //cout << " >>> n = " << n << endl;
      double time = min(calcTime(C, F, X, minN), calcTime(C, F, X, maxN));
      cout << "Case #" << tCase << ": " << time << endl;
    }

    return 0;
}
