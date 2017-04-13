#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

int N, M;
set<string> exist;
vector<string> create;

//char tmp[102];
string tmp;

int main() {
  int caseN;
  cin >> caseN;

  for (int cc = 1; cc <= caseN; ++cc) {
    cout << "Case #" << cc << ": " ;

    cin >> N >> M;
    exist.clear();
    create.clear();

    //cout << endl;

    // exist
    for (int i = 0; i < N; ++i) {
      cin >> tmp;

      for (int last = 1; ; ++last) {
        last = tmp.find("/", last);
        if (last == string::npos) break;
        exist.insert(tmp.substr(0, last));
        //cout << tmp.substr(0, last) << endl;
      }
      exist.insert(tmp);
      //cout << tmp << endl;
    }

    for (int i = 0; i < M; ++i) {
      cin >> tmp;
      create.push_back(tmp);
    }
    sort(create.begin(), create.end());

    int cnt = 0;
    for (int i = 0; i < create.size(); ++i) {
      string &current = create[i];
      if (exist.find(current) != exist.end()) continue;

      //cout << current << endl;
      for (int last = current.length(); ; --last) {
        last = current.find_last_of("/", last);
        //cout << last << endl;
        if (last == 0 ||
            last == string::npos ||
            exist.find(current.substr(0, last)) != exist.end()) {

          // test search
          for (++last; last = current.find("/", last); ++last) {
            if (last == string::npos) break;
            exist.insert(current.substr(0, last));
            //cout << "add " << current.substr(0, last) << endl;
            cnt++;
          }
          exist.insert(current);
          //cout << "add " << current << endl;
          cnt++;

          break;
        }
      }
    }
    cout << cnt;
    cout << endl;
  }

  return 0;
}

