#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

// --------------------- Template ---------------------------------------------

#define FOR(i, f, t) for (int i = (int)(f); i < (int)(t); ++i)
#define FORN(i, n) for (int i = 0; i < (int)(n); ++i)

template <class T, class IT>
inline void PRINT(IT i1, IT i2) {
    cout << '['; copy(i1, i2, ostream_iterator<T>(cout, ", ")); cout << "]\n";
}


char nonbasic[256][256];
bool delelement[256][256];

string solve(const string& str)
{
    //int counts[256];
    string result;
    //fill(&counts[0], &counts[256], 0);
    FORN(i, str.size()) {
        result.push_back(str[i]);
        if (result.length() > 1) {
            char x;
            //cout << "last two: " << result[result.length()-1] << " and " << result[result.length()-2] << '\n';
            if ((x = nonbasic[result[result.length()-1]][result[result.length()-2]]) != 0) {
                //--counts[result[result.length-1]];
                //--counts[result[result.length-2]];
                result.erase(result.length()-2);
                result.push_back(x);
                //cout << "now: " << result << '\n';
                continue;
                //++counts[x];
            }
            FOR(j, 0, result.length() - 1) {
                //cout << "check: " << result[j] << " vs " << str[i] << '\n';
                if (delelement[result[j]][str[i]]) {
                    result.erase();
                    //cout << result[j] << ' ' << str[i] << endl;
                    break;
                }
            }
        }
    }
    return result;
}

void printnice(const string& str)
{
    cout << '[';
    FORN(i, str.length()) {
        if (i == 0) cout << str[i];
        else cout << ", " << str[i];
    }
    cout << ']';
}

#if 1
int main() {

    int cases;
    cin >> cases;
    FORN(i, cases) {
        FORN(ii, 256) FORN(jj, 256) nonbasic[ii][jj] = 0;
        FORN(ii, 256) FORN(jj, 256) delelement[ii][jj] = 0;
        int c, d, n;
        cin >> c;
        FORN(j, c) {
            string cmpl;
            cin >> cmpl;
            nonbasic[cmpl[0]][cmpl[1]] = cmpl[2];
            nonbasic[cmpl[1]][cmpl[0]] = cmpl[2];
            //cout << "read " << cmpl[0] << ' ' << cmpl[1] << '=' << cmpl[2] << '\n';
        }
        cin >> d;
        FORN(j, d) {
            string del;
            cin >> del;
            delelement[del[0]][del[1]] = 1;
            delelement[del[1]][del[0]] = 1;
        }
        cin >> n;
        string seq;
        cin >> seq;
        cout << "Case #" << i+1 << ": ";
        printnice(solve(seq));
        cout << endl;
    }

    return 0;
}
#endif
