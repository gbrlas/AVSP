#include<iostream>
using namespace std;
int t,i,x,s,n,a,m;
int main(){
  for(cin>>t;i++<t;cout<<"Case #"<<i<<": ",x?cout<<"NO"<<endl:cout<<s-m<<endl)
    for(cin>>n,x=s=0,m=1e6;n--;x^=a,s+=a,m=m<a?m:a)
      cin>>a;
  return 0;
}