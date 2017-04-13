#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<cstring>
#include<iomanip>

#define ll long long int
#define ull unsigned long int

#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)

#define sl(i) scanf("%lld",&i)
#define psl(i) printf("%lld ",i)
#define pal(i) printf("%lld\n",i)

#define pb push_back
#define fr(i,s,n) for(int i=s;i<n;i++)

#define De_bug 0
#define pdeb(s,i) if(De_bug)cout<<"DEBUG "<<s<<" "<<i<<endl;

#define MOD 1000000007

using namespace std;

double C, F, X;

double getTime(double c, double f, double x)
{
    double timePassed = 0;
    while(1)
    {
        double timeWithCurrF = x/f;
        double timeWithForeSee = c/f + x/(f+F);

        if(timeWithCurrF <= timeWithForeSee)
        {
            timePassed += timeWithCurrF;
            return timePassed;
        }
        timePassed += c/f;
        f += F;
    }
}

int main()
{
    int t;
    s(t);
    fr(i,1,t+1)
    {
        cin >> C >> F >> X;
        printf("Case #%d: %.7lf\n", i, getTime(C,2,X));
    }
}
