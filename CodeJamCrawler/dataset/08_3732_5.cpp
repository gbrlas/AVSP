#include <iostream>
#include <algorithm>
using namespace std;
int n,t;
int main(){
    cin>>t;
    for (int l=0;l<t;l++){
        cin>>n;
        int a[n],b[n];
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n;i++) cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        int ans = 0;
        for (int i=0;i<n;i++) ans += (a[i]*b[n-i-1]);
        cout<<"Case #"<<(l+1)<<": "<<ans<<endl;
    }
    return 0;
}
