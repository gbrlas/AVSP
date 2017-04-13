#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin>>T;

    for (int i = 1; i <= T; i++) {
        int N;
        cin>>N;

        vector<int> order;
        vector<queue<int> > next(2);
        for (int j = 0; j < N; j++) {
            char R;
            int P;
            cin>>R>>P;

            int index = (R == 'O')? 0: 1;
            order.push_back(index);
            next[index].push(P);
        }

        int ans = 0;
        vector<int> pos(2, 1);
        for (int j = 0; j < N; j++) {
            int self = order[j];
            int other = 1 - self;
            int d0 = abs(next[self].front() - pos[self]);
            pos[self] = next[self].front();
            next[self].pop();
            ans += d0 + 1;
            if (!next[other].empty()) {
                int d1 = abs(next[other].front() - pos[other]);
                if (d1 <= d0 + 1) {
                    pos[other] = next[other].front();
                }
                else {
                    int dir = (next[other].front() - pos[other]) / d1;
                    pos[other] += dir * (d0 + 1);
                }
            }
        }

        cout<<"Case #"<<i<<": "<<ans<<endl;
    }

    return 0;
}
