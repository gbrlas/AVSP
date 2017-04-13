#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int dist[3123];
int n,lboosters,c;
typedef unsigned long long big;
big thours;
int booster1,booster2;

big f1()
{
  big t=0;
  for(int i=0;i<booster1;i++)
    t+=dist[i]+dist[i];

  //booster1
  if(t>=thours)//booster1 is ready
    t+=dist[booster1];
  else if(t+dist[booster1]+dist[booster1]<thours)//booster1 is not ready at all
    t+=dist[booster1]+dist[booster1];
  else//booster1 will be ready during trip
    {
      t+=(thours-t)/2+dist[booster1];
    }      
  for(int i=booster1+1;i<n;i++)
    t+=dist[i]+dist[i];
  return t;
}

big f2()
{
  big t=0;
  for(int i=0;i<booster1;i++)
    t+=dist[i]+dist[i];

  //booster1
  if(t>=thours)//booster1 is ready
    t+=dist[booster1];
  else if(t+dist[booster1]+dist[booster1]<thours)//booster1 is not ready at all
    t+=dist[booster1]+dist[booster1];
  else//booster1 will be ready during trip
    t+=(thours-t)/2+dist[booster1];
      
  for(int i=booster1+1;i<booster2;i++)
    t+=dist[i]+dist[i];

  //booster2
  if(t>=thours)//booster2 is ready
    t+=dist[booster2];
  else if(t+dist[booster2]+dist[booster2]<thours)//booster2 is not ready at all
    t+=dist[booster2]+dist[booster2];
  else//booster2 will be ready during trip
    t+=(thours-t)/2+dist[booster2];

  for(int i=booster2+1;i<n;i++)
    t+=dist[i]+dist[i];
  
  return t;
}

int main()
{
  int tt;
  cin>>tt;
  for(int t=1;t<=tt;t++)
    {
      int sum=0;
      cin>>lboosters>>thours>>n>>c;
      
      for(int i=0;i<c;i++)
	cin>>dist[i];
      for(int i=c;i<n;i++)
	dist[i]=dist[i-c];
      for(int i=0;i<n;i++)
	sum+=dist[i];

      big minans=123456789;
      if(lboosters==0)minans=sum+sum;
      else if(lboosters==1)
	{
	  for(int i=0;i<n;i++)
	    {
	      booster1=i,booster2=-1;
	      minans=min(minans,f1());
	    }
	}
      else if(lboosters==2)
	{
	  for(int i=0;i<n;i++)
	    for(int j=i+1;j<n;j++)
	      {
		booster1=i,booster2=j;
		minans=min(minans,f2());
	      }	  
	}
      cout<<"Case #"<<t<<": "<<minans<<endl;
    }
}
