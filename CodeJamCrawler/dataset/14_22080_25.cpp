#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
  
  ifstream cin ("test.txt");
  ofstream cout ("output.out");
  
  int t;
  cin >> t;
  
  double c[t];
  double f[t];
  double x[t];
  
  double rate;
  
  double time1, time2;
  double totaltime;
  
  for (int i = 0; i < t; i++) {    
    cin >> c[i];
    cin >> f[i];
    cin >> x[i];
  }
  
  for (int i = 0; i < t; i++) {
    rate = 2.0;
    totaltime = 0.0;
    
    while (0 == 0) {
    
      time1 = x[i]/rate;    
      time2 = c[i]/rate + x[i]/(rate + f[i]);
      
      //cout << time1;
      //cout << "  ";
      //cout << time2;
      //cout << "\n";
      
    
      if (time1 < time2) {
	totaltime += time1;
	
	cout << "Case #";
	cout << (i+1);
	cout << ": ";
	cout << setprecision(15) << totaltime;
	cout << "\n";      
	break;
      }
      
      totaltime += c[i]/rate;
    
      rate += f[i];
    
    }    
    
  }
  
  
}