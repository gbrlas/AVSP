#include <stdio.h>
using namespace std;

int pas,fux[60][60],i,j,n,m,a[60][60],b[60][60],morcha,vig,t,tt,f,k,u,l;

void wav(int x,int y)
{
   fux[x][y]=1;
    if (x==0 || x==n+1 || y==0 || y==m+1) return;
     pas++;		
	if (b[x][y]>0) return;
	
	
	if (fux[x-1][y-1]==0)  wav(x-1,y-1);
	if (fux[x-1][y]==0)    wav(x-1,y);
	if (fux[x-1][y+1]==0)  wav(x-1,y+1);
	if (fux[x][y-1]==0)    wav(x,y-1);
	if (fux[x][y+1]==0)    wav(x,y+1);
	if (fux[x+1][y-1]==0)  wav(x+1,y-1);
	if (fux[x+1][y]==0)    wav(x+1,y);
	if (fux[x+1][y+1]==0)  wav(x+1,y+1);
	
}

void abaa()
{
	int i,j;
	
	if (a[2][2]==1 && a[2][4]==1)
	 {
	 	i=1;
	 	j=1;
	 }
	
	
	 for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
	   b[i][j]=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
	   
	  
	 for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++) 
	    if (b[i][j]==0 && a[i][j]==0)
	     {
	     	if (morcha==1) break;
	          pas=0;	
	          wav(i,j);
               if (pas==f) morcha=1;		   	
	     }
	     
	     
   	 for (u=0;u<=n+1;u++)
	  for (l=0;l<=m+1;l++) 
        fux[u][l]=0;
  
	
}


void go(int x,int y,int z)
{
  if (x>n || y>m) return;
  
  if (morcha==1) return;
      
  	
    if (z<f)
	 {
	  a[x][y]=0;
      if (x+y==n+m && z==f-1) abaa(); else
      if (y==m) go(x+1,1,z+1); else
      go(x,y+1,z+1);
      
      if (morcha==1) return;
      
     } 
     
     a[x][y]=1;
      
      if (x+y==n+m && z==f) abaa(); else
      if (y==m) go(x+1,1,z); else
      go(x,y+1,z);
     
     
     if (morcha==1) return;
      
     
}


main()
{
	
	
	freopen ("dito.in","r",stdin);
	freopen ("dito.out","w",stdout);
	
	 scanf ("%d",&t);
	 
	  tt=t;
	   
	    
	    while (t--)
	     {
	 scanf ("%d%d%d",&n,&m,&k);
	 
	      
	       vig=0;
	       morcha=0;
	       
	       
	       f=n*m-k;
	        
	        if (n==1 || m==1 || f==1)
	         {
	         printf ("Case #%d:\n",tt-t);
	           for (i=1;i<=n;i++)
			    {
			      for (j=1;j<=m;j++)
				   if (i+j==2) printf ("c"); else
				   if (i+j<=f+1) printf ("."); else
				    printf ("*");
				    printf ("\n");
				}
				   	
	           continue;	
	         }
	        
	        go(1,1,0);
	        
	          printf ("Case #%d:\n",tt-t);
			   
	        if (morcha==0)
	        {
	       printf ("Impossible\n");
	       
	     	 continue;
	        }
	        
	        
     	 for (i=1;i<=n;i++)
    	   {
		     for (j=1;j<=m;j++)
			  if (a[i][j]==0)
			   {
			   	 if (vig==0 && b[i][j]==0) {printf ("c"); vig=1;} else
					printf ("."); 
			   } else printf ("*");
			 
			    printf ("\n");
           }
	        
	     }
	
	
	
	
}
