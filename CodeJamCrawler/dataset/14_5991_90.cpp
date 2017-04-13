#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int n;
double nao[1000], ken[1000];

int dec() {
    bool kenned[1000];
    int ans=0;
    memset(kenned, 0, sizeof(kenned));
    for(int i=0; i<n; ++i) {
        // does nao[i..n-1] majorize ken[0..n-1-i]?
        bool maj=1;
        for(int j=i; j<n; ++j) {
            if(nao[j] < ken[j-i]) maj=0;
        }
        
        if(maj) return n-i;
    }

    return ans;
}

int reg() {
    bool kenned[1000];
    int ans=0;
    memset(kenned, 0, sizeof(kenned));
    for(int i=0; i<n; ++i) {
        // nao takes nao[i]
        int m=-1, mn=-1;
        for(int j=0; j<n; ++j) {
            if(kenned[j]) continue;
            if(m == -1 || ken[j] < ken[m]) m = j;
            if(ken[j] < nao[i]) continue;
            if(mn == -1 || ken[j] < ken[mn]) mn = j;
        }

        if(mn == -1) {
            kenned[m] = 1;
            ++ans;
        }
        else {
            kenned[mn] = 1;
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    for(int qq=1; qq<=T; ++qq) {

        cin >> n;
        for(int i=0; i<n; ++i) cin >> nao[i];
        for(int i=0; i<n; ++i) cin >> ken[i];

        sort(nao, nao+n);
        sort(ken, ken+n);

        cout << "Case #" << qq << ": " << dec() << ' ' << reg() << '\n';
    }
    return 0;
}
