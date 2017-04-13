#include<iostream>

#include<algorithm>

using namespace std;

int main()
{
    long t;
    cin>>t;
    
    for(long j=0;j<t;j++)
    {
              long a,n;
              
              cin>>a>>n;
              
             
              
              long ar[n],count=0,scount=0;
              
              for(long i=0;i<n;i++)
                       cin>>ar[i];
              
              if(a==1)
              {
                
                      cout<<"Case #"<<j+1<<": "<<n<<endl;
                      continue;
              }
                       
              sort(ar,ar+n);
              
              
              
              for(long i=0;i<n;i++)
              {
                       A:
                       if(a>ar[i])
                       {
                                  if(scount < (n-i))
                                  {
                                            count=count+scount;
                                            a=a+ar[i];
                                            scount=0;
                                  }
                                  else
                                  {          
                                             count=count+n-i;
                                             break;
                                  }
                       }
                            
                       else if(a<=ar[i] && i==n-1)
                       {
                                 count++;
                                 break;
                       }
                                    
                       else if(a<=ar[i])         
                       {
                            a=a+a-1;
                            scount++;
                            goto A;
                         }
              }
              
              cout<<"Case #"<<j+1<<": "<<count<<endl;
    }
              return 0;
}
              
                            
                            
                            
                            
                       
