#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

void solvecase(int index){
    int f[50],v,n,k,b,t;
    cin>>n>>k>>b>>t;
    for(int i=0; i<n; ++i)
        cin>>f[i];
    for(int i=0; i<n; ++i)
    {
        cin>>v;
        f[i]+=v*t;
    }
    int cnt=0,p=0;
    for(int i=n-1; i>=0&&p<k; --i){
        if(f[i]>=b) {
            ++p;
            cnt+=n-p-i;
        }
    }
    cout<<"Case #"<<index<<": ";
    if(p==k)
        cout<<cnt<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
}

int main(int argc, char *argv[])
{
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i)
        solvecase(i);
    return 0;
}
