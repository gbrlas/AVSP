#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <ctime>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DMAX 5005
#define LMAX 20

int n, d, l;
int p[DMAX][LMAX];
int s[LMAX];

string getNext(string& s)
{
	string r = "";
	if (s[0] != '(') 
	{
		r += s[0];
		s.erase(0, 1);
	}
	else
	{
		int l = 0;
		while (s[l] != ')') l++;
		r = s.substr(1, l - 1);
		s.erase(0, l + 1);
	}
	return r;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    scanf("%d %d %d\n", &l, &d, &n);

    string str;
    forn(i, d)
    {
        getline(cin, str);
        forv(j, str)
        {
            p[i][j] = 1 << int(str[j] - 'a');            
        }
    }


    forn(i, n)
    {
        getline(cin, str);
        string t;
        forn(j, l)
        {
            s[j] = 0;
            t = getNext(str);
            forv(k, t)
            {
                s[j] |= (1 << int(t[k] - 'a'));
            }
        }

        int ans = 0;
        forn(j, d)
        {
            bool ok = true;
            forn(k, l)
            {
                if (!(s[k] & p[j][k]))
                {
                    ok = false;
                    break;
                }
            }            
            if (ok) ans++;
        }
        printf("Case #%d: %d\n", i + 1, ans);
    }
    return 0;
}
            
