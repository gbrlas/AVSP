#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;




int main() {

    istream& in (cin);
    //ifstream fin ("/home/ciobi/cpp/Contests/in/CJ-2011-Magicka.txt"); istream& in (fin);

    int testcaseCnt;
    in >> testcaseCnt;

    for (int i = 0; i < testcaseCnt; ++i) {
        char combines [26][26];
        set<char> destroys [26];
        int lstCnt [26];
        for (int p = 0; p < 26; ++p) {
            for (int j = 0; j < 26; ++j) {
                combines[p][j] = 0;
                //destroys[p][j] = false;
            }
            lstCnt[p] = 0;
        }

        int k;
        string bfr;

        in >> k;
        for (int j = 0; j < k; ++j) {
            in >> bfr;
            combines[bfr[0] - 'A'][bfr[1] - 'A'] = combines[bfr[1] - 'A'][bfr[0] - 'A'] = bfr[2];
        }

        in >> k;
        for (int j = 0; j < k; ++j) {
            in >> bfr;
            //combines[bfr[0] - 'A'][bfr[1] - 'A'] = combines[bfr[1] - 'A'][bfr[0] - 'A'] = bfr[2];
            destroys[bfr[0] - 'A'].insert(bfr[1]);
            destroys[bfr[1] - 'A'].insert(bfr[0]);
        }

        in >> k;
        in >> bfr;

        vector<char> lst;
        //map<char, int> lstMap;
        for (int j = 0; j < bfr.size(); ++j) {
            char c = bfr[j];
            if (!lst.empty()) {
                char c1 (lst.back());
                char cmb (combines[c - 'A'][c1 - 'A']);
                if (cmb != 0) {
                    lst[lst.size() - 1] = cmb;
                    lstCnt[cmb - 'A']++;
                    lstCnt[c1 - 'A']--;
                    continue;
                }

                for (set<char>::const_iterator it = destroys[c - 'A'].begin(), end = destroys[c - 'A'].end(); it != end; ++it) {
                    char c (*it);
                    if (lstCnt[c - 'A'] > 0) {
                        lst.clear();
                        for (int p = 0; p < 26; ++p) { lstCnt[p] = 0; }
                        break;
                    }
                }

                if (lst.empty()) {
                    continue;
                }
            }
            lst.push_back(c);
            lstCnt[c - 'A']++;
        }

        cout << "Case #" << (i + 1) << ": [";
        for (int j = 0; j < lst.size(); ++j) {
            if (j > 0) {
                cout << ", ";
            }
            cout << lst[j];
        }
        cout << "]" << endl;
    }
}




