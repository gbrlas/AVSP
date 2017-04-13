#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dw(size_t t)
{
    typedef vector <size_t> vn;
    typedef vector <vn> vvn;
    const size_t sz = 4;

    vvn arg1(sz, vn(sz)), arg2(sz, vn(sz));
    size_t r1i, r2i;

    cin >> r1i;
    for (size_t i = 0; i < sz; i++) {
        for (size_t j = 0; j < sz; j++) {
            cin >> arg1[i][j];
        }
    }

    cin >> r2i;
    for (size_t i = 0; i < sz; i++) {
        for (size_t j = 0; j < sz; j++) {
            cin >> arg2[i][j];
        }
    }

    r1i--;
    r2i--;

    vn r1(arg1[r1i]), r2(arg2[r2i]), cand;
    for (size_t x : r1) {
        if (find(r2.begin(), r2.end(), x) != r2.end()) {
            cand.push_back(x);
        }
    }

    if (cand.size() == 0) {
        cout << "Case #" << t << ": Volunteer cheated!" << endl;
    } else if (cand.size() == 1) {
        cout << "Case #" << t << ": " << cand[0] << endl;
    } else {
        cout << "Case #" << t << ": Bad magician!" << endl;
    }
}

int main()
{
    size_t T;
    cin >> T;

    for (size_t i = 0; i < T; i++) {
        dw(i + 1);
    }
}

