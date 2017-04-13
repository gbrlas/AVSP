#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>

#define ll long long

using namespace std;

int M, N;
vector<string> s;

int w=-1, wc=0;
int a[1000];

int ts(const vector<string>& v) {
    set<string> s;
    for(int i=0; i<v.size(); ++i) {
        for(int j=0; j<=v[i].length(); ++j) {
            s.insert(v[i].substr(0,j));
        }
    }
    return s.size();
}

int proc() {
    vector<string> v[5];
    for(int i=0; i<M; ++i) {
        v[a[i]].push_back( s[i] );
    }

    int tot=0;
    for(int i=0; i<N; ++i) tot += ts(v[i]);

    return tot;
}

// assign each string to a server
void f(int pos) {
    if(pos == M) {
        int t = proc();
        if(t>w) {
            w=t;
            wc=1;
        }
        else if(t==w) ++wc;
        return;
    }

    for(int i=0; i<N; ++i) {
        a[pos] = i;
        f(pos+1);
    }
}

int main() {
    int Cases;
    scanf("%d", &Cases);

    for(int Case=1; Case<=Cases; ++Case) {
        scanf("%d %d", &M, &N);
        s.resize(M);
        for(int i=0; i<M; ++i) cin >> s[i];

        w=-1; wc=0;
        f(0);

        printf("Case #%d: %d %d\n", Case, w, wc);

        //cout << ts(s) << '\n';
    }

    return 0;
}
