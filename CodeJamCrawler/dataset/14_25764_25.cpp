#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;


double C,F,X;

int main()
{
    freopen("C:\\Users\\admin\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\admin\\Desktop\\output.txt","w",stdout);
    int t;
    cin>>t;
    int ctr=0;
    while(t--)
    {
              ctr++;
               double currentrate=2;
               double future_rate=0;
              cin>>C;
              cin>>F;
              cin>>X;
              
              double fact_totaltime=X/currentrate;
              future_rate=currentrate+F;
              double timeSpent=C/currentrate;
             double not_totaltime=X/(future_rate) + timeSpent;
             // int timeSpent=250;
           //   printf("%0.7f\n",not_totaltime); 
           //   printf("%0.7f\n",fact_totaltime); 
              while((not_totaltime<fact_totaltime)&&(C<X))
              {
                  //  printf("%0.7f\n",C/currentrate);                             
                    currentrate=future_rate;
                    
                    fact_totaltime=not_totaltime;
                    future_rate=currentrate+F;
                    timeSpent+=C/currentrate;
                    not_totaltime=X/(future_rate)+timeSpent;
             //      printf("%0.7f this  \n",X/(future_rate));  
                    
                    }
                    
               printf("Case #%d: %0.7lf \n",ctr,fact_totaltime);
             //  printf("%0.7f\n",not_totaltime);
              
                    
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
              
              
              
              
              
              
              }
    
       fclose(stdin);
            fclose(stdout);
    
    
    getch();
    return 0;
    
}
