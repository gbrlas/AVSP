// 
// File:   17.07.08_1.cc
// Author: cain
//
// Created on 17 Июль 2008 г., 13:21
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
// google code jam. Qualification Round. problem A - Saving the Universe
// 
//
int main()
{
    int n;
    map<string, int> e;
    vector<int> q;
    vector<int> t;
    freopen("output", "w",stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int ee, qq;
        cin >> ee;
        string a;
        getline(cin, a);
        q.clear();
        e.clear();
        t.clear();
        t.clear();
        t.resize(ee, 0);
        for (int j = 0; j < ee; ++j)
        {
            getline(cin, a);
            e[a] = j;
        }
        cin >> qq;
        getline(cin, a);
        for (int k = 0; k < qq; ++k)
        {
            getline(cin, a);
            q.push_back(e[a]);
        }
        int count = 0;
        int res  = 0;
        for (int k = 0; k < qq; ++k)
        {
            if (count == ee - 1 && t[q[k]] == 0)
            {
                t.clear();
                t.resize(ee, 0);
                count = 1;
                t[q[k]]++;
                res++;
            }
            else
            {
                count += t[q[k]] == 0;
                t[q[k]]++;
            }
        }
        cout << "Case #" << i + 1 << ": " << res << endl;
    }
    return 0;
}
