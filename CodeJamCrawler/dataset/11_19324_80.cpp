#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int main()
{
  int tt;
  cin>>tt;
  for(int t=1;t<=tt;t++)
    {
      char combine[255][255];
      memset(combine,0,sizeof(combine));

      int c;
      cin>>c;
      char clist[4];
      for(int i=0;i<c;i++)
	{
	  cin>>clist;
	  char x=clist[0],y=clist[1];
	  combine[x][y]=combine[y][x]=clist[2];
	}

      int opposed[255][255];
      memset(opposed,0,sizeof(opposed));

      int d;
      cin>>d;
      char dlist[3];
      for(int i=0;i<d;i++)
	{
	  cin>>dlist;
	  char x=dlist[0],y=dlist[1];
	  opposed[x][y]=opposed[y][x]=1;
	}

      int listsize;
      cin>>listsize;
      char in[listsize+1];
      cin>>in;
      vector<char>out(1,' ');
      int baseinlist[255];
      memset(baseinlist,0,sizeof(baseinlist));
      for(int i=0;i<listsize;i++)
	{
	  char x=in[i];
	  char y=out.back();
	  if(combine[x][y])
	    {
	      out.back()=combine[x][y];
	      baseinlist[y]--;
	    }
	  else
	    {
	      int found=0;
	      for(char j='A';j<='Z';j++)
		{
		  if(baseinlist[j]>0 && opposed[j][x])
		    {
		      found=1;
		      break;
		    }
		}
	      if(found)
		{
		  out.clear();
		  out.push_back(' ');
		  memset(baseinlist,0,sizeof(baseinlist));
		}
	      else
		{
		  out.push_back(x);
		  baseinlist[x]++;
		}
	    }
	}
      
      cout<<"Case #"<<t<<": [";
      if(out.size()>=2)
	cout<<out[1];
      for(int i=2;i<out.size();i++)
	cout<<", "<<out[i];
      cout<<']'<<endl;
    }
  return 0;
}
