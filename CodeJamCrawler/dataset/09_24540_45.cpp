#include <iostream>
#define FOR(i,a,b) for(long i = a; i <= b; i++)
#define DOWN(i,a,b) for(long i = a; i >= b; i--)
using namespace std;
long n,a[30],d[30],c[30],top;

void solve()
{
     memset(d,0,sizeof(d));
     scanf("%ld",&n);
     top = 0;
     while (n)
     {
           top++;
           a[top] = n % 10;
           n = n / 10;
     };
     FOR(i,1,top) c[i] = a[i];
     FOR(i,1,top) a[i] = c[top - i + 1];
     long sl = 0;
     FOR(i,1,top)
        if (!a[i]) sl++;
        else d[a[i]]++;
     bool ok = false;
     FOR(i,1,top-1)
       if (a[i] < a[i+1]) ok = true;
     if (ok)
     {
         DOWN(i,top - 1,1)
         if (a[i] < a[i+1])
         {
              long j = i + 1;
              while (j < top && a[j+1] > a[i]) j++;
              long tg = a[j];a[j] = a[i];a[i] = tg;
              memset(d,0,sizeof(d));
              FOR(j,i+1,top) d[a[j]]++;
              FOR(j,i+1,top)
                  FOR(k,0,9)
                      if (d[k]) 
                         {
                             a[j] = k;
                             d[k]--;
                             break;
                         };
              break;
         };
         FOR(i,1,top) cout << a[i];
         cout << endl;
     }
    else
    {
        sl++;
        FOR(k,1,9)
        if (d[k])
        {
            a[1] = k;
            d[k]--;
            break;
        };
        d[0] = sl;
        FOR(i,2,top+1)
        FOR(k,0,9)
        if (d[k])
        {
            a[i] = k;
            d[k]--;
            break;
        };
        FOR(i,1,top+1) cout << a[i];
        cout << endl;
    };  
};
int main()
{
    freopen("TEST3.IN","r",stdin);
    freopen("TEST.OUT","w",stdout);
    long ntest;
    scanf("%ld",&ntest);
    FOR(test,1,ntest)
    {
         cout << "Case #" << test << ": ";
         solve();
    };
    return 0;
};
