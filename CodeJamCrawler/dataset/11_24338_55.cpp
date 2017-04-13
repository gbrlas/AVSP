#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

typedef struct s1{
        char cbase1;
        char cbase2;
        char nbase;
        }comb ;
        
typedef struct s2{
        char obase1;
        char obase2;
        }opp;
        
int main(){
    
    int test,cas;
    comb c1[37];
    opp o1[29] ;
    
    char* a;
    
    int c,n,d;
    int i,j,k,t;       // i in a , j in cbase , k in obase , t in final
    cas=1;
    int count ;      // no. of elements in the final array
    char final[101];
    
    c=0; n=0; d=0;
    i=0; j=0; k=0; t=0;
    count = 0;
    char e1,e2,e3,e4;
    int combined,opposed ;
    
    
    cin>>test ;
    while(test>0)
    {
         c=0; n=0; d=0;
         i=0; j=0; k=0; t=0;
         count = 0;
    
         cin>>c;
         for(i=0;i<c;i++)
         {
             cin>>c1[i].cbase1 ;
             cin>>c1[i].cbase2 ;
             cin>>c1[i].nbase ;
         }            
           
         cin>>d;
         for(i=0;i<d;i++)
         {
             cin>>o1[i].obase1 ;
             cin>>o1[i].obase2 ;
         }

         cin>>n;
         a = (char*) malloc(sizeof(char)*n);
         for(i=0;i<n;i++)
         {
             cin>>a[i];
         }
         
         for(i=0;i<n;i++)
         {
            combined = 0; opposed = 0;
            if(count==0)
            {
                final[t] = a[i];
                t ++;
                count ++ ;            
            }
            else 
            {
                e1 = a[i];
                e2 = final[t-1];
                for(j=0;j<c;j++)
                {
                    if( ((c1[j].cbase1==e1) && (c1[j].cbase2==e2)) || ((c1[j].cbase1==e2) && (c1[j].cbase2==e1)) )             
                    {
                           final[t-1] = c1[j].nbase;
                           combined = 1;
                    }
                }
                
                if(combined == 0)                       // if not combined
                {
                    e3 = a[i];
                    for(k=0;k<d;k++)
                    {
                        if((o1[k].obase1 == e3))
                        {
                            e4 = o1[k].obase2 ;
                            for(int x=0;x<count;x++)
                            {
                               if (final[x]==e4)
                               {
                                  count = 0;
                                  t = 0 ;  
                                  opposed = 1 ;               
                               }        
                            }                 
                        }
                        
                        else if((o1[k].obase2 == e3))
                        {
                            e4 = o1[k].obase1 ;
                            for(int x=0;x<count;x++)
                            {
                               if (final[x]==e4)
                               {
                                  count = 0;
                                  t = 0 ;  
                                  opposed = 1 ;               
                               }        
                            }                 
                        }
                    }
                }
                
                if((combined ==0) && (opposed == 0))          // if not combined or opposed
                {
                      final[t] = e1 ;
                      t ++ ;
                      count ++ ;       
                }
            }
         }
         
         cout<<"Case #"<<cas<<": "<<"["; 
         
         for(i=0;i<count-1;i++)
         {
            cout<<final[i]<<", ";
         }
         
         if(count>0)
            cout<<final[count-1] ;
            
         cout<<"]"<<endl ;
          
         cas ++;        
         test--;             
         free(a);
    }
    
    return 0;
}




