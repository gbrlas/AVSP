#include<iostream>
#include<cstdio>
using namespace std;
int main()
{unsigned long long a,b,k,t;
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        unsigned long long ans = 0;
        cin>>a>>b>>k;
        for (int i=0; i<a; i++)
        {for (int j=0; j<b; j++)
            {if ((i&j) < k)
                 ans++;
                }}
        printf("Case #%d: ",p);
        cout << ans << endl;
    }
    return 0;
}
