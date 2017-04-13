// I just use the calc of Windows Vista to calc it. ^_^

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string w[31];
        w[30] = "647";
    w[29] = "135";
    w[28] = "791";
    w[27] = "903";
    w[26] = "407";
    w[25] = "135";
    w[24] = "351";
    w[23] = "743";
    w[22] = "527";
    w[21] = "855";
    w[20] = "151";
    w[19] = "263";
    w[18] = "607";
    w[17] = "095";
    w[16] = "991";
    w[15] = "463";
    w[14] = "447";
    w[13] = "055";
    w[12] = "471";
    w[11] = "943";
    w[10] = "047";
    w[9] = "335";
    w[8] = "991";
    w[7] = "903";
    w[6] = "607";
    w[5] = "935";
    w[4] = "751";
    w[3] = "143";
    w[2] = "027";
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string res;
        int n;
        cin >> n;/*
        double now = 1;
        n = 7;
        for (int i = 1; i <= n; i++) {
            now = now * (3 + sqrt(5));
            while (now > 10000) now = now - 10000;
        }
        long long rr = (long long) now;
        res.push_back(rr / 100 % 10 + '0');
        res.push_back(rr / 10 % 10 + '0');
        res.push_back(rr % 10 + '0');*/
        cout << "Case #" << t <<": " << w[n] << endl;
    }
 //   while (1);
    return 0;
}
