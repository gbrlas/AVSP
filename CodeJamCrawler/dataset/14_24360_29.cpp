#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
using namespace std;

int sr[10];
int allm, alln, max_ans,nr_ans;
vector<string> allv;

int solve(vector<string> v) {
    int ans = 0;
    int n = v.size();
    set<string> S;

    for(int i = 0; i < n; ++i) {
        int len = v[i].size();
        for(int j = 0; j < len; ++j)
            if(S.find(v[i].substr(0, j + 1)) == S.end()) {
                ans++;
                S.insert(v[i].substr(0, j + 1));
            }
    }

    return ans + 1;
}

void back(int poz) {
    if(poz == allm) {
        int tmp = 0;
        for(int i = 0; i < alln; ++i) {
            vector<string> now;
            for(int j = 0; j < allm; ++j)
                if(sr[j] == i)
                    now.push_back(allv[j]);
            if(now.empty())
                continue;
            //sort(now.begin(), now.end());
            int cst = solve(now);
            tmp += cst;
        }
        
        if(tmp == max_ans) {
            nr_ans++;
        } else if(tmp > max_ans) {
            max_ans = tmp;
            nr_ans = 1;
        }
        return;
    }

    for(int i = 0; i < alln; ++i) {
        sr[poz] = i;
        back(poz + 1);
    }
}

int main() {
    ifstream cin("testD.in");
    ofstream cout("testD.out");
    
    int t; cin >> t;
    for(int t_case = 1; t_case <= t; ++t_case) {
        int m, n; cin >> m >> n;
        cout << "Case #" << t_case << ": ";
        vector<string> v(m);
        for(int i = 0; i < m; ++i)
            cin >> v[i];
        allv = v;
        alln = n, allm = m;
        max_ans = 0, nr_ans = 0;
        back(0);
        
        //cerr << solve(v) << "\n";
        cout << max_ans << " " << nr_ans << "\n";
    }
}
