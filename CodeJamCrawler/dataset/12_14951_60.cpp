#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>


using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

typedef vector < string > vs;

vs in, out;

vector < int > next(200, -1);
vector < int > was(200, false);



void update_mapping(string s1, string s2) {
    //cout << sz(s1) << " " << sz(s2) << endl;
    for (int i = 0; i < sz(s1); ++i) {
        char c1 = s1[i];
        if (next[c1] != -1) {
            //printf("was = [%c], ", next[c1]);
            //printf("now = [%c]\n", s2[i]);
            assert(s2[i] == next[c1]);
        } else {
            next[c1] = s2[i];
            was[s2[i]] = true;
        }
    }
}

void solve() {
    string s;
    getline(cin, s);
    for (int i = 0; i < sz(s); ++i) {
        s[i] = next[ s[i] ];
       assert (s[i] != -1); 
    }
    cout << s << endl;
}

int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);

    in.pb("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    in.pb("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    in.pb("de kr kd eoya kw aej tysr re ujdr lkgc jv");
    in.pb("qz");

    out.pb("our language is impossible to understand");
    out.pb("there are twenty six factorial possibilities");
    out.pb("so it is okay if you want to just give up");
    out.pb("zq");
   

    for (int i = 0; i < sz(in); ++i) {
        update_mapping(in[i], out[i]);
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        if (next[i] == -1) printf("%c\n", i);
    }


    int T;
    cin >> T;

    string t;
    getline(cin, t);
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }


    return 0;
}

