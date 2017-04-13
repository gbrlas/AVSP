// At least S of the ti values will be between 2 and 28, inclusive.
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main()
{
    freopen("B-small.in", "r", stdin);
    freopen("output-small.out", "w", stdout);
    int t;
    cin >> t;
    for (int casenum = 1; casenum <= t; ++casenum) {
        int n, s, p;
        int count = 0;
        int max = 0;
        int num[100] = {0};
        cin >> n >> s >> p;
        for (int i = 0; i < n; ++i)
            cin >> num[i];
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                if (num[i] > num[j]) {
                    int tmp = num[i];
                    num[i] = num[j];
                    num[j] = tmp;
                }
        for (int i = 0; i < n; ++i) {
            if (num[i] >= 2 && num[i] <= 28) {
               int p_min = (num[i] + 1) / 3;
               int p_max = p_min + 1;
               if (num[i] > p_min * 3)
                   p_min += 1;
               if (p_min >= p)
                   ++max;
               else if (p_max >= p && count < s) {
                    ++count;
                    ++max;
               }
            }
            else if (num[i] >= p)
                ++max;
        }
        cout << "Case #" << casenum << ": " << max << endl;
        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
