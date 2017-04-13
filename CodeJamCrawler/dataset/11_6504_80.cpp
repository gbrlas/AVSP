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

string s[120];
double wp[120], tmp[120], owp[120], oowp[120];

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d:\n",test++);

        int N; cin>>N;
        REP(i, N) cin>>s[i];
            // WP
        REP(i, N) {
            int cnt[2]; cnt[0]=cnt[1]=0;
            REP(j, N) if (s[i][j] != '.') cnt[s[i][j]-'0']++;
            wp[i] = (double)cnt[1] / (cnt[0]+cnt[1]);
        }
            // OWP
        REP(k, N) {
                // calc tmp
            REP(i, N) {
                int cnt[2]; cnt[0]=cnt[1]=0;
                REP(j, N) if (j != k) if (s[i][j] != '.') cnt[s[i][j]-'0']++;
                tmp[i] = (double)cnt[1] / (cnt[0]+cnt[1]);
            }
            int num=0; double sum=0;
            REP(i, N) if (s[k][i] != '.') sum+=tmp[i], num++;
            owp[k] = sum / num;
        }
            // OOWP
        REP(i, N) {
            int num=0; double sum=0;
            REP(j, N) if (s[i][j] != '.') sum+=owp[j], num++;
            oowp[i] = sum / num;
        }

            // return RPI
        REP(i, N) printf("%.13f\n", 0.25*wp[i] + 0.50*owp[i] + 0.25*oowp[i]);
    }
}
