#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int t;
    cin>>t;

    for (int i = 0; i < t; i++) {
        int R, K, N;
        cin>>R>>K>>N;
        vector<int> gs(N);
        for (int j = 0; j < N; j++) {
            cin>>gs[j];
        }
        vector<pair<int, int> > m(N);
        for (int j = 0; j < N; j++) {
            int c = 0;
            int k = j;
            while (true) {
                if (c + gs[k] > K) {
                    break;
                }
                c += gs[k];
                k = (k + 1) % N;
                if (k == j) {
                    break;
                }
            }
            m[j].first = c;
            m[j].second = k;
        }
        int index = 0;
        long long result = 0;
        for (int j = 0; j < R; j++) {
            result += m[index].first;
            index = m[index].second;
        }
        cout<<"Case #"<<i + 1<<": "<<result<<endl;
    }

    return 0;
}
