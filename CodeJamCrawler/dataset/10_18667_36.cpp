#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  int t;
  int l,p,c;
    int caseno=1;
    int cnt,cnt2,a;
    cin>>t;
    while(t--)
    {
      cin>>l>>p>>c;
      cnt=0;
      while(l<p)
      {
	l*=c;
	cnt++;
      }
      a = 1;
      cnt2=0;
      while(a<cnt)
      {
	a*=2;
	cnt2++;
      }
      cout<<"Case #"<<caseno<<": "<<cnt2<<endl;
      caseno++;
    }
  
  
  return 0;
}