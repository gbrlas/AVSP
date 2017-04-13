#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int stevec=0;stevec<t; stevec++){
    int st;
    cin >> st;
    vector <double> moj (st,0);
    vector <double> njegov (st,0);
    for(int i=0;i<st;i++){
      cin >> moj[i];
    }
    for(int i=0;i<st;i++){
      cin >> njegov[i];
    }
    vector <bool> nucano(st,0);
    vector <double> moj2=moj;
    sort(moj2.begin(),moj2.end());
    int rez=0;
    for(int i=0;i<st;i++){
      for(int j=0;j<st;j++){
	if(moj2.at(j)>njegov.at(i) && !nucano.at(j)){nucano.at(j)=1;rez++;break;}
      }
    }
    cout << "Case #" << stevec+1 << ": " << rez << ' ';
    vector <bool> nucano2(st,0);
    sort(njegov.begin(),njegov.end());
    rez=st;
    for(int i=0;i<st;i++){
      for(int j=0;j<st;j++){
	if(moj.at(i)<njegov.at(j) && !nucano2.at(j)){nucano2.at(j)=1;rez--;break;}
      }
    }
    cout << rez << '\n';
  }
  return 0;
}