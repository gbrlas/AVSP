#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int main()
{
    freopen("out.txt","w",stdout);
    int a,b,nc;
    cin>>nc;
    for(int cc=1;cc<=nc;++cc) {
        cin>>a>>b;
        int ans=0;
        for(int n=a;n<=b;++n) {
            set<int> ss;
            int t = 1, m = 0;
            while(t<=n) t*=10, ++m;
            int q = n;
            t/=10;
            for(int j=1;j<m;++j)
            {
                int e=q%10;
                q=q/10+e*t;
                if(q>n&&q<=b&&ss.count(q)==0) {
                    ss.insert(q);
                    ++ans;
                }
            }
        }
        cout<<"Case #"<<cc<<": "<<ans<<endl;
    }
    return 0;
}
