#include <cstdio>
#include <iostream>
#include <cstring>
typedef long long int64;
using namespace std;

int64 gcd(int64 a,int64 b)
{
    int64 c=a%b;

    while(c)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main()
{
    freopen("A-small-attempt0_001.in","r",stdin);freopen("A-small-attempt0_001.out","w",stdout);
    //freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    int test;
    
    scanf("%d",&test);
    for(int times=1;times<=test;times++)
    {
        int64 n,pd,pg,qd,qg,d;

        cin>>n>>pd>>pg;
        
        int64 t1=gcd(pd,(int64)100);
        
        pd/=t1;qd=100/t1;;
        
        cout<<"Case #"<<times<<": ";
        if((!((pg==0 && pd!=0) || (pd!=qd && pg==100))) && qd<=n)
            cout<<"Possible"<<endl;
        else
            cout<<"Broken"<<endl;
    }
    return 0;
}
