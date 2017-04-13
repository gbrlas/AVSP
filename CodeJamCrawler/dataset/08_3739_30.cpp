#include <iostream>
#include <algorithm>
using namespace std;
int t;
int main(){
    cin>>t;
    for (int l=0;l<t;l++){
        unsigned long long n,a,b,c,d,x0,y0,m;
        cin>>n>>a>>b>>c>>d>>x0>>y0>>m;
        unsigned long long x[n],y[n];
        x[0]=x0;y[0]=y0;
        for (int i=1;i<n;i++){
            x[i]=(a*x[i-1]+b)%m;
            y[i]=(c*y[i-1]+d)%m;
        }
        unsigned long long ans = 0;
        for (int i=0;i<n-2;i++){
            for (int j=i+1;j<n-1;j++){
                if (x[i]==x[j]&&y[i]==y[j]) continue;
                for (int k=j+1;k<n;k++){
                    if (x[i]==x[k]&&y[i]==y[k]) continue;
                    if (x[j]==x[k]&&y[j]==y[k]) continue;
                    if ((x[i]+x[j]+x[k])%3==0&&(y[i]+y[j]+y[k])%3==0)
                        ans++;
                }
            }
        }
        cout<<"Case #"<<(l+1)<<": "<<ans<<endl;
    }
    return 0;
}
