#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int t;
int c, d, n;

map<string, char> com;
map<string, bool> opo;

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.txt");

    fin >> t;

    for (int cn = 0; cn < t; cn++) {
        cout << " case " << cn + 1 << endl;
        fin >> c;
        com.clear();
        opo.clear();
        for (int i = 0; i < c; i++) {
            string tmp;
            fin >> tmp;
            string ce = tmp.substr(0, 2);
            cout << ce << "=>" << tmp[2] << endl;
            com[ce] = tmp[2];
            reverse(ce.begin(), ce.end());
            cout << ce << "=>" << tmp[2] << endl;
            com[ce] = tmp[2];
        }
        fin >> d;
        for (int i = 0; i < d; i++) {
            string tmp;
            fin >> tmp;
            opo[tmp] = true;
            cout << tmp << "=>-X-" << endl;
            reverse(tmp.begin(), tmp.end());
            opo[tmp] = true;
            cout << tmp << "=>-X-" << endl;
        }
        fin >> n;
        string frm;
        fin >> frm;
        string res(1, frm[0]);
        for (int i = 1; i < n; i++) {
            string tmp("  ");
            tmp[0] = *(--res.end());
            tmp[1] = frm[i];
            if (com.find(tmp) != com.end()) {
                *(--res.end()) = com[tmp];
                cout << tmp << "-->" << com[tmp] << endl;
            }
            else {
                bool cl = false;
                for (string::iterator j = res.begin(); j < res.end(); j++) {
                    tmp[0] = *j;
                    if (opo[tmp]) {
                        res.clear();
                        cl = true;
                        cout << tmp << "-->-X-" << endl;
                        break;
                    }
                }
                if (!cl) {
                    res.append(1, frm[i]);
                }
            }
        }
        fout << "Case #" << cn + 1 << ": [";
        for (string::iterator j = res.begin(); j < res.end(); j++) {
            if (j != res.begin()) {
                fout << ", ";
            }
            fout << *j;
        }
        fout << "]" << endl;
    }
    return 0;
}
