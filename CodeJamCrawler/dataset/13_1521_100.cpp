#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int t;
    cin>>t;
    for (int tt = 1; tt <= t; ++tt) {
        int k, n;
        cin>>k>>n;
        vector< int > start(k);
        vector< pair< int, int > > allk;
        for (int i = 0; i < k; ++i) {
            cin>>start[i];
            allk.push_back(make_pair(start[i], -1));
        }
        vector< pair< int, vector< int > > > chsr(n);
        for (int i = 0; i < n; ++i) {
            cin>>chsr[i].first;
            int ki;
            cin>>ki;
            chsr[i].second.resize(ki);
            for (int j = 0; j < ki; ++j) {
                cin>>chsr[i].second[j];
                allk.push_back(make_pair(chsr[i].second[j], i));
            }
        }
        sort(allk.begin(), allk.end());
        vector< pair< int, long long > > chs(n);
        for (int i = 0; i < n; ++i) {
            chs[i].first = chsr[i].first;
        }
        long long initk = 0;
        map< int, vector< int > > keymap;
        for (int i = 0; i < allk.size(); ++i) {
            if (allk[i].second < 0) {
                initk += 1LL << i;
            } else {
                chs[allk[i].second].second += 1LL << i;
            }
            keymap[allk[i].first].push_back(i);
        }
        vector< int > prev(1 << n);
        fill(prev.begin(), prev.end(), -1);
        queue< pair< int, long long > > q;
        q.push(make_pair(0, initk));
        while (!q.empty()) {
            int c = q.front().first;
            long long keys = q.front().second;
            if (c == ((1 << n) - 1)) {
                break;
            }
            q.pop();
            for (int i = 0; i < n; ++i) {
                if ((((1 << i) & c) == 0) && (prev[c + (1 << i)] < 0)) {
                    int idx = -1;
                    for (vector< int >::iterator p = keymap[chs[i].first].begin(); p != keymap[chs[i].first].end(); ++p) {
                        if (keys & (1LL << (*p))) {
                            idx = *p;
                            break;
                        }
                    }
                    if (idx < 0) {
                        continue;
                    }
                    int nc = c + (1 << i);
                    long long nkeys = keys - (1LL << idx) + chs[i].second;
                    q.push(make_pair(nc, nkeys));
                    prev[nc] = c;
                }
            }
        }
        map< int, int > mp;
        for (int i = 0; i < n; ++i) {
            mp[1 << i] = i + 1;
        }
        cout<<"Case #"<<tt<<":";
        if (q.empty()) {
            cout<<" IMPOSSIBLE";
        } else {
            stack< int > st;
            int a = (1 << n) - 1;
            int b = prev[a];
            while (b >= 0) {
                st.push(mp[a ^ b]);
                a = prev[a];
                b = prev[b];
            }
            while (!st.empty()) {
                cout<<" "<<st.top();
                st.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}

