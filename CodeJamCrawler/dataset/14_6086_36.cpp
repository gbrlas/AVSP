#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int a[4][4], b[4][4], u, v;
vector<int> Ans;

int main()
{
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("A-small-attempt0.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ": ";
        cin >> u;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; cin >> a[i][j++]);
        cin >> v;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; cin >> b[i][j++]);
        --u, --v;
        Ans.clear();
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (a[u][i] == b[v][j])
                    Ans.push_back(a[u][i]);
        if (Ans.size() == 1)
            cout << Ans[0] << endl;
        else if (Ans.size() == 0)
            cout << "Volunteer cheated!" << endl;
        else
            cout << "Bad magician!" << endl;
    }
    return 0;
}
