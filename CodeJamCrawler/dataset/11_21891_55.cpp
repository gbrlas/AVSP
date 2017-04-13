#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int c, d, n;
        string a[100], b[100], s, m = "";
        cin >> c;
        for (int j = 0; j < c; j++)
            cin >> a[j];
        cin >> d;
        for (int j = 0; j < d; j++)
            cin >> b[j];
        cin >> n;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                m += s[j];
            } else {
                bool flag = false;
                for (int k = 0; !flag && k < c; k++) {
                    if ((a[k][0] == m[m.length() - 1] && a[k][1] == s[j]) || (a[k][0] == s[j] && a[k][1] == m[m.length() - 1])) {
                        m[m.length() - 1] = a[k][2];
                        flag = true;
                    }
                }
                for (int k = 0; !flag && k < d; k++) {
                    for (int l = 0; !flag && l < m.length(); l++) {
                        if ((b[k][0] == m[l] && b[k][1] == s[j]) || (b[k][0] == s[j] && b[k][1] == m[l])) {
                            m = "";
                            flag = true;
                        }
                    }
                }
                if (!flag)
                    m += s[j];
            }
        }
        cout << "Case #" << i + 1 << ": " << "[";
        if (m.length() == 0) {
            cout << "]" << endl;
        } else if (m.length() ==  1) {
            cout << m << "]" << endl;
        } else {
            cout << m[0];
            for (int j = 1; j < m.length(); j++)
                cout << ", " << m[j];
            cout << "]" << endl;
        }
    }
    return 0;
}
