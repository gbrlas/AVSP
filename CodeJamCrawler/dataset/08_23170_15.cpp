#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
 int te,z;
 cin>>te;
 for(z=0;z<te;z++)
 {
  int p,k,l;
  cin>>p>>k>>l;
  long long int i,el; vector <int> fre;
  for(i=0;i<l;i++)
  {
   cin>>el;                 
   fre.push_back(el);
  }
  sort(fre.begin(),fre.end());
  vector <int> key;
  int j=0,q,d=1;
  for(i=0;(i<p)&&(j<l);i++)
  {
   for(q=0;(q<k)&&(j<l);q++)
   {
    key.push_back(i+1);
    j=j+1;
   }
   d=d+1;
  }
  long long int ret=0;
  for(i=0;i<l;i++)
  ret=ret+fre[l-1-i]*key[i];
  
  cout<<"Case #"<<z+1<<": "<<ret<<"\n";
  key.clear();
  fre.clear();
 }
}
