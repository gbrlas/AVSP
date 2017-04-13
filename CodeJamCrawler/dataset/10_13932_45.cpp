#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main()
{
    int T;
    scanf("%d",&T);
    for (int test=1; test<=T; ++test) {
        int N;
        scanf("%d",&N);
        vector<int> a(N);
        vector<int> b(N);
        map<int, int> wires;
        for (int i=0; i<N; ++i) {
            int A, B;
            scanf("%d%d",&A, &B);
            a[i] = A;
            b[i] = B;
            wires.insert(make_pair<int, int>(A, B));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        map<int ,int> bpos;
        for (int i=0; i<N; ++i) {
            bpos.insert(make_pair<int, int>(b[i], i));
        }
        ull crossings = 0;
        for (int i=0; i<N; ++i) {
            int sa = a[i];
            int sb = wires[sa];
            int pos = bpos[sb];
            if (pos > i) {
                crossings = pos - i;
            }
        }
        printf("Case #%d: %llu\n", test, crossings);
    }
    return 0;
}