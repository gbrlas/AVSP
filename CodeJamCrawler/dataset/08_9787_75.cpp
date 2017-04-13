#include <cfloat>
#include <climits>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <complex>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef priority_queue<int> heap;

struct Plan
{
    int start, end, dir;
    bool operator<(const Plan &p) const
    {
        return start < p.start;
    }
};

Plan plan[256];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int __it;
    scanf ("%d", &__it);
    for (int __xx = 1; __xx <= __it; ++ __xx)
    {
        int ans[2];
        int t, na, nb;
        heap h[2];
        scanf("%d %d %d", &t, &na, &nb);
        for (int i = 0; i < na + nb; ++ i)
        {
            int h, m;
            scanf("%d:%d", &h, &m);
            plan[i].start = h * 60 + m;
            scanf("%d:%d", &h, &m);
            plan[i].end = h * 60 + m;
            plan[i].dir = (i >= na);
        }
        ans[0] = ans[1] = 0;
        sort(plan, plan + na + nb);
        for (int i = 0; i < na + nb; ++ i)
        {
            //printf("%d %d %d\n", plan[i].start, plan[i].end, plan[i].dir);
            int d = plan[i].dir;
            //if (!h[d].empty())
            //    printf("top: %d\n", h[d].top());
            if (!h[d].empty() && -h[d].top() <= plan[i].start)
                h[d].pop();
            else
                ans[d] ++;
            h[!d].push(-plan[i].end - t);
        }
        printf("Case #%d: %d %d\n", __xx, ans[0], ans[1]);
    }
    return 0;
}

