#include <iostream>

using namespace std;


int main()
{
    int t;
    cin>>t;
    int *milli=new int[t];
    int *radius=new int[t];
    for(int a=0; a < t; ++a)
    {
      cin>>radius[a];
      cin>>milli[a];
    }
    
    
    for(int a=0; a < t; ++a)
    {
      int results=0;
      int paint=milli[a];
      for(int b=radius[a]+1;;b+=2)
      { 
        int previous=(b-1)*(b-1);
        int current=(b*b)-previous;
        
        if(current > paint)
        {
          break;
        }
        
        
        paint-=current;
        
        
        
        if(paint==0)
        {
            ++results;
            break;
        }      
        
        if(paint > 0)
        {
          ++results;
        }
        
        
      }
      

    cout<<"Case #"<<a+1<<": "<<results<<endl;
} 

          
cin.get();
cin.ignore();    




    
    
}  

