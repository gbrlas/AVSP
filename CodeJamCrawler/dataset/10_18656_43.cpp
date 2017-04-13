#include<iostream>
using namespace std;

int main()
{
  int t,n,k;
  int x=1;
 int i,y;
 int cnt=1;
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    x = 1;
    for(i=0;i<n;i++)
	x=x<<1;
    x-=1;	
   // cout<<"x - "<<x<<endl;
    y = x&k;
//     cout<<"y - "<<y<<endl;
    cout<<"Case #"<<cnt<<": ";
    cnt++;
    if(y==x)
      cout<<"ON"<<endl;
    else
      cout<<"OFF"<<endl;
  }
  return 0;
}