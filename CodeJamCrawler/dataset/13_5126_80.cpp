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

set<string> Ans;

inline void Convert(int k, string &s1, string &s2)
{
    s1 = s2 = "";
    for (; k; k >>= 1)
        s2 += (char)('0'+(k & 1));
    s1 = s2;
    for (int i = 0; i+1 << 1 <= (int)s1.length(); ++i)
        swap(s1[i], s1[s1.length()-1-i]);
}

bool Check(const string &s)
{
    int n = s.length()*2-1;
    for (int i = 0, j, cnt; i < n; ++i)
    {
        for (cnt = 0, j = 0; j < n; ++j)
            if (i-j >= 0 && i-j < n)
                cnt += (int)(s[j]-'0')+(int)(s[i-j]-'0');
        if (cnt >= 10)
            return 0;
    }
    Ans.insert(s);
    cerr << s << endl;
    return 1;
}

void Calc(string s)
{
    if (Check(s))
    {
        int n = s.length();
        for (int i = 0; i < n+1 >> 1; ++i)
            if (s[i] == '1')
            {
                s[i] = s[n-i-1] = '2';
                if (Check(s))
                {
                    for (int j = 0; j < i; ++j)
                    {
                        s[j] = s[n-j-1] = '2';
                        Check(s);
                        s[j] = s[n-j-1] = '1';
                    }
                }
                s[i] = s[n-i-1] = '1';
            }
    }
}

int main()
{
    ofstream fout("C_Res.txt");
    Ans.clear();
    string s1, s2;
    for (int i = 0; i < 1 << 25; ++i)
    {
        if (i == (i >> 18 << 18))
            cerr << '.';
        Convert(i, s1, s2);
        Calc(s1+s2);
        Calc(s1+'0'+s2);
        Calc(s1+'1'+s2);
    }
    Ans.insert("3");
    for (set<string>::iterator iter = Ans.begin(); iter != Ans.end(); ++iter)
        fout << (*iter) << endl;
    fout.close();
	return 0;
}
