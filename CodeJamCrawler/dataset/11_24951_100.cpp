#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

#define maxn 1111
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORN(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int n,a[maxn];
bool Free[maxn];
vector <int > cir;

int visit(int i) {
    Free[i]=false;
    if (!Free[a[i]]) return 1;
    else return 1+visit(a[i]);
}

void init_cir() {
    cir.clear();
    memset(Free,true,sizeof(Free));
    FOR(i,1,n) 
        if (Free[i]) {
            int cnt=visit(i);
            cir.push_back(cnt);
        }
    sort(cir.begin(),cir.end());
}

double calc(int N) {
            if (N==1) return 0;
            double current=1;
            
            FOR(i,1,N) current/=(double)i;
            double base=1-current;
            
            double p=current;
            //cerr << current << " " << base << endl;
            
            FOR(x,2,1000000000) {
                current*=(double)base;
                double newp=p+(double)x*current;
                
                if (newp-p<1e-7) break;
                p=newp;
            }
            cerr << p << endl;
            return p;
}

int main() {
    freopen("goro.in1","r",stdin);
    freopen("goro.out","w",stdout);
    int _;
    cin >> _;
    FOR(__,1,_) {
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        int res=0;
        FOR(i,1,n) if (a[i]!=i) res++;
        printf("Case #%d: %.6lf\n",__,(double)res);
        continue;
        init_cir();
        /*
        double res=0;
        FORN(i,0,cir.size()) {
            //cerr << cir [i] << endl;
            int N=cir[i];
            res+=calc(N);
        }
        printf("Case #%d: %.6lf\n",__,res);
        //cout << "Case #" << __ << ": " << res << endl;
        */
    }
}