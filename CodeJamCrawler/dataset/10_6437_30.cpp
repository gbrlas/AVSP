
#include <iostream>

using namespace std;

#define DEBUG_7
#define MAX_N 51

int main()
{
  long ci,cases;
  int wait4;
  long result,obstacles;
  long n,k,b,t;
  long loc[MAX_N];
  long spe[MAX_N];
  int can_do[MAX_N];
  
  
  cin >> cases;

  for(ci=1;ci<=cases;ci++)
    { 
  cin >> n >> k >> b >> t;
    
     for(int i=0;i<n;i++)
         cin >> loc[i];
  
  for(int i=0;i<n;i++)
         cin >> spe[i];

  for(int i=0;i<n;i++)
      { 
     //     if (  (b - loc[i]) / spe[i] <= t)
          if (  (b - loc[i])   <= t * spe[i])
          can_do[i]=1;
         else            can_do[i]=0;
      }    

/*
  for(int i=0;i<n;i++)
   cout << can_do[i];
  */    
   result=0;
   obstacles=0;
   
   
   for(int i=n-1;i>=0;i--)
      {  if (can_do[i] == 0)
          { obstacles ++;continue;}
          
          
               result += obstacles;
               k--;
           if(k ==0 ) break;    
      }             
        
      
  
     cout << "Case #"<< ci << ": ";


     if(k ==0)
      cout << result << "\n";
      else cout << "IMPOSSIBLE\n";

    }




  //  cin >> wait4;
  return 0;

 }
