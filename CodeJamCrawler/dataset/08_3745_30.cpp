#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int c;
int main(){
    cin>>c;
    bool nprimes[1000002];
    nprimes[0]=1;
    nprimes[1]=1;
    for (int i=2;i<1000002;i++){
        if (nprimes[i]) continue;
        for (int j=i+i;j<1000002;j+=i) nprimes[j]=1;
    }
    for (int l=0;l<c;l++){
        unsigned long long a,b,p;
        cin>>a>>b>>p;
        unsigned long long n = b-a+1;
        unsigned long long s[n];
        for (unsigned long long i=0;i<n;i++) s[i]=i;
        unsigned long long nextp = p;
        while (nextp<=b){
            while (nprimes[nextp]) nextp++;
            bool first=true;
            unsigned long long m;
            for (unsigned long long x=0;x<n;x++){
                if ((x+a)%nextp!=0) continue;
                if (first){
                    m=s[x];
                    first=false;
                }else{
                    unsigned long long c=s[x];
                    for (unsigned long long y=0;y<n;y++)
                        if (s[y]==c) s[y]=m;
                }
            }
            nextp++;
        }
        bool v[n];
        for (unsigned long long i=0;i<n;i++) v[i]=0;
        unsigned long long ans = 0;
        for (unsigned long long i=0;i<n;i++){
            if (v[i]) continue;
            ans++;
            for (unsigned long long j=i;j<n;j++) if (s[j]==s[i]) v[j]=1;
        }
        cout<<"Case #"<<(l+1)<<": "<<ans<<endl;
    }
    return 0;
}
