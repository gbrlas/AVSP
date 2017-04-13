#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
using namespace std;

const int maxn = 1005;
int aib[maxn];

inline int lsb(int poz) {
    return poz & (-poz);
}

void update(int poz) {
    while(poz < 1001) {
        aib[poz]++;
        poz += lsb(poz);
    }
}

int query(int poz) {
    int ans = 0;
    while(poz) {
        ans += aib[poz];
        poz -= lsb(poz);
    }
    return ans;
}

int cntInv(vector<int> A) {
    memset(aib, 0, sizeof(aib));
    int n = A.size();
    int ans = 0;

    for(int i = 0; i < n; ++i) {
        ans += i - query(A[i] - 1);    
        update(A[i]);
    }

    return ans;
}

int main() {
    
    ifstream cin("testB.in");
    ofstream cout("testB.out");

    int t; cin >> t;
    
    for(int t_case = 1; t_case <= t; ++t_case) {
        cout << "Case #" << t_case << ": ";
        int n; cin >> n;
        vector<int> v(n, 0);
        vector<pair<int, int>> A;
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
            A.push_back(make_pair(v[i], i));
        }

        sort(A.begin(), A.end());
        int cnt = 1;
        for(int i = 0; i < n; ++i)
            if(i == 0 || (i > 0 && A[i - 1].first == A[i].first))
                v[A[i].second] = cnt;
            else
                v[A[i].second] = ++cnt;
        

        /*
        int poz = -1;

        for(int i = 0; i < n; ++i)
            if(v[i] == n) {
                poz = i;
                break;
            }
        
        int permpoz = poz;
        int ans = 1e9;

        for(int apex = 0; apex < n; ++apex) {
            vector<int> now = v;
            int tmp = 0;
            int poz = permpoz;

            while(poz > apex) {
                swap(now[poz], now[poz - 1]);
                tmp++, poz--;
            }

            while(poz < apex) {
                swap(now[poz], now[poz + 1]);
                tmp++, poz++;
            }
            
            vector<int> lf, rt;
            for(int i = 0; i < poz; ++i)
                lf.push_back(now[i]);
            for(int i = poz + 1; i < n; ++i)
                rt.push_back(now[i]);
            reverse(rt.begin(), rt.end());
            cerr << apex << "\n";
            for(auto tmp : lf)
                cerr << tmp << " ";
            cerr << "\n";
            for(auto tmp : rt)
                cerr << tmp << " ";
            cerr << "\n";

            ans = min(ans, tmp + cntInv(lf) + cntInv(rt));    
        }
        */

        int ans = 1e9;
        vector<int> aux = v;
        sort(aux.rbegin(), aux.rend());
        vector<int> poz(n + 1, 0);
        for(int i = 0; i < n; ++i)
            poz[v[i]] = i;

        for(int i = 0; i < (1 << n); ++i) {
            deque<int> D;
            for(int j = 0; j < n; ++j)
                if((1 << j) & i) 
                    D.push_back(aux[j]);
                else
                    D.push_front(aux[j]);
            vector<int> now;
            while(!D.empty()) {
                now.push_back(poz[D.back()]);
                D.pop_back();
            }
            
            int tmp = 0;
            for(int j = 0; j < n; ++j)
                for(int k = j + 1; k < n; ++k)
                    if(now[k] < now[j])
                        tmp++;
            ans = min(ans, tmp);
        }
                

        cout << ans << "\n";
    }

}
