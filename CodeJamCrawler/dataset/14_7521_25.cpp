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
      double time = calcTime(C, F, X, 0);
      double newTime;
      int i = 1;
      bool stop = false;
      while(not stop)
      {
	newTime = calcTime(C, F, X, i);
	if (newTime < time) time = newTime;
	else stop = true;
	i++;
      }
      cout << "Case #" << tCase << ": " << time << endl;
    }

    return 0;
}
