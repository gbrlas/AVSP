
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("A-large.in");
ofstream fout("A-large.out");

int l, d, n, ans;
string str[5001];
string temp;
bool flag;

int main() {
    int p;
    fin >> l >> d >> n;
    for (int i = 1; i <= d; i++) fin >> str[i];
    for (int o = 1; o <= n; o++) {
        fin >> temp;
        ans = 0;
        for (int i = 1; i <= d; i++) {
            p = 0;
            flag = true;
            for (int j = 0; j < l; j++) {
                if (temp[p] >= 'a' && temp[p] <= 'z')
                    if (temp[p] != str[i][j]) {
                        flag = false;
                        break;
                    }
                if (temp[p] == '(') {
                    while (true) {
                        p++;
                        if (temp[p] == ')') {
                            flag = false;
                            break;
                        }
                        if (str[i][j] == temp[p]) {
                            while (temp[p] != ')') p++;
                            break;
                        }
                    }
                }
                if (p == temp.length()) break;
                p++;
            }
            if (flag) ans++;
        }
        fout << "Case #" << o << ": " << ans << endl;
    }
    return 0;
}

