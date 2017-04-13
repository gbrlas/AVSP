#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
#include <queue>

using namespace std;

struct node {
    int num, den, gen;
    node () : num(0), den(0), gen(0) {}
    node (int n, int d, int g) : num(n), den(d), gen(g) {}
};

class compareQueue {
public:
    bool operator()(const node & n1, const node & n2) const {
        if(n1.num-n1.den == n2.num-n2.den)
            return n1.gen < n2.gen;
        return (n1.num-n1.den < n2.num-n2.den);
    }
};


typedef priority_queue<node,vector<node>,compareQueue> queue_t;
typedef set<node> set_t;

//set_t was;

bool check(int n) {
    if(n == 1)
        return true;
    if(n%2 != 0)
        return false;
    return check(n/2);
}

int main() {

    int k;
    cin >> k;

    for(int l = 0; l < k; ++l) {

        queue_t ans;

        int p = 0, q = 0;
        string tmp;
        cin >> tmp;

        int i;
        for(i = 0; i < tmp.size(); ++i) {
            if(tmp[i] != '/') {
                p *= 10;
                p += (tmp[i] - '0');
            }
            else
                break;
        }
        ++i;

        for(; i < tmp.size(); ++i) {
            if(tmp[i] != '\n') {
                q *= 10;
                q += (tmp[i] - '0');
            }
            else
                break;
        }

        if(!check(q)) {
            cout << "Case #" << l+1 << ": impossible" << endl;
            continue;
        }


        ans.push(node(p, q, 0));
        //was.insert(node(p, q, 0));

        while(!ans.empty()) {
            node cur = ans.top();
            ans.pop();

            if(cur.den == cur.num) {
                cout << "Case #" << l+1 << ": " << cur.gen << endl;
                break;
            }

            int new_q = cur.den / 2;

            for(int new_p = 0; new_p < cur.num/2 + 1; ++new_p) {
                if(new_p > new_q || cur.num - new_p > new_q)
                    continue;

                if(new_p != 0)
                    ans.push(node(new_p, new_q, cur.gen+1));

                if(cur.num - new_p != 0)
                    ans.push(node(cur.num - new_p, new_q, cur.gen+1));
            }
        }

    }



    return 0;

}
