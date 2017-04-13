#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std ;

void comb1(int c[], int n, int& b, int &max)
{
   int t,pile,tot;
   for(t=0;t<n;t++)
   {
       pile = 0 ;
       tot = 0 ;
       //----
       for(int k=0;k<n;k++)
       {
          if(k!=t)
          {
            pile = pile ^ c[k];
            tot = tot + c[k];
          }
       }
       
       if(pile==c[t])
       {
          b = 1;           
          if((tot>=c[t]) && (tot>=max))
            max = tot;
          else if ((c[t]>=tot) && (c[t]>=max))
            max = c[t];
       }
       //-----   
   }
} 
 
void comb2(int c[], int n, int& b, int &max)
{
   int t1,t2,pile1,tot1,pile2,tot2;
   for(t1=0;t1<n;t1++)
   {
      for(t2=t2+1;t2<n;t2++)
      {
         if(t2 == t1)                   //we don't want it 
            continue;
         else 
         {
            pile1= 0; pile2=0; tot1=0; tot2=0;
            
            pile1 = pile1 ^ c[t1] ^ c[t2];
            tot1 = tot1 + c[1] + c[2] ;
            
            for(int k=0;k<n;k++)
            {
               if((k!=t1) && (k!=t2))
               {
                 pile2 = pile2 ^ c[k];
                 tot2 = tot2 + c[k];
               }
            }
            
            if(pile1==pile2)
            {
               b = 1;           
               if((tot1>=tot2) && (tot1>=max))
                  max = tot1;
               else if ((tot2>=tot1) && (tot2>=max))
                  max = tot2;
            }
         }
      }
   }
} 

void comb3(int c[], int n, int& b, int &max)
{
   int t1,t2,t3,pile1,tot1,pile2,tot2;
   for(t1=0;t1<n;t1++)
   {
      for(t2=t2+1;t2<n;t2++)
      {
         if(t2 == t1)                   //we don't want it 
            continue;
         for(t3=t2+1;t3<n;t3++)
         {
             if(t3 == t2 || t3 == t1)
                 continue;                 //ditto
         
             else 
             {
                pile1= 0; pile2=0; tot1=0; tot2=0;
                
                pile1 = pile1 ^ c[t1] ^ c[t2] ^ c[t3];
                tot1 = tot1 + c[1] + c[2] + c[t3] ;
                
                for(int k=0;k<n;k++)
                {
                   if((k!=t1) && (k!=t2) && (k!=t3))
                   {
                     pile2 = pile2 ^ c[k];
                     tot2 = tot2 + c[k];
                   }
                }
                
                if(pile1==pile2)
                {
                   b = 1;           
                   if((tot1>=tot2) && (tot1>=max))
                      max = tot1;
                   else if ((tot2>=tot1) && (tot2>=max))
                      max = tot2;
                }
             }
         
         }
      }
   }
} 

void comb4(int c[], int n, int& b, int &max)
{
   int t1,t2,t3,t4,pile1,tot1,pile2,tot2;
   for(t1=0;t1<n;t1++)
   {
      for(t2=t2+1;t2<n;t2++)
      {
         if(t2 == t1)                   //we don't want it 
            continue;
         for(t3=t2+1;t3<n;t3++)
         {
             if(t3 == t2 || t3 == t1)
                 continue;                 //ditto
             for(t4=t3+1;t4<n;t4++)
             {
                 if(t4 == t1 || t4 ==t2 || t4 == t3)
                      continue ;        
                 else 
                 {
                    pile1= 0; pile2=0; tot1=0; tot2=0;
                    
                    pile1 = pile1 ^ c[t1] ^ c[t2] ^ c[t3] ^ c[t4];
                    tot1 = tot1 + c[1] + c[2] + c[t3] + c[t4];
                    
                    for(int k=0;k<n;k++)
                    {
                       if((k!=t1) && (k!=t2) && (k!=t3) && (k!=t4))
                       {
                         pile2 = pile2 ^ c[k];
                         tot2 = tot2 + c[k];
                       }
                    }
                    
                    if(pile1==pile2)
                    {
                       b = 1;           
                       if((tot1>=tot2) && (tot1>=max))
                          max = tot1;
                       else if ((tot2>=tot1) && (tot2>=max))
                          max = tot2;
                    }
                 }
                 
             }
         }
      }
   }
} 

void comb5(int c[], int n, int& b, int &max)
{
   int t1,t2,t3,t4,t5,pile1,tot1,pile2,tot2;
   for(t1=0;t1<n;t1++)
   {
      for(t2=t2+1;t2<n;t2++)
      {
         if(t2 == t1)                   //we don't want it 
            continue;
         for(t3=t2+1;t3<n;t3++)
         {
             if(t3 == t2 || t3 == t1)
                 continue;                 //ditto
             for(t4=t3+1;t4<n;t4++)
             {
                 if(t4 == t1 || t4 ==t2 || t4 == t3)
                      continue ;
                 for(t5=t4+1;t5<n;t5++)
                 {
                     if(t5 == t1 || t5 ==t2 || t5 == t3 || t5 == t4)
                        continue ;    
                           
                     else 
                     {
                        pile1= 0; pile2=0; tot1=0; tot2=0;
                        
                        pile1 = pile1 ^ c[t1] ^ c[t2] ^ c[t3] ^ c[t4] ^ c[t5];
                        tot1 = tot1 + c[1] + c[2] + c[t3] + c[t4] + c[t5] ;
                        
                        for(int k=0;k<n;k++)
                        {
                           if((k!=t1) && (k!=t2) && (k!=t3) && (k!=t4) && (k!=t5))
                           {
                             pile2 = pile2 ^ c[k];
                             tot2 = tot2 + c[k];
                           }
                        }
                        
                        if(pile1==pile2)
                        {
                           b = 1;           
                           if((tot1>=tot2) && (tot1>=max))
                              max = tot1;
                           else if ((tot2>=tot1) && (tot2>=max))
                              max = tot2;
                        }
                     }
                     
                 }
                 
             }
         }
      }
   }
} 

void comb6(int c[], int n, int& b, int &max)
{
   int t1,t2,t3,t4,t5,t6,pile1,tot1,pile2,tot2;
   for(t1=0;t1<n;t1++)
   {
      for(t2=t2+1;t2<n;t2++)
      {
         if(t2 == t1)                   //we don't want it 
            continue;
         for(t3=t2+1;t3<n;t3++)
         {
             if(t3 == t2 || t3 == t1)
                 continue;                 //ditto
             for(t4=t3+1;t4<n;t4++)
             {
                 if(t4 == t1 || t4 ==t2 || t4 == t3)
                      continue ;
                 for(t5=t4+1;t5<n;t5++)
                 {
                     if(t5 == t1 || t5 ==t2 || t5 == t3 || t5 == t4)
                        continue ;    
                     for(t6=t5+1;t6<n;t6++)
                     {
                         if(t6 == t1 || t6 ==t2 || t6 == t3 || t6 == t4 || t6 == t5)
                              continue ;
                           
                         else 
                         {
                            pile1= 0; pile2=0; tot1=0; tot2=0;
                            
                            pile1 = pile1 ^ c[t1] ^ c[t2] ^ c[t3] ^ c[t4] ^ c[t5] ^ c[t6];
                            tot1 = tot1 + c[1] + c[2] + c[t3] + c[t4] + c[t5] + c[t6] ;
                            
                            for(int k=0;k<n;k++)
                            {
                               if((k!=t1) && (k!=t2) && (k!=t3) && (k!=t4) && (k!=t5) && (k!=t6))
                               {
                                 pile2 = pile2 ^ c[k];
                                 tot2 = tot2 + c[k];
                               }
                            }
                            
                            if(pile1==pile2)
                            {
                               b = 1;           
                               if((tot1>=tot2) && (tot1>=max))
                                  max = tot1;
                               else if ((tot2>=tot1) && (tot2>=max))
                                  max = tot2;
                            }
                         }
                         
                     }
                     
                 }
                 
             }
         }
      }
   }
} 

void comb7(int c[], int n, int& b, int &max)
{
   int t1,t2,t3,t4,t5,t6,t7,pile1,tot1,pile2,tot2;
   for(t1=0;t1<n;t1++)
   {
      for(t2=t2+1;t2<n;t2++)
      {
         if(t2 == t1)                   //we don't want it 
            continue;
         for(t3=t2+1;t3<n;t3++)
         {
             if(t3 == t2 || t3 == t1)
                 continue;                 //ditto
             for(t4=t3+1;t4<n;t4++)
             {
                 if(t4 == t1 || t4 ==t2 || t4 == t3)
                      continue ;
                 for(t5=t4+1;t5<n;t5++)
                 {
                     if(t5 == t1 || t5 ==t2 || t5 == t3 || t5 == t4)
                        continue ;    
                     for(t6=t5+1;t6<n;t6++)
                     {
                         if(t6 == t1 || t6 ==t2 || t6 == t3 || t6 == t4 || t6 == t5)
                              continue ;
                         for(t7=t6+1;t7<n;t7++)
                         {
                             if(t7 == t1 || t7 ==t2 || t7 == t3 || t7 == t4 || t7 == t5 || t7 == t6)
                                  continue ;
                             else 
                             {
                                pile1= 0; pile2=0; tot1=0; tot2=0;
                                
                                pile1 = pile1 ^ c[t1] ^ c[t2] ^ c[t3] ^ c[t4] ^ c[t5] ^ c[t6] ^ c[t7];
                                tot1 = tot1 + c[1] + c[2] + c[t3] + c[t4] + c[t5] + c[t6] + c[t7] ;
                                
                                for(int k=0;k<n;k++)
                                {
                                   if((k!=t1) && (k!=t2) && (k!=t3) && (k!=t4) && (k!=t5) && (k!=t6) && (k!=t7))
                                   {
                                     pile2 = pile2 ^ c[k];
                                     tot2 = tot2 + c[k];
                                   }
                                }
                                
                                if(pile1==pile2)
                                {
                                   b = 1;           
                                   if((tot1>=tot2) && (tot1>=max))
                                      max = tot1;
                                   else if ((tot2>=tot1) && (tot2>=max))
                                      max = tot2;
                                }
                             }
                             
                         }
                         
                     }
                     
                 }
                 
             }
         }
      }
   }
} 


int main()
{
    int test,cas;
    int n,l;
    int *c;
    int max = 0;
    int b = 0;
    cas = 1;  
    cin>>test;
    
    while(test>0)
    {
       max = 0;
       b = 0;
       cin>>n;
       
       c = (int*)malloc (sizeof(int)*n) ;
       
       l = n/2;
       
       for(int j=0;j<n;j++)
          cin>>c[j];
      //    
//       for(int y=0;y<n;y++)
//          f = f ^ c[y];
//       
       if(l>=1)
         comb1(c,n,b,max);
         
       if(l>=2)
         comb2(c,n,b,max) ;
       
       if(l>=3)
         comb3(c,n,b,max);
         
       if(l>=4)
         comb4(c,n,b,max) ;
         
       if(l>=5)
         comb5(c,n,b,max);
         
       if(l>=6)
         comb6(c,n,b,max) ;
         
       if(l>=7)
         comb7(c,n,b,max);
       
       if(b==0)
          cout<<"Case #"<<cas<<": "<<"NO"<<endl ;   
       else 
          cout<<"Case #"<<cas<<": "<<max<<endl ;   

       cas ++ ;
       test --;
       
    }    
    //system("pause");
    return 0;
}
