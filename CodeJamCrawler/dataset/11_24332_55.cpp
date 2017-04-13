#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

int main()
{
     
     int test,n;
     int cb,cor;       //current positions of blue and orange bots
     int nb,nor;       // next positions of blue and orange bots
     int sb,sor;     // semaphores of blue and orange
     char c;
     char order[100];
     int o[100] = {0};
     int b[100] = {0};
     int x,i,j,k,p;
     int time;
     int cas;
     
     cin>>test;
     cas = 1;
     time = 0;
     while(test>0)
     {            
         cin>>n;
         i=0; j=0; k=0;
         time =0;
         
         while(n>0)
         {
             cin>>c;
             cin>>x;
             
             if(c == 'O') 
             {
                order[i]='O';
                i++;
                o[j]=x;
                j++;
             }
             else if(c=='B') 
             {
                order[i]='B';
                i++;
                b[k]=x;
                k++;
             }  
             n--;   
         }   
 /*        for(p=0;p<i;p++)
         cout<<order[p]<<"   ";
 
         cout<<endl;
         
         for(p=0;p<j;p++)
         cout<<o[p]<<"   ";
         
         cout<<endl;
         
         for(p=0;p<k;p++)
         cout<<b[p]<<"   ";

         cout<<endl;  */
         
//         cout<<i;         
         cor=1; cb=1;      // current positions of bots
         j=0; k=0;
         
         for(p=0;p<i;)
         {
              if (order[p]== 'O')
              {
                 sor = 1;
                 sb = 0;
              }
              else if (order[p]== 'B')
              {
                 sor = 0;
                 sb = 1;
              }
              
              nor = o[j];
              
              nb = b[k];
              
              if((nor-cor !=0) && (nor!=0) && (nb - cb !=0) && (nb!=0))   // M - M case
              {
                  if((nor-cor)>0)
                     cor ++ ;
                  else if((nor-cor)<0)
                     cor -- ;

                  if((nb-cb)>0)
                     cb ++ ;
                  else if((nb-cb)<0)
                     cb -- ;
                  
                  time ++ ;
              }
              
              else if(((nor-cor !=0) && (nor!=0) && (nb - cb ==0) && (sor==1) && (sb ==0)) || ((nb == 0) && (sor==1) && (sb ==0) && (nor-cor !=0) && (nor!=0)) )   // M - S case    
              { 
                  if((nor - cor )>0)
                     cor ++ ;
                  else if((nor - cor )<0)
                     cor -- ;

                  time ++ ;
              }
              
              else if((nor-cor !=0) && (nor!=0) && (nb - cb ==0) && (sb==1) && (sor ==0))   // M - P case
              {
                 if((nor - cor )>0)
                     cor ++ ;
                 else if((nor - cor )<0)
                     cor -- ;
                  
                  p++;      // button pushed
                  k ++ ;     // next position of blue is changed
                  time ++;
              }
              
              else if(((nor - cor ==0) && (sor==1) && (sb ==0) && (nb - cb ==0)) || ((nb == 0) && (sor==1) && (sb ==0)&& (nor - cor ==0)) )          // P - S case
              {
                 p ++ ;     // button pushed
                 j ++ ;     // next position of orange is changed
                 time ++ ;
              }
              
              else if((nb-cb !=0) && (nb!=0) && (nor - cor ==0) && (sor==1) && (sb ==0))   //  P - M case
              {
                 if((nb - cb )>0)
                     cb ++ ;
                  
                 else if((nb - cb )<0)
                     cb -- ;
                  
                  p++;      // button pushed
                  j ++ ;     // next position of orange is changed
                  time ++;
              }
              
              else if(((nb-cb !=0) && (nb!=0) && (nor - cor ==0) && (sb==1) && (sor ==0)) || ((nor == 0) && (sor==0) && (sb ==1) && (nb-cb !=0) && (nb!=0)) )   // S - M case    
              { 
                  if((nb - cb )>0)
                     cb ++ ;
                  else if((nb - cb )<0)
                     cb -- ;

                  time ++ ;
              }
              
              else if( ((nb - cb ==0) && (sb==1) && (sor ==0) && (nor - cor ==0)) || ((nor == 0) && (sor==0) && (sb ==1) &&  (nb - cb ==0)) )            // S - P case
              {
                 p ++ ;     // button pushed
                 k ++ ;     // next position of blue is changed
                 time ++ ;
              }
         }
         cout<<"Case #"<<cas<<": "<<time<<endl ;    
                  
                  
         cas ++;  
         test--;
     }
     //system("pause");
     return 0;
}
     
