#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int pow(int a, int b) { int res=1; while (b--) res*=a; return res; }
string S[10];
int main() {
    ios_base::sync_with_stdio(0);
    int T,N,M;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> M >> N;
        for (int i=0; i<M; i++) cin >> S[i];
        map<int, int> cnt;
        int res = 0;
        for (int i=0; i<pow(N,M); i++) {
            int s[M], tmp = i, c[N];
            for (int j=0; j<N; j++) c[j]=0;
            for (int j=0; j<M; j++) {
                s[j] = tmp%N;
                c[s[j]]++;
                tmp /= N;
            }
            bool ok = true;
            for (int j=0; j<N; j++)
                if (!c[j]) ok = false;
            if (!ok) continue;
            map<string, bool> d[N];
            for (int j=0; j<M; j++)
                for (int k=0; k<S[j].length(); k++)
                    d[s[j]][S[j].substr(0,k+1)] = true;
            tmp = 0;
            for (int j=0; j<N; j++) tmp += d[j].size()+1;
            cnt[tmp]++;
            res = max(res, tmp);
        }
        cout << "Case #" << t << ": " << res << " " << cnt[res] << "\n";
    }
    return 0;
}
