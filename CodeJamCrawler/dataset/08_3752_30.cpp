#include <iostream>
#include <algorithm>
using namespace std;
long n,t,k;
long add(long p){
    if (p+1==k) return 0;
    else return p+1;
}
int main(){
    cin>>t;
    for (int l=0;l<t;l++){
        cin>>k>>n;
        long d[n];
        for (long i=0;i<n;i++) cin>>d[i];
        long cards[k];
        for (long i=0;i<k;i++) cards[i]=0;
        long c = 0;
        long p = 0;
        while (c<k){
            long cc = c;
            while (cc>0){
                if (cards[p]==0) cc--;
                p = add(p);   
            }
            while (cards[p]!=0) p = add(p);
            cards[p]=(++c);
        }
        cout<<"Case #"<<(l+1)<<":";
        for (long i=0;i<n;i++) cout<<" "<<cards[d[i]-1];
        cout<<endl;
    }
    return 0;
}
