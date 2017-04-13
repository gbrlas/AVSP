#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main()
{
    int T;
    string map = "ynficwlbkuomxsevzpdrjgthaq";
    string s;
    int j;

    cin >> T;
    getline(cin,s);
    FOR (t, T) {
        cout << "Case #" << t + 1 << ": ";
        getline(cin, s); 
        FOR (i,s.size()) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                for (j=0; j<26; j++) {
                    if (map[j] == s[i])
                        break;
                }
                cout << (char)(j + 'a');
               
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
