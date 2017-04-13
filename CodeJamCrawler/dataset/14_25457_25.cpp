#include <iostream>
#include <stdio.h>
using namespace std;

int p,x,a[6][6],i,j,t,t1,b[20],ans;

main()
{
	 
	 freopen ("dito.in","r",stdin);
	 freopen ("dito.out","w",stdout);
	 
	
	  cin>>t;
	    t1=t;
	     
	      while (t--) 
	       {
	       	 cin>>x;
	       	  
	       	  for (i=1;i<=4;i++)
	       	   for (j=1;j<=4;j++)
	       	     cin>>a[i][j];
	       	  
		      for (i=1;i<=4;i++)
	       	    b[a[x][i]]=1;
				   
		    	 cin>>x; 
	       	  for (i=1;i<=4;i++)
	       	   for (j=1;j<=4;j++)
	       	     cin>>a[i][j];
	       	  
		      for (i=1;i<=4;i++)
	           if (b[a[x][i]]==1)
			    {
			    	ans++;
			    	p=a[x][i];
			    }		      
			    
			    cout<<"Case #"<<t1-t<<": ";
	       	  if (ans==0) cout<<"Volunteer cheated!"<<endl;
	       	  if (ans==1) cout<<p<<endl;
	       	  if (ans>1) cout<<"Bad magician!"<<endl;
	       	  
	       	
	       	  for (i=1;i<=16;i++)
	       	    b[i]=0;
	       	    ans=0;
	       	    
	       	
	       }
	
}
