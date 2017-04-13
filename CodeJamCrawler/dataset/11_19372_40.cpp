#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int freq[11234];
int n,l,h;

int findfreq()
{
  for(int f=l;f<=h;f++)
    {
      int i;
      for(i=0;i<n;i++)
	if(freq[i]%f!=0 && f%freq[i]!=0)
	  break;
      if(i==n)return f;
    }
  return 0;
}

int main()
{
  int tt;
  cin>>tt;
  for(int t=1;t<=tt;t++)
    {
      cin>>n>>l>>h;
      for(int i=0;i<n;i++)
	cin>>freq[i];
      int f=findfreq();
      cout<<"Case #"<<t<<": ";
      if(f==0)
	cout<<"NO"<<endl;
      else
	cout<<f<<endl;
    }
}
