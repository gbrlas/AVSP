#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define DEC(i,k) for (int i=(k); i>=0; --i)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

int seq[12];

int main()
{
    vector<int> primes;
    primes.push_back(2);
    for (int j=3; j<=10000; j+=2) {
        REP(k,SZ(primes)) {
            if (primes[k]*primes[k]>j) break;
            if (j%primes[k]==0)
                goto NEXT;
        }
        primes.push_back(j);
NEXT:;
    }
    int T;
    cin>>T;
    while (T--) {
        static int test=1;
        printf("Case #%d: ",test++);
        int D,K;
        cin>>D>>K;
        REP(j,K) cin>>seq[j];

        if (K==1) {
            puts("I don't know.");
            goto NEXT2;
        }
        {
            int ma=0;
            REP(j,K) ma=max(ma,seq[j]);
            int upper=1; REP(j,D) upper*=10;

            int cand=-1;
            for (int j=0; primes[j]<=upper; ++j) {
                if (ma>=primes[j]) continue;
                int P=primes[j];

                REP(A,P) {
                    int B=(seq[1]-A*seq[0])%P;
                    B=(B+P)%P;

                    int s=seq[0];
                    FOR(j,1,K) {
                        s=(A*s+B)%P;
                        if (s!=seq[j]) goto NEXT3;
                    }
                    s=(A*s+B)%P;
                    if (cand==-1) cand=s;
                    else if (cand!=s) {
                        puts("I don't know.");
                        goto NEXT2;
                    }
NEXT3:;
                }
            }
            if (cand==-1) puts("I don't know.");
            else printf("%d\n", cand);
        }
NEXT2:;
    }
}
