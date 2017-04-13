#include <iostream>
#include <cstdio>

#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
    return b ? gcd(b,a%b) : a;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int Cases;

    scanf("%d\n", &Cases);

    for(int Case=1; Case<=Cases; ++Case) {
        ll P, Q;
        scanf("%lld/%lld", &P, &Q);

        ll g = gcd(P,Q);
        P/=g; Q/=g;

        ll q = Q;
        while((q&1)==0) q>>=1;

        ll p=P;
        while(p != (p&-p)) p -= (p&-p);
        ll gen=-1;
        p = Q/p;
        //printf("%lld\n", p);
        while(p) { p>>=1; ++gen; }

        printf("Case #%d: ", Case);
        if(q==1) printf("%lld\n", gen);
        else printf("impossible\n");
    }

    return 0;
}