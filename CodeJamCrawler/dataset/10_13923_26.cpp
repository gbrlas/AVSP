#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull findcost(string &s, multimap<string, string> &dirs)
{
    ull cost = 0;
    if (s.empty()) {
        return 0;
    }
    size_t pos = s.find_last_of('/');
    string parent = s.substr(0, pos);
    string dir = s.substr(pos+1, s.length());
    typedef multimap<string, string>::const_iterator I;
    pair<I, I> dirPair = dirs.equal_range(dir);
    bool exists = false;
    for (I i = dirPair.first; i != dirPair.second; ++i) {
        if (i->second == parent) {
            exists = true;
            break;
        }
    }
    if (!exists) {
        cost += findcost(parent, dirs);
        cost += 1;
        dirs.insert(make_pair<string, string>(dir, parent));
    }
    return cost;
}
int main()
{
    int T;
    cin >> T;
    for (int test=1; test<=T; ++test) {
        int M, N;
        cin >> N >> M;
        string dummy;
        getline(cin , dummy);
        multimap<string, string> dirs;
        for (int i=0; i<N; ++i) {
            string s;
            getline(cin , s);
            size_t pos = s.find_last_of('/');
            string parent = s.substr(0, pos);
            string dir = s.substr(pos+1, s.length());
            dirs.insert(make_pair<string, string>(dir, parent));
        }
        ull cost = 0;
        for(int i=0; i<M; ++i) {
            string s;
            getline(cin, s);

            cost += findcost(s, dirs);
        }
        cout << "Case #" << test << ": " <<cost << endl;
    }
    return 0;
}