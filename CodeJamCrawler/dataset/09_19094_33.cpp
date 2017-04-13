#include <iostream>
#include <set>
using namespace std;

const int MAXL = 15;
const int MAXD = 5000;

string a[MAXD];
int L, D, N;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    cin >> L >> D >> N;
    for (int i = 0; i < D; i++) cin >> a[i];
    for (int x = 1; x <= N; x++) {
        cout << "Case #" << x << ": ";
        string b;
        cin >> b;
      //  cout << b << endl;
        int len = b.size();
        set<char> f[MAXL];
        int pos = 0;
        int sign = 0;
        for (int i = 0; i < len; i++) {
            if (b[i] == '(') { sign = 1;continue;}
            if (b[i] == ')') { sign = 0; pos++; continue; }
            if (sign == 0) {
                     f[pos].insert(b[i]);
                     pos++;
            }
            else f[pos].insert(b[i]);
        }
//        cout << pos << endl;
        int sum = 0;
        for (int i = 0; i < D; i++) {
            int ok = 1;
            for (int j = 0; j < L; j++) if (f[j].find(a[i][j]) == f[j].end()) {
                ok = 0; break;
            }
            sum += ok;
        }
        cout << sum << endl;
    }
//    while (1);
    return 0;
}


/*
3 5 4
abc
bca
dac
dbc
cba
(ab)(bc)(ca)
abc
(abc)(abc)(abc)
(zyx)bc


The first line of input contains 3 integers, L, D and N separated by a space. D lines follow, each containing one word of length L. These are the words that are known to exist in the alien language. N test cases then follow, each on its own line and each consisting of a pattern as described above. You may assume that all known words provided are unique.
*/
