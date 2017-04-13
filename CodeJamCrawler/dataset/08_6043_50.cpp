// 
// File:   17.07.08_b.cc
// Author: cain
//
// Created on 17 Июль 2008 г., 15:24
//

#include <stdlib.h>
#include <set>
#include <vector>
#include <iostream>
#include <queue>
#include <memory.h>
#include <map>
#include <string>
using namespace std;
// google code jam. Qualification Round. problem b - Saving the Universe
// 
//

void inc(vector<int> &tree, int i)
{
    for (int j = i; j < tree.size(); j |= j + 1)
        tree[j]++;
}
void dec(vector<int> &tree, int i)
{
    for (int j = i; j < tree.size(); j |= j + 1)
        tree[j]--;
}
int sum(vector<int> &tree, int i)
{
    int res = 0;
    for (int j = i; j >= 0; j &= j + 1, j--)
        res += tree[j];
    return res;
}

int main()
{
    int n, na , nb;
    vector<int> a;
    vector<int> b;
    int h1, m1, m2, h2, t;
    freopen("output_b", "w",stdout);
    cin >> n;
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int > >, greater<pair<pair<int, int>,int > > > q;
    for (int i = 0; i < n; ++i)
    {
        while (!q.empty()) q.pop();
        a.clear();
        b.clear();
        cin >> t >> na >> nb;
        a.resize(24 * 60 + 1 + t);
        b.resize(24 * 60 + 1 + t);
        
        for (int j = 0; j < na; ++j)
        {
            scanf("%d:%d %d:%d",&h1,&m1, &h2,&m2);
            q.push(make_pair(make_pair(h1 * 60 + m1 + 1, h2 * 60 + m2 + t + 1), 0));
        }
        for (int j = 0; j < nb; ++j)
        {
            scanf("%d:%d %d:%d",&h1,&m1, &h2,&m2);
            q.push(make_pair(make_pair(h1 * 60 + m1 + 1, h2 * 60 + m2 + t + 1), 1));
        }
        while (!q.empty())
        {
            pair<pair<int, int>, int > f = q.top();
            if (f.second == 0)
            {
                if (sum(a, f.first.first) <= 0)
                    inc(a, 0);
                dec(a, f.first.first);
                inc(b, f.first.second);
            }
            else
            {
                if (sum(b, f.first.first) <= 0)
                    inc(b, 0);
                dec(b, f.first.first);
                inc(a, f.first.second);
            }
            q.pop();
        }
        cout << "Case #" << i + 1 << ": " << sum(a,0) << ' ' << sum(b,0) << endl;
    }
    return 0;
}
