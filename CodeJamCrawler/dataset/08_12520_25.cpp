#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> CalcAnd(int a, int b, int c, int d)
{
    pair<int, int> ret;
    if((a == -1) && (c == -1))
        ret.first = -1;
    else if(a == -1)
        ret.first = c;
    else if(c == -1)
        ret.first = a;
    else
        ret.first = min(a, c);
    if((b == -1) || (d == -1))
        ret.second = -1;
    else
        ret.second = b + d;
    return ret;
}

pair<int, int> CalcOr(int a, int b, int c, int d)
{
    pair<int, int> ret;
    if((a == -1) || (c == -1))
        ret.first = -1;
    else
        ret.first = a + c;
    if((b == -1) && (d == -1))
        ret.second = -1;
    else if(b == -1)
        ret.second = d;
    else if(d == -1)
        ret.second = b;
    else
        ret.second = min(b, d);
    return ret;
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int M, V;
        cin >> M >> V;

        vector<pair<int, int> > interior_nodes((M - 1) / 2);
        vector<int>             leaf_nodes((M + 1) / 2);
        for(size_t j = 0; j < interior_nodes.size(); ++j)
            cin >> interior_nodes[j].first >> interior_nodes[j].second;
        for(size_t j = 0; j < leaf_nodes.size(); ++j)
            cin >> leaf_nodes[j];

        vector<pair<int, int> > dp(M, pair<int, int>(-1, -1));
        for(size_t j = M - 1; j >= interior_nodes.size(); --j)
        {
            if(leaf_nodes[j - interior_nodes.size()] == 0)
                dp[j].first = 0;
            else
                dp[j].second = 0;
        }
        for(size_t j = interior_nodes.size() - 1; j < interior_nodes.size(); --j)
        {
            int a = dp[2 * j + 1].first;
            int b = dp[2 * j + 1].second;
            int c = dp[2 * j + 2].first;
            int d = dp[2 * j + 2].second;

            // Determine this node's values without change
            if(interior_nodes[j].first == 1)
                dp[j] = CalcAnd(a, b, c, d);
            else
                dp[j] = CalcOr(a, b, c, d);

            // If we can change this, calculate with the change
            if(interior_nodes[j].second == 1)
            {
                pair<int, int> with_change;
                if(interior_nodes[j].first == 1)
                    with_change = CalcOr(a, b, c, d);
                else
                    with_change = CalcAnd(a, b, c, d);

                // Update dp
                if(((dp[j].first == -1) && (with_change.first != -1)) || ((dp[j].first != -1) && (with_change.first != -1) && (with_change.first < dp[j].first)))
                    dp[j].first = with_change.first + 1;
                if(((dp[j].second == -1) && (with_change.second != -1)) || ((dp[j].second != -1) && (with_change.second != -1) && (with_change.second < dp[j].second)))
                    dp[j].second = with_change.second + 1;
            }
        }

        int v = (V == 1) ? dp[0].second : dp[0].first;
        cout << "Case #" << (i + 1) << ": ";
        if(v == -1)
            cout << "IMPOSSIBLE";
        else
            cout << v;
        cout << endl;
    }

    return 0;
}
