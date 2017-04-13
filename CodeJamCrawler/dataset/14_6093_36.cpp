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

long double C, F, X;

int main()
{
    freopen("B-small-attempt1.in.txt", "r", stdin);
    freopen("B-small-attempt1.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ": ";
        cin >> C >> F >> X;
        long double t = 0.0, Ans = X/2.0;
        for (int i = 1; t <= Ans; ++i)
        {
            t += C/(2.0+(i-1)*F);
            Ans = min(Ans, t+X/(2.0+i*F));
        }
        cout << setprecision(10) << fixed << Ans << endl;
    }
    return 0;
}
