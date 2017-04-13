#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int T;
    cin>>T;

    for (int ncase = 1; ncase <= T; ncase++) {
        int P;
        cin>>P;
        vector<int> M(1 << P);

        for (int i = 0; i < M.size(); i++) {
            cin>>M[i];
        }
        for (int i = P - 1; i >= 0; i--) {
            for (int j = 0; j < (1 << i); j++) {
                int p;
                cin>>p;
            }
        }

        int ans = 0;
        for (int i = P; i >= 1; i--) {
            for (int j = 0, k = 0; j < (1 << i); j += 2, k++) {
                M[k] = min(M[j], M[j + 1]);
                if (M[k] <= P - i) {
                    M[k]++;
                    ans++;
                }
            }
        }

        cout<<"Case #"<<ncase<<": "<<ans<<endl;
    }

    return 0;
}

