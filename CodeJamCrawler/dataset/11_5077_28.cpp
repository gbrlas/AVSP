// seraph template //
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
long long gcd (long long a, long long b)
{
    long long c;
    while (true)
    {
        c = a%b;
        if (c==0) return b;
        a = b;
        b = c;
    }
}
long long lcm(long long a, long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    long long tc;
    cin>>tc;
    long long arr[200];
    long long count=1;
    
    bool ar[10001];
    while (tc--)
    {
        memset(ar,0,sizeof(bool));
        long long n,l,h;
        cin>>n>>l>>h;
        for (int i=0;i<n;i++)cin>>arr[i];
        cout<<"Case #"<<count++<<": ";
        int ada=0;
        for (int i=l;i<=h;i++)
        {
            bool gagal=0;
            for (int j=0;j<n;j++)
            {
                if (i>arr[j])
                {
                    if (i%arr[j]!=0) {gagal=1;break;}
                }
                else
                {
                    if (arr[j]%i!=0){gagal=1;break;}
                }
            }
            if (gagal==0)
            {
                ada=1;
                cout<<i<<endl;
                break;
            }
        }
        
        if (!ada) cout<<"NO"<<endl;
        //else cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
