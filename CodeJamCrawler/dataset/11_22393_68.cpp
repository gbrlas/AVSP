#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
typedef long long int64;
using namespace std;

bool v[1010000]={false};
int num[200000]={0},tot=0;

void prime(int nn)
{
    for(int i=2;i<=nn/i;i++)
    {
        if(v[i]==false)
        {
            for(int j=i*i;j<=nn;j+=i)
                v[j]=true;
        }
    }
    for(int i=2;i<=nn;i++)
        if(v[i]==false)
            num[tot++]=i;
}

int main()
{
    freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
    //freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
    int test;

    cin>>test;
    prime(1000000);
    //for(int i=0;i<tot;i++) cout<<num[i]<<endl;
    for(int times=1;times<=test;times++)
    {
        int64 n;
        int res=1;

        cin>>n;
        for(int i=0;i<tot;i++)
        {
            int64 tmp=n;

            if(tmp<num[i]) break;
            res--;
            while(tmp>=num[i])
            {
                res++;
                tmp/=num[i];
            }
        }
        if(n==1) res--;
        printf("Case #%d: %d\n",times,res);
    }
    return 0;
}

