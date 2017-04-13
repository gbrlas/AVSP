#include <iostream>
//#include <stdlib.h>
//#include <conio.h>
//#define DEBUG_P 1
#define MAX_GROUPS  1100
using namespace std;

long calc_cash(long k,long r,long ng,long *gsize)
{
     long next_g[MAX_GROUPS];
     long g_score[MAX_GROUPS];
     long cur,next;
     long score,cash;
     int i,run_begin;
     

     
     score=gsize[0];
     cur=0;
     next =  1 % ng;
     
     while(next != cur)
     {
                if( k >= gsize[next]+ score )
                       { score += gsize[next];
                        next =(next+1) % ng;
                        }
                else break;
                
     
     }

      if( next == cur)
        {
                return score * r;
                
        }
     
     g_score[0]= score;
     next_g[0]= next;
         
    for( i=1;i<ng;i++)
    {
         score = g_score[i-1]  - gsize[i-1];
         next = next_g[i-1];
         cur = i;    
         
         if(cur == next)
                     { score = gsize[i];
                        next = (cur + 1) % ng;
                      }
                  
      while(next != cur)
           {
                if( k >= gsize[next]+ score )
                       { score += gsize[next];
                        next=(next+1) % ng;
                        }
                else break;
     
                }        
                 g_score[i]= score;
                 next_g[i]= next;
    
     }
     
 #ifdef DEBUG_P
 
  std::cout << "\n scores : ";
 
   for( i=0;i<ng;i++)
       std::cout << g_score[i] <<  "  ";
       
       std::cout << "\n next_group_begin :";

    for( i=0;i<ng;i++)
         std::cout << next_g[i] << "  ";    
    
 #endif    
    
 
 
     run_begin = 0;
     cash=0;
     for( i = 1; i <=r; i++) 
     { 
          cash += g_score[run_begin];
          run_begin = next_g[run_begin];
          }

     return  cash;         
     

}
     
      

int main()
{   long cases,k,r,n;
    long ci,gi;
    long cash=0;
    long gsize[MAX_GROUPS];
        
    std::cin >> cases;
    
    
    
   for(ci=1;ci<=cases;ci++)
   {
              std::cin >> r >> k >> n;
             
         for(gi=0;gi<n;gi++)
            std::cin  >> gsize[gi];
 #ifdef DEBUG_P
        std::cout << "\n group : ";
        for(gi=0;gi<n;gi++)
            std::cout   << gsize[gi] << " ";           
 #endif
        
          cash = calc_cash(k,r,n,gsize);
          std::cout << "Case #"<<ci<<": "<< cash<< "\n";                                         
   }
    
//     getch();
      return 0;

}
