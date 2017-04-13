#include <cstdio>
#include <climits>
#include <vector>
using namespace std;


int n, next[2005], h[2005];

bool solve(int node, int end) {
    //get current 'string' to end node
    //assume height of node and end have been set

    vector<int> path;
    int i = node+1;
    while (i != end) {
        path.push_back(i);
        i = next[i];
        if (i > end) return false;
    }
    path.push_back(end);
    //set heights for all nodes in path.
    double prevgr = (double)(h[end]-h[node])/(end-node);
    for (i = path.size()-2; i >= 0; i--) {
        //extrapolate from prevgr
        h[path[i]] = (int)(h[path[i+1]] - (double)(path[i+1]-path[i])*prevgr - 1);
        if (!solve(path[i], path[i+1])) return false;

        prevgr = (double)(h[path[i+1]] - h[path[i]]) / (path[i+1]-path[i]);
    }
    return true;
}

int main() {
    int T;
    
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            scanf("%d", &next[i]);
        }
        next[0] = next[n] = n+1;
        h[0] = h[n+1] = 0;

        if (!solve(0, n+1)) printf("Case #%d: Impossible\n", t);
        else {
            printf("Case #%d:", t);
            int low = INT_MAX;
            for (int i = 1; i <= n; i++) low = min(low, h[i]);
            for (int i = 1; i <= n; i++) printf(" %d", h[i]-low);
            printf("\n");
        }

    }
    return 0;
}

