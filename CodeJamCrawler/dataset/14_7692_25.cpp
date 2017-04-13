#include<iostream>
#include<cstdio>
using namespace std;
int main()
 {
    double c,f,x,m,r;
    int t;
    cin>>t;	
    for(int k=0;k<t;k++)
    {  m=0;
     cin>>c;cin>>f;cin>>x;
     r=2;
     while(1)
      {  if((x/r)<((x/(r+f))+(c/r)))
		  { 
			  m+=(x/r);
			  break; 
			  }
	 else
		{	m+=c/r;
			r+=f;
        }
  }
     printf("Case #%d: %0.7f\n",k+1,m);
    }
	 return 0;
 }
