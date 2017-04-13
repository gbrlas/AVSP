#include <iostream>
#include <set>
using namespace std;

void solvecase(int index)
{
    int n,a[1000],b[1000];
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>a[i]>>b[i];
    int cnt=0;
    for(int i=0; i<n; ++i)
        for(int j=i+1; j<n; ++j)
            if((a[i]-a[j])*(b[i]-b[j])<0)
                cnt++;
    cout<<"Case #"<<index<<": "<<cnt<<endl;
}

int main(int argc, char *argv[])
{
    int t;
    cin>>t;
    for(int i=1; i<=t; ++i)
        solvecase(i);
    return 0;
}
