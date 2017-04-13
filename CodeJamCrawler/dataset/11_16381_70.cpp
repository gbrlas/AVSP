#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

void solve(int casenum, const vector<string>& C, const vector<string>& D, const string& N) {
    map<char, map<char, char> > combines;
    for (char i = 'A'; i <= 'Z'; ++i) 
        for (char j = 'A'; j <= 'Z'; ++j) 
            combines[i][j] = '\0';

    for (int i =0; i < C.size(); ++i) {
        combines[C[i][0]][C[i][1]] = C[i][2];
        combines[C[i][1]][C[i][0]] = C[i][2];
    }

    vector<pair<char, char> > opp;
    for (int i =0; i < D.size(); ++i) {
        opp.push_back(make_pair(D[i][0], D[i][1]));
    }

    string res = "";
    map<char, int> letters;
    for (int i = 0; i < N.length(); ++i) {
        res += N[i];
        letters[N[i]]++;
        while (res.length() > 1) {
            int l = res.length();
            char c1 = res[l-1];
            char c2 = res[l-2];
            char c = combines[c1][c2];
            if (c != '\0') {
                letters[c1]--;
                letters[c2]--;
                letters[c]++;
                res.erase(l-2);
                res += c;
            } else break;
        }

        for (int j = 0; j < opp.size(); ++j) {
            char c1 = opp[j].first;
            char c2 = opp[j].second;
            if (letters[c1] > 0 && letters[c2] > 0) {
                res = "";
                letters.clear();
                break;
            }
        }
    }
    cout << "Case #" << casenum << ": [";
    for (int i = 0; i < res.length(); ++i) {
        cout << res[i];
        if (i != res.length()-1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    string s;
    int t;
    getline(cin, s);
    istringstream is(s);
    is >> t;
    for (int i = 1; i <= t; ++i) {
        string ss;
        int c,d,n;
        vector<string> C,D;
        string N;
        getline(cin, ss);
        istringstream iis(ss);
        iis >> c;
        for (int j = 0; j < c; ++j) {
            string z;
            iis >> z;
            assert(z.length() == 3);
            C.push_back(z);
        }
        iis >> d;
        for (int j =0; j < d; ++j) {
            string z;
            iis >> z;
            assert(z.length() == 2);
            D.push_back(z);
            
        }
        iis >> n;
        iis >> N;
        assert(N.length() == n);
        solve(i, C,D,N);
    }
    return 0;
}
