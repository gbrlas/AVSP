#include <iostream>
#include <cstring>
#include <cstdio>

#define g(i,j) ((mask >> ((i)*M + (j)))&1)

using namespace std;

int OPT;
int N, M, K;

void process(int mask) {
    int cand=K;

    for(int i=1; i<N-1; ++i) {
        for(int j=1; j<M-1; ++j) {
            if(g(i,j) && g(i,j+1) && g(i,j-1) && g(i-1,j) && g(i+1,j)) --cand;
        }
    }

    OPT = min(OPT, cand);
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int Cases;

    cin >> Cases;

    for(int Case=1; Case<=Cases; ++Case) {
        cin >> N >> M >> K;
        OPT = K;

        int BIG = 1<<(N*M);
        for(int i=0; i<BIG; ++i) {
            if(__builtin_popcount(i) != K) continue;
            process(i);
        }

        cout << "Case #" << Case << ": " << OPT << '\n';
    }

    return 0;
}