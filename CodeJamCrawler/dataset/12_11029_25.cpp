#include <iostream>
#include <cstdio>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOWN(i, a, b) for(int i=a; i>=b; i--)

int a, b, test;

int check(int a, int b) 
{
    int cs1, cs2, cs3;
    if (b<10) return 0;
    if (b<100) {
               cs1=a/10; cs2=a%10;
               if (cs1+cs2*10==b) return 1; else return 0;
               }
    if (b<1000) {
                cs1=a/100; cs2=(a-cs1*100)/10; cs3=a%10;
                if (cs3*100+cs1*10+cs2==b) return 1;
                if (cs2*100+cs3*10+cs1==b) return 1;
                return 0;
                }
    return 0;
}

int main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) {
           cin >> a; 
           cin >> b;
           int count=0;
           FOR(i, a, b-1)
             FOR(j, i+1, b) if (check(i, j)) count++;
           printf("Case #%d: ", t);
           cout << count << endl;
           }
    return 0;
}
