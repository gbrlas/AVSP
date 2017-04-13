#include <cstdio>
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
      int nteams;
      cin>>nteams;

      char mat[nteams+1][nteams+1];
      
      for(int i=0;i<nteams;i++)
	cin>>mat[i];
      
      double matches[nteams];
      int victories[nteams];
      double wp[nteams];
      double owp[nteams];
      double oowp[nteams];
      double rpi[nteams];

      for(int i=0;i<nteams;i++)
	{
	  matches[i]=0;
	  victories[i]=0;
	  wp[i]=0;
	  owp[i]=0;
	  oowp[i]=0;
	  for(int j=0;j<nteams;j++)
	    {
	      if(mat[i][j]!='.')
		matches[i]++;
	      if(mat[i][j]=='1')
		victories[i]++;
	    }
	  wp[i]=victories[i]/matches[i];
	}
      for(int i=0;i<nteams;i++)
	{
	  for(int j=0;j<nteams;j++)
	    {
	      if(mat[i][j]=='.')continue;
	      if(mat[i][j]=='1')owp[i]+=victories[j]/(matches[j]-1);
	      if(mat[i][j]=='0')owp[i]+=(victories[j]-1)/(matches[j]-1);
	    }
	  owp[i]/=matches[i];
	}

      printf("Case #%d:\n",t);
      for(int i=0;i<nteams;i++)
	{
	  for(int j=0;j<nteams;j++)
	    {
	      if(mat[i][j]!='.')
		oowp[i]+=owp[j];
	    }
	  oowp[i]/=matches[i];
	  rpi[i]=0.25*wp[i]+0.5*owp[i]+0.25*oowp[i];
	  printf("%.12f\n",rpi[i]);
	}
    }
}
