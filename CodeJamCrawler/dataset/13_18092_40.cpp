#include<iostream>
#include<cmath>


using namespace std;
int check_palindrome(long long int n)
{

    
             
    long long int temp = n;
    long long int rem,sum=0;
    
    while(n!=0)
    {
               rem = n%10;
               sum = sum*10 +rem;
               
               n = n/10;
    }
    if(sum == temp)return 1;
    else return 0;

}
             
int main()
{
          long long int t,I=1,arr[100000],count=0,lower,arrlength=0,upper,f=0,f2=0;
          
          for(long long int i=1;i<=100000000;i++)
                    {f=f2=0;
                         f = check_palindrome(i);
                       
                         if(f==1){f2 = check_palindrome(i*i);}
                         if(f2==1){arr[arrlength]=i;arrlength++;}
                           
                    }
                    
                    
                    
          cin>>t;
          for(int x=0;x<t;x++)
          {
                    count=0;
                    long long int f=0,f2=0;
                    long long int p1=0,p2=0;
                    cin>>lower;
                    cin>>upper;
                    long long int l = long(sqrt(float(lower)));
                    double l1=sqrt(float(lower));
                    
                    if(l1-l>0)l++;
                    long long int u = long(sqrt(float(upper)));
                  
                    for(long long int i=0;i<arrlength;i++)
                    {
                             if(arr[i]>=l){p1=i;break;}
                    //if(arr[i]>l){p1=i+1;cout<<p1<<endl;break;}
                    }
                    for(long long int i=0;i<=arrlength;i++)
                    {
                     if(arr[i]==u){p2=i;break;}
                     else if(arr[i]>u){p2=i-1;break;}
                     
                    }
                                        
                             
                
                    cout<<"Case #"<<I<<": "<<p2-p1+1<<endl;
                    I++;
          }
          
          return 0;
}
                    
                             
     
