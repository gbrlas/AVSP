#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
  int tt;
  cin>>tt;
  for(int t=1;t<=tt;t++)
    {
      int possible=0;
      int n,pd,pg;
      cin>>n>>pd>>pg;
      for(int d=1;d<=n&&!possible;d++)
	{
	  int vd=pd*d;
	  if(vd%100!=0)continue;
	  vd/=100;
	  for(int g=d;g<=12345&&!possible;g++)
	    {
	      int vg=pg*g;
	      if(vg%100!=0)continue;
	      vg/=100;
	      int dd=d-vd,dg=g-vg;
	      if(vg>=vd && dg>=dd)
		{
		  possible=1;
		}
	    }
	}
      if(possible)
	cout<<"Case #"<<t<<": Possible"<<endl;
      else
	cout<<"Case #"<<t<<": Broken"<<endl;
    }
}
