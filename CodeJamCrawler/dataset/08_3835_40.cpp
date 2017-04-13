#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;




int main()
{
    ifstream cin("B-small-attempt1.in");
    ofstream cout("B-small-attempt1.out");

    int testNum = 0;
    cin >> testNum;
    for(int test = 1; test <= testNum; ++test)
    {
        int n, m, a, x1, x2, y1, y2;
        cin >> n >> m >> a;
        bool t = false;
        for (x1 = 0; x1 <= n; ++x1)
        for (y1 = 0; y1 <= m; ++y1)
        for (x2 = 0; x2 <= n; ++x2)
        for (y2 = 0; y2 <= m; ++y2)
        {
            int val = x1 * y2 - x2 * y1;
            if (val == a || val == -a)
            {
                t = true;
                goto mm;
            }
        }

mm:
        if (t)
            cout << "Case #" << test <<": " << "0 0 "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        else
            cout << "Case #" << test <<": " <<"IMPOSSIBLE"<<endl;
    }

    return 0;
}