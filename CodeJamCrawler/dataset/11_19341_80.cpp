#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  int tt;
  cin>>tt;
  for(int t=1;t<=tt;t++)
    {
      int n;
      cin>>n;
      int sum=0;
      for(int i=1;i<=n;i++)
	{
	  int x;
	  cin>>x;
	  if(x==i)continue;
	  sum++;
	}
      cout<<"Case #"<<t<<": "<<sum<<".000000"<<endl;
    }
}
