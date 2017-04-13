#include "../../../template.h"

void print_map(pair<int, int> p) {
    cout << p.first << ' ' << p.second << endl;
}
int my_atoi(string &s) {
    int a = 0;
    for (int i=0; i<s.length(); i++) {
        a= a*10 + (s[i] - '0');
    }
    return a;
}
string my_atoi(int n) {
    string s("");
    while (n != 0) {
        s += (char)(n % 10 + '0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(void) {
    const int MAX = 2000000;
    multimap<int, int> m;

    for (int n = 12; n <= MAX; n++) {
        string number(my_atoi(n));
        string s(number);
        for (int j = 1; j <= s.length() - 1; j++) {
            char x = s[0];
            s.erase(s.begin());
            s.insert(s.end(), x);
            if (s.compare(number) == 0) break;
            int num = my_atoi(s);
            if (num < MAX && num > n)
                m.insert(MP(n, num));
        }
    }
    //for_each(m.begin(), m.end(), print_map);

    int T, A, B;
    cin >> T;

    multimap<int, int>::iterator it1, it2, it;
    for (int x=1; x<=T; x++) {
        cin >> A >> B;
        it1 = m.lower_bound(A);
        it2 = m.upper_bound(B);
        long count = 0;
        for (it = it1; it != it2; it++) {
            if ((*it).second <= B)
                count++;
        }
        cout << "Case #" << x << ": " << count << endl;
    }   
}
