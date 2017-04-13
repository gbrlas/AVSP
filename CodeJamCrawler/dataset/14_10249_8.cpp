#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct frac{
  long long up;
  long long down;
};

long long stoi(string text){
  long long rez=0LL;
  for(int i=0;i<text.length();i++){
    rez*=10LL;
    rez+=long(text.at(i)-'0');
  }
  return rez;
}

long long gcd(long long a, long long b){
  if(b>a){long long tmp=b;b=a;a=tmp;}
  if(a%b == 0LL){return b;}
  return gcd(b,a%b);
}

bool manjsi(frac a, frac b){
  if(b.up==0 && b.down==0){return 0;}
  //cout << a.up << '/' << a.down << ' ' << b.up << '/' << b.down << endl;
  //cout << (a.up*b.down<=a.down*b.up) << endl;
  return (a.up*b.down<=a.down*b.up);
}

frac subtr(frac a, frac b){
  //cout << "substr\n";
  //cout << a.up << '/' << a.down << ' ' << b.up << '/' << b.down << endl;
  long long skup=(a.down*b.down)/*/gcd(a.down,b.down)*/;
  //cout << skup << '\n';
  frac kon;
  kon.down=skup;
  kon.up=(a.up*b.down)-(b.up*a.down);
  if(kon.up==0LL || kon.down==0LL){return kon;}
  //cout << gcd(kon.up,kon.down) << endl;
  kon.down=kon.down/gcd(kon.up,kon.down);
  kon.up=kon.up/gcd(kon.up,kon.down);
  //cout << "konsubstr\n";
  return kon;
}

int main(){
  //cout << gcd(1099511628000LL,1234803097600LL) << endl;
  int n;
  cin >> n;
  for(int stevec=1;stevec<=n;stevec++){
    string ulomek;
    cin >> ulomek;
    frac vhod;
    vhod.up=stoi(ulomek.substr(0,ulomek.find('/')));
    vhod.down=stoi(ulomek.substr(ulomek.find('/')+1,ulomek.length()-ulomek.find('/')-1));
    long long skp=gcd(vhod.up,vhod.down);
    vhod.up=vhod.up/skp;
    vhod.down=vhod.down/skp;
    //cout << vhod.up << '/' << vhod.down << endl; 
    long long neki=vhod.down;
    while(neki%2==0){neki/=2;}
    if(neki>1){cout << "Case #" << stevec << ": impossible" << '\n';continue;}
    frac moj;
    moj.up=1LL;
    moj.down=2LL;
    int globina=100;
    for(int i=1;i<=40;i++){
      while(manjsi(moj,vhod)){
	if(i<globina){globina=i;}
	vhod=subtr(vhod,moj);
      }
      moj.down*=2LL;
    }
    if(vhod.up==0 && globina<100){cout << "Case #" << stevec << ": " << globina << '\n';}else{cout << "Case #" << stevec << ": impossible" << '\n';}
  }
  return 0;
}