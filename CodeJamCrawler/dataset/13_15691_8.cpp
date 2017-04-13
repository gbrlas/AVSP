#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int NODE = 1005, MOD = 1000002013;

int nStation;
long long nPpl[NODE][NODE]; // [src idx][dst idx]
vector< pair<int,int> >  sdList; // (src idx, dst idx)

map<int,int> idx2dist, dist2idx;

void read() {
    idx2dist.clear();
    dist2idx.clear();
    memset(nPpl, 0, sizeof(nPpl));
    sdList.clear();

    vector<int> distList;

    int M, s[NODE], t[NODE], n[NODE];
    cin >> nStation >> M;


    for (int i = 0; i < M; i++) {
        cin >> s[i] >> t[i] >> n[i];
        distList.push_back(s[i]);
        distList.push_back(t[i]);
    }

    sort(distList.begin(), distList.end());
    distList.erase(unique(distList.begin(), distList.end()), distList.end());

    for (vector<int>::iterator it = distList.begin(); it != distList.end(); it++) {
        int idx = idx2dist.size();
        idx2dist[idx] = *it;
        dist2idx[*it] = idx;
    }

    for (int i = 0; i < M; i++) {
        nPpl[dist2idx[s[i]]][dist2idx[t[i]]] += n[i];
        sdList.push_back(make_pair(dist2idx[s[i]],dist2idx[t[i]]));
    }
}

long long calcCost(int s, int t) { // idx
    int v = abs(idx2dist[s] - idx2dist[t]);
    return 1LL * v * nStation - 1LL * v * (v - 1) / 2;
}


void work(int cases) {
    static bool pushed[NODE][NODE];
    memset(pushed, 0, sizeof(pushed));

    for (int i = 0; i < sdList.size(); i++)
        pushed[sdList[i].first][sdList[i].second] = true;

    long long ans = 0;

    while (1) {
        bool update = false;

        for (int i = 0; i < sdList.size(); i++) {
            pair<int,int> &sd1 = sdList[i];

            for (int j = 0; nPpl[sd1.first][sd1.second] != 0 && j < sdList.size(); j++) {
                pair<int,int> &sd2 = sdList[j];
                if (nPpl[sd2.first][sd2.second] == 0)
                    continue;

                if (min(max(sd1.first,sd1.second),max(sd2.first,sd2.second)) >=
                    max(min(sd2.first,sd2.second),min(sd1.first,sd1.second)) &&
                    calcCost(sd1.first, sd1.second) + calcCost(sd2.first, sd2.second)
                    > calcCost(sd1.first, sd2.second) + calcCost(sd2.first, sd1.second)) {
                    
                    long long minP = min(nPpl[sd1.first][sd1.second], nPpl[sd2.first][sd2.second]);
                    nPpl[sd1.first][sd1.second] -= minP;
                    nPpl[sd2.first][sd2.second] -= minP;
                    nPpl[sd1.first][sd2.second] += minP;
                    nPpl[sd2.first][sd1.second] += minP;                    

                    if (!pushed[sd1.first][sd2.second]) {
                        pushed[sd1.first][sd2.second] = true;
                        sdList.push_back(make_pair(sd1.first, sd2.second));
                    }

                    if (!pushed[sd2.first][sd1.second]) {
                        pushed[sd2.first][sd1.second] = true;
                        sdList.push_back(make_pair(sd2.first, sd1.second));
                    }


                    long long diff = calcCost(sd1.first, sd1.second) + calcCost(sd2.first, sd2.second)
                                   - calcCost(sd1.first, sd2.second) - calcCost(sd2.first, sd1.second);
                    
                    ans = (ans + diff % MOD * (minP % MOD)) % MOD;

                    update = true;
                }
            }
        }

        if (!update)
            break;
    }

    cout << "Case #" << cases << ": " << ans << endl;
}

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++){
        read();
        work(i + 1);
    }

    return 0;
}
