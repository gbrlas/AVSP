#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int t;
  cin >> t;
  cout << fixed << setprecision(7);
  for(int stevec=0;stevec<t;stevec++){
    double c,f,x;
    cin >> c >> f >> x;
    double pridelava=2;
    double cajt=0;
    double rez=1000000;
    while(1){
      double tren=cajt+x/pridelava;
      if(tren<rez){rez=tren;}else{break;}
      cajt+=c/pridelava;
      pridelava+=f;
    }
    cout << "Case #" << stevec+1 << ": " << rez << '\n';
  }
  return 0;
}