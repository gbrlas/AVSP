#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#include<vector>

using namespace std;

typedef vector<int> T;
vector<T> graph;
vector<bool> spa, valid;
int n;

bool nextdfs(int x) {
    if (valid[x]) return true;
    valid[x] = true;
    for (int i = 0, y; i < graph[x].size(); i++) {
        y = graph[x][i];
        if (nextdfs(y)) return true;
    }
    return false;
}

bool calc() {
    for (int i = 1; i <= n; i++) {
        if (spa[i]) {
            valid.assign(n + 1, false);
            if (nextdfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    freopen("D:\\A-small-attempt0.in", "r", stdin);
    freopen("D:\\A-small-attempt0.out", "w", stdout);
    int tc, ccc;

    scanf("%d", &tc);
    ccc = 0;
    while (tc--) {
        int input, input2;
        scanf("%d", &n);
        printf("Case #%d: ", ++ccc);
        graph.assign(n + 1, vector<int>());
        spa.assign(n + 1, true);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &input);
            for (int j = 0; j < input; j++) {
                scanf("%d", &input2);
                graph[i].push_back(input2);
                spa[input2] = false;
            }
        }

        puts(calc()?"Yes":"NO");
    }

}
