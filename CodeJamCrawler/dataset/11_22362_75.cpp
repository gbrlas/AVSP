#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
    //freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
    
    int test;

    cin>>test;
    for(int times=1;times<=test;times++)
    {
        int n,mint=10000000,sum=0,xsum=0;

        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;

            cin>>a;
            mint=min(mint,a);
            sum+=a;xsum=xsum^a;
        }

        printf("Case #%d: ",times);
        if(xsum==0)
            cout<<sum-mint<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
