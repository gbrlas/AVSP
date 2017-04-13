#include <iostream>
#include <list>
using namespace std;

int main() {
    int T, C, D, N;
    list<char> lis;
    list<char>::iterator it;
    char tabi['[']['['];
    char tabo['[']['['];
    cin >> T;
    for(int i = 0; i < T; i++) {
        for(int j = 0; j <= 'Z'; j++) {
            for(int k = 0; k <= 'Z'; k++) {
                tabi[j][k] = '$';
                tabo[j][k] = '$';
            }
        }
        cin >> C;
        string s;
        for(int j = 0; j < C; j++) {
            cin >> s;
            tabi[s[0]][s[1]] = s[2];
            tabi[s[1]][s[0]] = s[2];
        }
        cin >> D;
        for(int j = 0; j < D; j++) {
            cin >> s;
            tabo[s[0]][s[1]] = '%';
            tabo[s[1]][s[0]] = '%';
        }

        cin >> N;
        char c, temp;
        for(int j = 0; j < N; j++) {
            cin >> c;
            //cout << c << endl;
            if(!lis.empty()) {
                // check invoke
                if(tabi[lis.back()][c] != '$') {
                    temp = lis.back();
                    lis.pop_back();
                    lis.push_back(tabi[temp][c]);
                } else { // check opposed
                    bool found = false;
                    for(it = lis.begin(); it != lis.end(); it++) {
                        if(tabo[c][*it] == '%') {
                            lis.clear();
                            found = true;
                            break;
                        }
                    }
                    if(!found) {
                        lis.push_back(c);
                    }
                }
            } else {
                lis.push_back(c);
            }
        }
        list<char>::iterator ite;
        ite = lis.end();
        ite--;
        cout << "Case #" << (i + 1) << ": [";
        for(it = lis.begin(); it != ite; it++) {
            cout << *it << ", ";
        }
        if(!lis.empty()) cout << lis.back();
        cout << "]" << endl;
        lis.clear();
    }
    return 0;
}
