#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> getset()
{
    int a;
    static int sq[4][4];
    cin >> a;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cin >> sq[i][j];
    }
    --a;
    assert(a >= 0 && a <= 3);

    sort(sq[a], sq[a] + 4);
    return vector<int>(sq[a], sq[a] + 4);
}

int solve()
{
    auto a = getset(), b = getset();
    vector<int> c;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
    if (c.size() == 0)
        return 0;
    if (c.size() > 1)
        return -1;
    if (c.size() == 1)
        return c.back();
    assert(false);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int ans = solve();
        cout << "Case #" << i << ": ";
        if (ans == -1)
            cout << "Bad magician!\n";
        else if (ans == 0)
            cout << "Volunteer cheated!\n";
        else
            cout << ans << endl;
    }

    return 0;
}
