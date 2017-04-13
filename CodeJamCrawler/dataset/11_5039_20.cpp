#include <iostream>
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
int main()
{
    int tc;
    cin>>tc;
    int count=1;
    while (tc--)
    {
        cout<<"Case #"<<count++<<": ";
        int pd,pg;
        long long n;
        bool bisa = 1;
        cin>>n>>pd>>pg;
        int fpb1 = gcd(pd,100);
        int fpb2 = gcd(pg,100);
        int x = pd/fpb1;
        int y = 100/fpb1;
        if (n>100LL){}
        else
        {
            if (y>n) bisa=0;
        }
        int a, b;
        a = pg/fpb2;
        b = 100/fpb2;
        //selama a>0
        if (pg==0)
        {
            if (x>0) bisa=0;
        }
        else if (pg<100)
        {
            if (x==0) bisa=0;
        }
        else
        {
            if (pd<100) bisa=0;
        }
        if (bisa) cout<<"Possible"<<endl;
        else cout<<"Broken"<<endl;
    }
    return 0;
}
