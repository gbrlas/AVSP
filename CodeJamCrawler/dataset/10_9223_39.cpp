#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &m) {
    int N = m.size();

    for (int i = 0; i < m.size(); i++) {
        for (int j = m.size() - 1, k = m.size() - 1; j >= 0; j--) {
            if (m[i][j] != -1) {
                m[i][k] = m[i][j];
                if (j != k) {
                    m[i][j] = -1;
                }
                k--;
            }
        }
    }
}
void print(vector<vector<int> > &m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            if (m[i][j] == -1) {
                cout<<'.';
            }
            else if (m[i][j] == 0) {
                cout<<'R';
            }
            else {
                cout<<'B';
            }
        }
        cout<<endl;
    }
}
bool check(int c, int K, vector<vector<int> > &m) {
    int N = m.size();

    for (int i = 0; i < N; i++) {
        int rc = 0;
        int cc = 0;
        for (int j = 0; j < N; j++) {
            rc = (m[i][j] == c)? rc + 1: 0;
            cc = (m[j][i] == c)? cc + 1: 0;
            if (rc >= K || cc >= K) {
                return true;
            }
        }
    }

    vector<vector<int> > lines(2, vector<int>(N, 0));
    int dx[] = {+1,-1};
    for (int i = 0; i < N; i++) {
        vector<vector<int> > tlines(2, vector<int>(N, 0));
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 2; k++) {
                int x = j + dx[k];
                if (x < 0 || x >= N) {
                    tlines[k][j] = (m[i][j] == c)? 1: 0;
                    continue;
                }
                tlines[k][j] = (m[i][j] == c)? lines[k][x] + 1: 0;
                //cout<<i<<" "<<j<<" "<<tlines[k][j]<<endl;
                if (tlines[k][j] >= K) {
                    return true;
                }
            }
        }
        lines = tlines;
    }

    return false;
}
int main(void) {
    int T;
    cin>>T;

    for (int ncase = 1; ncase <= T; ncase++) {
        int N, K;
        cin>>N>>K;

        vector<vector<int> > m(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            string s;
            cin>>s;
            for (int j = 0; j < N; j++) {
                if (s[j] == '.') {
                    m[i][j] = -1;
                }
                else if (s[j] == 'R') {
                    m[i][j] = 0;
                }
                else {
                    m[i][j] = 1;
                }
            }
        }

        rotate(m);
        //print(m);

        bool r = check(0, K, m);
        bool b = check(1, K, m);

        cout<<"Case #"<<ncase<<": ";
        if (r && b) {
            cout<<"Both";
        }
        else if (r) {
            cout<<"Red";
        }
        else if (b) {
            cout<<"Blue";
        }
        else {
            cout<<"Neither";
        }
        cout<<endl;
    }

    return 0;
}
