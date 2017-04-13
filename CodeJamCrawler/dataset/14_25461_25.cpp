#include <iostream>
#include <stdio.h>
using namespace std;


int t,t1,i;
double tim2,tim1,c,f,x;

main()
{

  freopen ("cookie.in","r",stdin);
  freopen ("cookie.out","w",stdout);
  

  cin>>t;
   t1=t;
    
     while (t--)
     {
       
        cin>>c>>f>>x;
        
         tim1=x/2;
         
         
         for (i=1;;i++)
          {
             tim2=tim1;
             
             tim2=tim2-x/( 2 + f*(i-1) );            
             tim2=tim2+x/( 2 + f*i );
             tim2=tim2+c/( 2 + f*(i-1) );
             
             if (tim2>tim1) break;
             tim1=tim2;          
          }
          
          printf ("Case #%d: %.7f\n",t1-t,tim1);
          
     }
  
}
