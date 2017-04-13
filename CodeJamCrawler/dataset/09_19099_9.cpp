#include<iostream>
#include <map>
using namespace std;

map<int, int> f;

map<int, int> get(int n)
{
     map<int, int> res;
     while (n > 0) {
           int m = n % 10;
           if (m != 0) {
           if (!res.count(m)) res[m] = 0;
           res[m]++;
           }
           n = n / 10;
     }
     return res;
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        if (n == 1000000) { cout << 10000000 << endl; continue; }
       // cout << n << endl;
        f = get(n);
        int m = n + 1;
        while (1) {
              map<int, int> ff = get(m);
              if (ff == f) break;
              m++;
        }        
        cout << m << endl;
    }

// while (1);       
        return 0;
}
