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

string G[4], s;

int main()
{
	#ifndef ONLINE_JUDGE
	//freopen(InputFileName, "r", stdin);
	//freopen(OutputFileName, "w", stdout);
	#endif
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cin >> G[0] >> G[1] >> G[2] >> G[3];
        s = G[0]+"!"+G[1]+"!"+G[2]+"!"+G[3]+"!";
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
                s += G[j][i];
            s += '!';
        }
        for (int i = -3; i < 4; ++i)
        {
            for (int j = max(-i, 0); i+j < 4 && j < 4; ++j)
                s += G[j][i+j];
            s += '!';
        }
        for (int i = 0; i < 7; ++i)
        {
            for (int j = max(i-3, 0); i-j >= 0 && j < 4; ++j)
                s += G[j][i-j];
            s += '!';
        }
        cout << "Case #" << Test << ": ";
        bool Alice = s.find("XXXX") != string::npos || s.find("TXXX") != string::npos || s.find("XTXX") != string::npos || s.find("XXTX") != string::npos || s.find("XXXT") != string::npos;
        bool Bob = s.find("OOOO") != string::npos || s.find("TOOO") != string::npos || s.find("OTOO") != string::npos || s.find("OOTO") != string::npos || s.find("OOOT") != string::npos;
        if (Alice)
            cout << "X won" << endl;
        else if (Bob)
            cout << "O won" << endl;
        else if (s.find(".") == string::npos)
            cout << "Draw" << endl;
        else
            cout << "Game has not completed" << endl;
    }
	return 0;
}
