#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int r,c;
char grid[52][52];

bool paint()
{
  for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
      {
	if(grid[i][j]=='#')
	  {
	    if(grid[i][j+1]=='#' && grid[i+1][j]=='#' && grid[i+1][j+1]=='#')
	      {
		grid[i][j]='/';
		grid[i][j+1]='\\';
		grid[i+1][j]='\\';
		grid[i+1][j+1]='/';
	      }
	    else
	      return false;
	  }
      }
  return true;
}

int main()
{

  int tt;
  cin>>tt;
  for(int t=1;t<=tt;t++)
    {
      cin>>r>>c;
      for(int i=0;i<r;i++)
	{
	  cin>>grid[i];
	  grid[i][c]='.';
	}
      bool possible=paint();
      cout<<"Case #"<<t<<":"<<endl;
      if(!possible)
	cout<<"Impossible"<<endl;
      else
	  for(int i=0;i<r;i++)
	    {
	      for(int j=0;j<c;j++)
		cout<<grid[i][j];
	      cout<<endl;
	    }
    }
}
