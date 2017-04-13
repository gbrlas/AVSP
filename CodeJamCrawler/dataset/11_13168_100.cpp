#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void printList(deque<int> &l) {
    if (l.size() == 0) {
        return;
    }
    for (deque<int>::reverse_iterator it = l.rbegin();
         it != l.rend() - 1; it++) {
        cout<<(char)(*it + 'A')<<", ";
    }
    cout<<(char)(l.front() + 'A');
}
int main() {
    int T;

    cin>>T;
    for (int i = 1; i <= T; i++) {
        int C, D, N;
        vector<vector<int> > comb_tbl(26, vector<int>(26, -1));
        vector<vector<bool> > opp_tbl(26, vector<bool>(26, false));

        cin>>C;
        for (int j = 0; j < C; j++) {
            char e0, e1, e2;
            cin>>e0>>e1>>e2;
            e0 -= 'A';
            e1 -= 'A';
            e2 -= 'A';
            comb_tbl[e0][e1] = comb_tbl[e1][e0] = e2;
        }
        cin>>D;
        for (int j = 0; j < D; j++) {
            char e0, e1;
            cin>>e0>>e1;
            e0 -= 'A';
            e1 -= 'A';
            opp_tbl[e0][e1] = opp_tbl[e1][e0] = true;
        }
        cin>>N;
        vector<int> used(26, 0);
        deque<int> elist;
        for (int j = 0; j < N; j++) {
            char e;
            cin>>e;
            e -= 'A';
            elist.push_front(e);
            used[e]++;

            while (true) {
                if (elist.size() < 2) {
                    break;
                }
                int e0 = elist[0];
                int e1 = elist[1];
                if (comb_tbl[e0][e1] == -1) {
                    break;
                }
                elist.pop_front();
                elist.pop_front();
                elist.push_front(comb_tbl[e0][e1]);
                used[e0]--;
                used[e1]--;
                used[comb_tbl[e0][e1]]++;
            }

            int e2 = elist[0];
            for (int k = 0; k < used.size(); k++) {
                if (used[k] && opp_tbl[e2][k]) {
                    elist.clear();
                    for (int l = 0; l < used.size(); l++) {
                        used[l] = 0;
                    }
                    break;
                }
            }
        }

        cout<<"Case #"<<i<<": [";
        printList(elist);
        cout<<"]"<<endl;
    }

    return 0;
}
