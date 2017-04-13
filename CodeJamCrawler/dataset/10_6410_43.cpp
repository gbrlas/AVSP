#include <iostream>
//#include <stdlib.h>

//#define DEBUG_S 1
#define MAX_GROUPS  1100
using namespace std;

#ifdef DEBUG_S
void printBits(long x)
{
    long b;
    if(!x) return;

     b = x & 1;
     
     printBits(x>>1);
 
     if(b) std::cout << "1";
         else std::cout << "0";
}   

#endif 



int main()
{ 
    long cases,ci,n,k,result=1,i,j; 
    unsigned long state=0,power=1,new_state,new_power,temp_state,next_power,top_bit;
    int x;
    

 std::cin >> cases;
    
    
    
   for(ci=1;ci<=cases;ci++)
   {  std::cin >> n >> k;
      top_bit = 1 << (n-1);
      state =0;
      power=top_bit;
      
      for(i=1;i<=k;i++)
      {
         new_state = state ^ power;
         temp_state = new_state;
         next_power = top_bit >> 1;
         new_power = top_bit;
         
         while ( top_bit & temp_state) 
         {
               new_power = new_power | next_power;
               next_power = next_power >> 1;
               temp_state = temp_state << 1;
         }
               
        power =new_power;
        state = new_state;                           

  
#ifdef DEBUG_S
  std::cout << "\n Snap : ***" ;
  std::cout << "\n State :";
  printBits(state);
  std::cout << "\n Power :";
  printBits(power); 
#endif

        }



#ifdef DEBUG_S

#endif


if( power & state & 1 )
std::cout << "Case #"<<ci<<": "<<"ON\n";
else 
std::cout << "Case #"<<ci<<": "<<"OFF\n";

 
  }


//cin >> x;

return 0;
}
