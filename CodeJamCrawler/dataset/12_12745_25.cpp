#include <map>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

int check(int tot, int target, int& r)
{
    if (target == 0) return 1;
    if (tot < 2)
    {
        if (tot >= target) return 1;
        else return 0;
    }
    // can we do without surprise?
    if (tot + 2 >= target * 3) return 1;
   // can we have surprise?
    if (r > 0)
    {
        if (tot + 4 >= target * 3)
        {
            r--;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    for (unsigned i = 1; i <= t; ++i)
    {
        int N, S, p;
        cin >> N >> S >> p;
        int res = 0;
        for (int j = 1; j <= N; ++j)
        {
            int tot;
            cin >> tot;
            res += check(tot, p, S);
        }
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
