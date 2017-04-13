#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int a[1200];

int main()
{
    freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
    //freopen("D-large.in","r",stdin);freopen("D-large.out","w",stdout);
    int test;
    
    cin>>test;
    for(int times=1;times<=test;times++)
    {
        int n,sum=0;

        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]!=i+1) sum++;
        }

        printf("Case #%d: %d.000000\n",times,sum);
    }

    return 0;
}
