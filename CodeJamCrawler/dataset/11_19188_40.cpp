#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t,r;
    cin>>t;
    r=t;
    while(t--){
        int n,solve=0;
        long long to=0,sp=0;
        cin>>n;
        long long c[n];
        for(int i=0;i<n;i++){
            cin>>c[i];
            to+=c[i];
        }
        for(int i=1;i<=pow(2.0,n-1);i++){
            int bitmask=i,pos = n - 1,m=n;
            long long s=0,p1=0,p2=0;
            while(m--){
                if((bitmask & 1) == 1){
                    s+=c[pos];
                    p1^=c[pos];
                }
                else{
                    p2^=c[pos];
                }
                bitmask >>= 1;
                pos--;
            }
            if(p1==p2){
                s=(to-s)>s?(to-s):s;
                sp=sp>s?sp:s;
                solve=1;
            }
        }
        cout<<"Case #"<<r-t<<": ";
        if(solve==0)
        cout<<"NO\n";
        else
        cout<<sp<<endl;
    }
    return 0;
}

