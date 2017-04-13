#include <iostream>
using namespace std;

typedef unsigned long long big;

big NWD(big a, big b)
{
    while(a!=b)
        if(a>b)
            a-=b;
        else
            b-=a;
    return a;
}

bool exp2(big Q) {
    bool ok=true;
    while (ok && Q>1) {
        if (Q%2==1) {
            ok=false;
        }
        Q=Q/2;
    }
    return ok;
}

void fact(big &P, big &Q) {
    big a = NWD(P,Q);
    P=P/a;
    Q=Q/a;
}

bool valid(big P, big Q) {
    return (exp2(Q) && P<=Q);
}

int main() {
    int i,j,T;
    big P,Q,n;
    char c;
    bool ok;
    cin >> T;
    for (i=0; i<T; i++) {
        cout << "Case #" << i+1 << ": ";
        cin >> P >> c >> Q;
        fact(P,Q);
        if (valid(P,Q)) {
            n=1;
            ok=false;
            for (j=0; j<40; j++) {
                if (n*P>=Q) {
                    ok=true;
                    break;
                }
                n*=2;
            }
            if (ok) {
                cout << j << endl;
            }
            else {
                cout << "impossible\n";
            }
        }
        else cout << "impossible\n";
    }
    return 0;
}