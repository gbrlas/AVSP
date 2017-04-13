#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int solve(const string& s1, const string& s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int> > f(s1.length() + 1, vector<int>(s2.length() +1, 0));

    for (int i = 0; i < m; ++i)
        f[0][i] = 1;

    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = f[i][j-1];
            if (s1[i-1] == s2[j-1]) {
                f[i][j] += f[i-1][j-1];
            }
            f[i][j] = f[i][j] % 10000;
        }
    }
    return f[n][m];
}

int main()
{
    int n = 0;
    cin >> n;
    string line("welcome to code jam");
    string s;
    getline(cin, s);
        
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        cout << "Case #" << i+1 << ": " << setw(4) << setfill('0') << solve(line, s) << endl;
    }
    
    return 0;
}
