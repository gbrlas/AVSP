 
 #include <stdlib.h>
 #include <string.h>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <map>
 #include <queue>
 using namespace std;
 
 int main()
 {
    freopen( "A-large.in", "r", stdin );
    freopen( "A-large.out", "w", stdout );   
     int cas,n,i,j,tem,total,cas1,t;
     int num[50];
     char c;
     scanf("%d",&cas1);
     cas=0;
     while( cas++<cas1 )
     {
        scanf("%d",&n);
        scanf("%c",&c);
        memset( num , 0 , sizeof(num) );
        for( i=1 ; i<=n ; i++ ) 
        {
         for( j=1 ; j<=n ; j++ ) 
         {
           scanf("%c",&c);
           if( c=='1' ) num[i]=j;
         }
         scanf("%c",&c);
        } 
        total=0;
        for( i=1 ; i<=n-1 ; i++ )
        {
           for( j=i ; j<=n ; j++ ) 
             if( num[j]<=i ) { tem=j ; break; }
           for( j=tem ; j>i ; j-- )
           {
              t=num[j];
              num[j]=num[j-1];
              num[j-1]=t;
              total++;
           }
        }
        printf("Case #%d: %d\n",cas,total);
     }
     return(0);
 }
