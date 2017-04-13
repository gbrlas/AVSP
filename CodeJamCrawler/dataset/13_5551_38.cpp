#include <stdio.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#define mod  1000007
using namespace std;
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define S1(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
bool vowel (char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    }
    return false;
}
bool check (string b, int x)
{
    int i,n,j,xx;
    n = b.size();
    F (i, 0, n) {
        if (vowel (b[i])) {
            continue;
        }
        xx = x - 1;
        if (xx == 0) {
            return true;
        }
        for (j = i+1; j < n; j++) {
            if (vowel (b[j])) {
                break;
            }
            xx--;
            if (xx == 0) {
                return true;
            }
        }
    }
    return false;
}



int main()
{
    freopen("iii.in","r",stdin);
    freopen ("output.txt", "w", stdout);
    int i,n;
    int t,ii=1;
    S (t);
    while (t--) {
        string s;
        int j;
        cin >> s;
        int n;
        S (n);
        string b;
        cout << "Case #" << ii << ": ";
        ii++;
        int sum = 0;
        F (i, 0, s.size()) {
            F (j, i, s.size()) {
                b = s.substr (i, j-i+1);
                if (check (b, n)) {
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
