#include<iostream>

using namespace std;

main()
{
      int test,cas=1;
      int n,l,h;
      int a[100];
      bool flag ;
      cin>>test;
      
      while(test)
      {
         int ans;
         cin>>n;
         cin>>l;
         cin>>h;
         flag =false;
         int i,j;
         
         for(i=0;i<n;i++)
           cin>>a[i];
           
         for(i=l;(i<=h && !flag);++i)
         {
            for(j=0;j<n;++j)
            {
               if((a[j]%i)&&(i%a[j]))
               {
                 break ;
               }
            }
            if(j==n)
            {
               flag = true;       
               ans = i;
            }  
         }
           
           
         if(flag)
         cout<<"Case #"<<cas<<": "<<ans<<endl;        
         else 
         cout<<"Case #"<<cas<<": NO"<<endl;
         
         cas ++;
         test--;     
      }
}
