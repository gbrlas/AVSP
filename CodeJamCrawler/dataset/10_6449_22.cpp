
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
         
using namespace std;

#define DEBUG_7
#define MAX_W 1001


void sortit(int *x,int first,int last,int  *y)
{
     int i,j,min_loc,temp;
     
     for(i=first;i<last;i++)
     {  min_loc=i;
        for(j=i+1;j<=last;j++)
         if(x[j] < x[min_loc])
            min_loc = j;
         
       if(min_loc == i)
          continue;
         
       temp=x[i];
       x[i]=x[min_loc];
       x[min_loc]=temp;
       
       temp=y[i];
       y[i]=y[min_loc];
       y[min_loc]=temp;
       
      
       }    
}


int main()
{
  long ci,cases;
  int wait4;
  int result;
  int wires,a[MAX_W],b[MAX_W];
  cin >> cases;

  for(ci=1;ci<=cases;ci++)
    {
    cin >> wires;
    for(int i=0;i<wires;i++)
        cin >>a[i]>> b[i];
     
     sortit(a,0,wires-1,b);
  
  /*   
     for(int i=0;i<wires;i++)
          cout << a[i] << " " << b[i] << "\n";
    */ 
     
     result =0;
     
     for(int i=0;i<wires;i++)
     {
       for(int j=i+1;j< wires;j++)
           if(b[j] < b[i])
              result++;
  
  }
  
  
     cout << "Case #"<< ci << ": ";


      cout << result << "\n";

    }





  //  cin >> wait4;
  return 0;

 }
