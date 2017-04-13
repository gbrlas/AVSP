#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
  int T;
  cin>>T;
  for(int t=1;t<=T;t++)
    {
      set<pair<int,int> >sol;
      int a,b;
      cin>>a>>b;
      for(int i=a;i<=b;++i)
	{
	  char tmp[50];
	  sprintf(tmp,"%d",i);
	  string s(tmp);
	  int len=s.size();
	  sprintf(tmp,"%d%d",i,i);
	  s=tmp;
	  for(int j=1;j<len;++j)
	    {
	      string x=s.substr(j,len);
	      int val=atoi(x.c_str());
	      if(val<i)
		if(a<=val && val<=b)
		  sol.insert(make_pair(val,i));
	    }
	}
      cout<<"Case #"<<t<<": "<<sol.size()<<endl;
    }
  return 0;
}
