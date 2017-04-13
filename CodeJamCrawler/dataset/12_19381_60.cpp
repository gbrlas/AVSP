#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;



int main()
{
  int tt;
  cin>>tt;
  for(int t=0;t<tt;t++)
    {
      int n,s,p;
      cin>>n>>s>>p;
      int minimum=3*p-3;
      int count=0,count2=0;
      for(int i=0;i<n;i++)
	{
	  int x;
	  cin>>x;
	  if(x>minimum)
	    {
	      count++;
	      //cout<<"x="<<x<<" "<<"minimum="<<minimum<<endl;
	    }
	  else if(x>=3*p-4 && p>1)
	    count2++;
	}
      //cout<<count<<" "<<count2<<endl;
      cout<<"Case #"<<t+1<<": "<<count+min(count2,s)<<endl;
    }
  return 0;
}
