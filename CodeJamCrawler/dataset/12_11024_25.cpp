#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOWN(i, a, b) for(int i=a; i>=b; i--)

char d[26]={'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int test;
string s;

int main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d\n", &test);
    FOR(t, 1, test) {
           getline(cin, s);
           FOR(i, 1, s.length()) if (s[i-1]!=' ') s[i-1]=d[s[i-1]-'a'];
           printf("Case #%d: ", t);
           cout << s << endl;
           }
    return 0;
}
