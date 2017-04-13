#include<iostream>
using namespace std;

int main()
{
    long long int t,t1,n,a[1100];
    long long int i,j,check,min,sum;
    cin>>t;
    t1=t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(i=0;i<n;i++)
        {     cin>>a[i];
              sum+=a[i];
        }
        min=a[0];
        check=a[0];
        for(i=1;i<n;i++)
        {
              check=check^a[i];
              if(a[i]<min)
                 min=a[i];
        }
        if(check==0)
           cout<<"Case #"<<t1-t<<": "<<sum-min<<endl;
        else
           cout<<"Case #"<<t1-t<<": NO"<<endl;
                       
    }
    return(0);
}
