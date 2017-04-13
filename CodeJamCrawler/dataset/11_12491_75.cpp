#include<iostream>
#include<cmath>
using namespace std;
int t,i,B,O,l,j,b,o,p;
char x;
int main(){
  for(cin>>t;i++<t;cout<<"Case #"<<i<<": "<<max(b,o)<<endl)
    for(cin>>l,B=O=1,b=o=j=0;j++<l;x-'B'?o=max(b,o+abs(O-p))+1,O=p:(b=max(o,b+abs(B-p))+1,B=p))
      cin>>x>>p;
  return 0;
}