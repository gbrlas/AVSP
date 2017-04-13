#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

char get_winner(map< char, int > mp) {
    if ((mp['O'] + mp['T']) == 4) {
        return 'O';
    }
    if ((mp['X'] + mp['T']) == 4) {
        return 'X';
    }
    return '-';
}

int main() {
    int n;
    cin>>n;
    for (int t = 1; t <= n; ++t) {
        cout<<"Case #"<<t<<": ";
        vector< string > v(4);
        for (int i = 0; i < 4; ++i) {
            cin>>v[i];
        }
        map< char, int > mp;
        for (int i = 0; i < 4; ++i) {
            ++mp[v[i][i]];
        }
        char res = get_winner(mp);
        if ((res == 'O') || (res == 'X')) {
            cout<<res<<" won"<<endl;
            continue;
        }
        mp.clear();
        for (int i = 0; i < 4; ++i) {
            ++mp[v[3 - i][i]];
        }
        res = get_winner(mp);
        if ((res == 'O') || (res == 'X')) {
            cout<<res<<" won"<<endl;
            continue;
        }
        bool fl = false;
        for (int j = 0; j < 4; ++j) {
            mp.clear();
            for (int i = 0; i < 4; ++i) {
                ++mp[v[i][j]];
            }
            res = get_winner(mp);
            if ((res == 'O') || (res == 'X')) {
                cout<<res<<" won"<<endl;
                fl = true;
                break;
            }
            mp.clear();
            for (int i = 0; i < 4; ++i) {
                ++mp[v[j][i]];
            }
            res = get_winner(mp);
            if ((res == 'O') || (res == 'X')) {
                cout<<res<<" won"<<endl;
                fl = true;
                break;
            }
        }
        if (fl) {
            continue;
        }
        int ct = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (v[i][j] == '.') {
                    ++ct;
                }
            }
        }
        if (ct) {
            cout<<"Game has not completed"<<endl;
        } else {
            cout<<"Draw"<<endl;
        }
    }
    return 0;
}

