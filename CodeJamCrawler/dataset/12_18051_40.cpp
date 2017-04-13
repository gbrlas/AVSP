#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int u[2200000];

int main()
{
    freopen("out.txt","w",stdout);
    int a,b,nc;
    cin>>nc;
    for(int cc=1;cc<=nc;++cc) {
        cin>>a>>b;
        int ans=0;
        for(int n=a;n<=b;++n) {
            memset(u,0,sizeof(u));
            int t = 1, m = 0;
            while(t<=n) t*=10, ++m;
            int q = n;
            t/=10;
            for(int j=1;j<m;++j)
            {
                int e=q%10;
                q=q/10+e*t;
                if(q>n&&q<=b&&u[q]==0) {
                    u[q]=1;
                    ++ans;
                }
            }
        }
        cout<<"Case #"<<cc<<": "<<ans<<endl;
    }
    return 0;
}
