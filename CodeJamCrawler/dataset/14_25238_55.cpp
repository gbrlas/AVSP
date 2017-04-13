#include<iostream>
#include<algorithm>

inline int dwar(double a[],double b[],int l)
{   --l;
    int b1=0,b2=0,t1=l,t2=l;
    int count=0;
    while(t1>=b1)
    {
        if(b[t2]>a[t1])
        {
            ++b1;
            --t2;
        }
        else
        {   --t1;
            --t2;
            ++count;
        }
    }
 return count;
}

inline int war(double a[],double b[],int l)
{   --l;
    int b1=0,b2=0,t1=l,t2=l;
    int count=0;
    while(t1>=b1)
    {
        if(a[t1]>b[t2])
        {
            ++b2;
            --t1;
            ++count;
        }
        else
        {
            --t2;
            --t1;
        }


    }
 return count;
}
using namespace std;
int main()
{
    int t;
    cin>>t;
    int c;
    for(int i=0;i<t;i++)
        {

        cin>>c;
        double n[c],k[c];
        for(int j=0;j<c;j++)
        cin>>n[j];
        for(int j=0;j<c;j++)
        cin>>k[j];
        sort(n,n+c);
        sort(k,k+c);
        //for(int j=0;j<c;j++)
        //cout<<n[j]<<" ";
       // cout<<endl;
       // for(int j=0;j<c;j++)
       // cout<<k[j]<<" ";
     //   cout<<endl;
        int ans=war(n,k,c);
        int ans1=dwar(n,k,c);
        cout<<"Case #"<<i+1<<": "<<ans1<<" "<<ans<<endl;
        }
    return 0;
}
