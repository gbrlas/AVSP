 #include <stdlib.h>
 #include <cmath>
 #include <string.h>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <map>
 #include <queue>
 using namespace std;
 
 int main()
 {
    freopen( "D-small-attempt1.in", "r", stdin );
    freopen( "D-small-attempt1.out", "w", stdout );   
    int cas1,cas,n,i,j,k,i1,j1;
    int x[50],y[50],r[50];
    int up,down,left,right;
    double min,tem,max,tem1;
    
    scanf("%d",&cas1);
    cas=0;
    while( cas++<cas1 ) 
    {
       scanf("%d",&n);
       up=0;down=1000;left=1000;right=0;
       for( i=1 ; i<=n ; i++ )
          scanf("%d%d%d",&x[i],&y[i],&r[i]);
     if( n==3 )
     {
      min=(double)((sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]))+r[1]+r[2])/2);
      tem=(double)((sqrt((x[1]-x[3])*(x[1]-x[3])+(y[1]-y[3])*(y[1]-y[3]))+r[1]+r[3])/2); 
      if( tem<min ) min=tem;
      tem=(double)((sqrt((x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]))+r[3]+r[2])/2); 
      if( tem<min ) min=tem;
      };
      if( n==2 ) 
      {
          min=(double)((sqrt((x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]))+r[1]+r[2])/2);
          if( r[1]>r[2] ) tem=r[1];else tem=r[2];
          if( tem<min ) min=tem;
      }
      if( n==1 )
      {
          min=r[1];
      }
       printf("Case #%d: %.6lf\n",cas,min);
    }
    return(0);
}
