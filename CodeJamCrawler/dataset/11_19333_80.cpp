#include <iostream>

using namespace std;

int main()
{
  int tt;
  cin>>tt;
  for(int t=1;t<=tt;t++)
    {
      int n;
      cin>>n;
      int min=1234567;
      int sum=0;
      int x;
      int zero=0;
      while(n--)
	{
	  cin>>x;
	  sum+=x;
	  if(x<min)
	    min=x;
	  zero^=x;
	}
      if(zero==0)
	cout<<"Case #"<<t<<": "<<sum-min<<endl;
      else
	cout<<"Case #"<<t<<": NO"<<endl;
    }
}
