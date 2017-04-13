#include <iostream>
using namespace std;

#define MAXN 1005

int a[MAXN],b[MAXN],c[MAXN];

void solvecase (int index) 
{
    int r,k,n;
    cin>>r>>k>>n;
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<n; ++i){
        int j=i,sum=0,d=0;
        while(1){
            if(d>=n||sum+a[j]>k) break;
            sum+=a[j];
            j=(j+1)%n;
            ++d;
        }
        b[i]=sum;
        c[i]=j;
    }
    long long all=0;
    int i=0;
    while(r--){
        all+=b[i];
        i=c[i];
    }
    cout<<"Case #"<<index<<": "<<all<<endl;
}

int main(int argc, char *argv[])
{
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i)
        solvecase(i);
    return 0;
}
