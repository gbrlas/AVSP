#include <iostream>
#include <stdio.h>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

int n,a[1111];

int main() {
    freopen("candy.inp","r",stdin);
    freopen("candy.out","w",stdout);
    int t;
    cin >> t;
    FOR(_,1,t) {
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        sort(a+1,a+n+1);
        int sum=0;
        FOR(i,1,n) sum ^=a[i];
        if (sum!=0) cout << "Case #" << _ << ": NO\n";
        else {
            sum=0;
            FOR(i,2,n) sum+=a[i];
            cout << "Case #" << _ <<": "<< sum <<"\n";
        }
    }
}