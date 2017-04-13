#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t,x=1;
    double C,F,X,ans,cur,rate;
    cin>>t;
    cout << fixed;
    while(t--)
    {
        cin>>C>>F>>X;
        ans=0;
        cur=0;
        rate = 2;
        while(1)
        {
            if((C/rate) + (X/(rate+F)) < (X/rate) )
            {
                ans += (C/rate) ;
                rate = rate + F;
            }
            else
            {
                ans += (X/rate) ;
                break;
            }
        }
        cout<<setprecision(8)<<"Case #"<<x++<<": "<<ans<<endl;

    }
    return 0;
}
