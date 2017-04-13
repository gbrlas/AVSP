#include <set>
#include <map>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

int T, n;
vector<char> ans;
map<pair<char, char>, char> M;
set<pair<char, char> > S;

int bad(char a, char b)
{
    if (S.count(make_pair(a, b)) || S.count(make_pair(b, a)))
        return 1;
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    cin >> T;
    for (int TT = 1; TT <= T; TT ++)
    {
        M.clear();
        S.clear();
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            string s; cin >> s;
            M[make_pair(s[0], s[1])] = s[2];
            M[make_pair(s[1], s[0])] = s[2];
        }
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            string s; cin >> s;
            S.insert(make_pair(s[0], s[1]));
        }
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i ++)
        {
            ans.push_back(s[i]);
            if (ans.size() > 1 && M.count(make_pair(ans[ans.size() - 1], ans[ans.size() - 2])))
            {
                char New = M[make_pair(ans[ans.size() - 1], ans[ans.size() - 2])];
                vector<char>::iterator C = ans.end(); C --;
                ans.erase(C);
                C = ans.end(); C --;
                ans.erase(C);
                ans.push_back(New);
            }
            else 
                for (int j = 0; j < ans.size() - 1; j ++)
                    if (bad(ans[ans.size() - 1], ans[j]))
                    {
                        ans.clear(); break;
                    }
        }
        printf("Case #%d: [", TT);
        for (int i = 0; i < ans.size(); i ++)
        {
            if (i) cout << ", ";
            cout << ans[i];
        }
        cout << "]" <<endl;
    }
    return 0;
}
