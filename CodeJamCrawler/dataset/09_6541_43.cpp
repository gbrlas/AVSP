/* 
 * File:   с.cc
 * Author: cain
 *
 * Created on 4 Сентябрь 2009 г., 1:06
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
/*
 * 
 */
char st[] = "welcome to code jam";
int dp[555][21];

int main(int argc, char** argv) {
    int t;
    int n = 19;
    string s;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t; getline(cin, s);
    for (int z = 0; z < t; ++ z)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        getline(cin, s);
        for (int i = 1; i <= s.length(); ++ i)
        {
            cerr << s[i - 1] << ": ";
            for (int j = 0; j < 20; ++ j)
                dp[i][j] = dp[i - 1][j];
            for (int j = 1; j < 20; ++ j)
                if (s[i - 1] == st[j - 1])
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000;
            for (int j = 0; j < 20; ++ j)
                cerr << dp[i][j] << ' ';
            cerr << endl;
        }
        printf("Case #%d: %04d\n", z + 1, dp[s.length()][19]);
    }
    return (EXIT_SUCCESS);
}

