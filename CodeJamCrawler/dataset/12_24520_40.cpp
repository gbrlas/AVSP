#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORN(i,a,b) for(int i=a;i<b;i++)
using namespace std;

string s1,s2;
int d[1000];

int main() {
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    d[(int)'y'] = (int)'a';
    d[(int)'n'] = (int)'b';
    d[(int)'f'] = (int)'c';
    d[(int)'i'] = (int)'d';
    d[(int)'c'] = (int)'e';
    d[(int)'w'] = (int)'f';
    d[(int)'l'] = (int)'g';
    d[(int)'b'] = (int)'h';
    d[(int)'k'] = (int)'i';
    d[(int)'u'] = (int)'j';
    d[(int)'o'] = (int)'k';
    d[(int)'m'] = (int)'l';
    d[(int)'x'] = (int)'m';
    d[(int)'s'] = (int)'n';
    d[(int)'e'] = (int)'o';
    d[(int)'v'] = (int)'p';
    d[(int)'z'] = (int)'q';
    d[(int)'p'] = (int)'r';
    d[(int)'d'] = (int)'s';
    d[(int)'r'] = (int)'t';
    d[(int)'j'] = (int)'u';
    d[(int)'g'] = (int)'v';
    d[(int)'t'] = (int)'w';
    d[(int)'h'] = (int)'x';
    d[(int)'a'] = (int)'y';
    d[(int)'q'] = (int)'z';
    int _;
    cin >> _;
    char A[1111];
    gets(A);
    FOR(t,1,_) {
        char A[1111];
        gets(A);
        string s=A,res=A;
        FORN(i,0,s.size()) if (s[i]!=' ') res[i] = d[s[i]];
        cout << "Case #"<<t<<": " <<res << endl;
    }
}

