#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    for (int tt = 1; tt <= t; ++tt) {
        int n, m;
        cin>>n>>m;
        vector< vector< int > > v(n);
        vector< int > r(n), c(m);
        for (int i = 0; i < n; ++i) {
            v[i].resize(m);
            for (int j = 0; j < m; ++j) {
                cin>>v[i][j];
                r[i] = max(r[i], v[i][j]);
                c[j] = max(c[j], v[i][j]);
            }
        }
        bool fl = true;
        for (int i = 0; (i < n) && fl; ++i) {
            for (int j = 0; (j < m) && fl; ++j) {
                if ((r[i] > v[i][j]) && (c[j] > v[i][j])) {
                    fl = false;
                }
            }
        }
        cout<<"Case #"<<tt<<": ";
        if (fl) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

