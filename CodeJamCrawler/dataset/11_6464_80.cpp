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
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

string comb[60], opps[60];

int main()
{
    int T; cin>>T;
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);

        int C, D, N;
        cin>>C;
        REP(j, C) cin>>comb[j];
        cin>>D;
        REP(j, D) cin>>opps[j];

        string s;
        cin>>N>>s;

        string lst;
        REP(j, N) {
            lst+=s.substr(j, 1);
                // combine?
            if (SZ(lst)>=2) {
                int m=SZ(lst)-2;
                REP(k, C) if ((lst[m]==comb[k][0] && lst[m+1]==comb[k][1]) || (lst[m]==comb[k][1] && lst[m+1]==comb[k][0])) {
                    lst = lst.substr(0, m) + comb[k].substr(2, 1);
                    goto NEXT;
                }
            }
                // deletion?
            REP(l, D) {
                if (lst.find(opps[l][0]) != string::npos && lst.find(opps[l][1]) != string::npos) {
                    lst="";
                    break;
                }
            }
NEXT:;
        }

        printf("[");
        REP(k, SZ(lst)) {
            if (k) printf(", ");
            printf("%c", lst[k]);
        }
        printf("]\n");
    }
}
