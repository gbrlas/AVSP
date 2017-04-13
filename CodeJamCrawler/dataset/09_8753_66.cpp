#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> tokenize(const string& str, int num = -1)
{
    vector<string> retval;
    if (num > 0) {
        retval.resize(num);
    }
    static const string p(")");
    size_t k = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != '(') {
            string toPush(str.begin()+i, str.begin()+i+1);
            if (k == retval.size()) {
                retval.push_back(toPush);
                ++k;
            } else {
                retval[k++] = toPush;
            }
        } else {
            size_t s = i+1;
            size_t e = str.find(p, s);
            if (k == retval.size()) {
                retval.push_back(str.substr(s, e-s));
                ++k;
            } else {
                retval[k++] = str.substr(s, e-s);
            }
            i += (e-s)+1;
        }
    }
    return retval;
}

struct AlienCode
{
    size_t numTokens;
    vector<string> tokens;
    size_t count;

    static set<string> language;
    static set<string> possibilities;

    static void buildPossibilities()
    {
        possibilities.clear();
        for (set<string>::iterator i = language.begin();
                i != language.end(); ++i) {
            const string& s = *i;
            for (size_t k = 1; k <= s.size(); ++k) {
                string sub = s.substr(0, k);
                possibilities.insert(s.substr(0, k));
            }
        }
    }

    AlienCode(const string& inp, int nTokens = -1)
    {
        tokens = tokenize(inp, nTokens);
        numTokens = tokens.size();
        count = 0;
    }

    void check(string s, int n)
    {
        if (n == numTokens) return;
        string t(s);
        size_t sz = s.size();
        t.push_back(' ');
        for (int i = 0; i < tokens[n].size(); ++i) {
            t[sz] = tokens[n][i];
            if (possibilities.find(t) != possibilities.end()) {
                if (n+1 == numTokens) {
                    ++count;
                } else {
                    check(t, n+1);
                }
            }
        }
    }

};

set<string> AlienCode::language;
set<string> AlienCode::possibilities;


int main()
{
    int l, d, n;
    cin >> l >> d >> n;
    AlienCode::language.clear();
    for (int i = 0; i < d; ++i) {
        string temp;
        cin >> temp;
        AlienCode::language.insert(temp);
    }
    AlienCode::buildPossibilities();
    vector<string> inp(n);
    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
    }
    for (int i = 0; i < n; ++i) {
        AlienCode alien(inp[i], l);
        alien.check(string(), 0);
        cout << "Case #" << (i+1) << ": " << alien.count << endl;
    }
    return 0;
}

