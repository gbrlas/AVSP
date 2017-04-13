#include <sstream>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool palindrom(long long cifra){
  stringstream ss;
  string s;
  ss << cifra;
  ss >> s;
  bool tr00=1;
  for(int i=0;i<round(s.length()/2);i++){
    if(s.at(i)!=s.at(s.length()-i-1)){tr00=0; break;}
  }
  return tr00;
}

int main(){
  int st;
  cin >> st;
  for(int primer=1;primer<st+1;primer++){
    long long prva,druga;
    cin >> prva >> druga;
    if(long(sqrt(prva))==sqrt(prva)){prva=long(sqrt(prva));}else{prva=long(sqrt(prva))+1;}
    druga=long(sqrt(druga));
    long rez=0;
    //cout << prva << " " << druga << endl;
    for(int i=prva;i<druga+1;i++){
      if(palindrom(long(i))){
	if(palindrom(i*i)){rez++;/* cout << i << endl;*/}
      }
    }
    cout << "Case #" << primer << ": " << rez << endl;
  }
  return 0;
}