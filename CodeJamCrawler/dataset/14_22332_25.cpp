#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("archivob.in","r",stdin);
//    freopen("fileb.txt","w",stdout);
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++ )
    {
            double c,f,x,cps=2;
            cin>>c>>f>>x;
            double ans=0;
            while(true)
            {
                double t1 = x/cps;
                double t2 = c/cps + x/(cps+f);
                if(t1 < t2)
                {

//                    cout<<"Case #"<<i+1<<": "<<ans+t1<<endl;
                    printf("Case #%d: %.7f\n",i+1,ans+t1);
                    break;
                }

                ans+=c/cps;
                cps+=f;
            }
    }
}
