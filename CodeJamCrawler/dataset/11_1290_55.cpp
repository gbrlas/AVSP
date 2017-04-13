#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <utility>
#include <queue>

using namespace std;

int main() {
  int t;
  cin>>t;
  for (int tt = 1; tt <= t; ++tt) {
    map< pair< char, char >, char > conv;
    map< char, vector< char > > opp;
    queue< char > q;
    int c, d, n;
    cin>>c;
    for (int i = 0; i < c; ++i) {
      string s;
      cin>>s;
      conv[make_pair(s[0], s[1])] = s[2];
      conv[make_pair(s[1], s[0])] = s[2];
    }
    cin>>d;
    for (int i = 0; i < d; ++i) {
      string s;
      cin>>s;
      opp[s[0]].push_back(s[1]);
      opp[s[1]].push_back(s[0]);
    }
    cin>>n;
    string s;
    cin>>s;
    for (int i = 0; i < s.size(); ++i) {
      q.push(s[i]);
    }

    vector< char > flist;
    map< char, int > used;
    while (!q.empty()) {
      char ch = q.front();
      q.pop();
      if (flist.size()) {
        char nch;
        if (((nch = conv[make_pair(ch, flist.back())]) >= 'A') || ((nch = conv[make_pair(flist.back(), ch)]) >= 'A')) {
          --used[flist.back()];
          flist.pop_back();
          flist.push_back(nch);
        } else {
          bool clear = false;
          for (vector< char >::iterator i = opp[ch].begin(); i != opp[ch].end(); ++i) {
            if (used[*i]) {
              clear = true;
              break;
            }
          }
          if (clear) {
            used.clear();
            flist.clear();
            continue;
          }
          flist.push_back(ch);
          ++used[ch];
        }
      } else {
        flist.push_back(ch);
        ++used[ch];
      }
    }
    cout<<"Case #" << tt <<": [";
    for (int i = 0; i < flist.size(); ++i) {
      if (i) {
        cout<<", ";
      }
      cout<<flist[i];
    }
    cout<<"]"<<endl;
  }
}
