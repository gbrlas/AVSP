#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>

#include <algorithm>

#include <vector>

#include <stack>
#include <queue>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int qn, pn;

int gcd(int a, int b) {
    if (b) return gcd(b, a%b);
    return a;
}

int ending;

int sub(int p1, int q1, int p2, int q2) {
    if (q1 == 0) {
        return 0;
    }
//    int qn, pn;
    if (p1 * q2 >= q1 * p2) {
        pn = p1 * q2 - p2 * q1;
        qn = q1 * q2;
//        cout << "pn" << pn << endl;
        if (pn == 0) {
            ending = true;
  //          printf("%d/%d - %d/%d stop\n", p1, q1, p2, q2);
            return 1;
        }
        int g = gcd(pn, qn);
        pn = pn / g;
        qn = qn / g;

 //       printf("%d/%d - %d/%d yes\n", p1, q1, p2, q2);
        return 1;
    } else {
        pn = p1;
        qn = q1;
//        printf("%d/%d - %d/%d no\n", p1, q1, p2, q2);
        return 0;
    }
}

int a[33];

void solve(int p1, int q1) {
    int p2 = 1;
    int q2 = 1;
    for (int i = 1; i < 33; i++) {
        q2 *= 2;
        a[i] = sub(p1, q1, p2, q2);
        if (ending) {
            break;
        }
        p1 = pn;
        q1 = qn;
    }
//    cout << p1 << " " << q1 << endl;
}

int main() {
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; ++Case) {
        int p, q;
        scanf("%d/%d", &p, &q);

        int g= gcd(p, q);
        p /= g;
        q /= g;

        int i = 1;
        int t = 0;
        while (i < q) {
            i *= 2;
            t += 1;
        }
//        cout << "i" << i << endl;
        if (i != q) {
//            cout << "impossible" << endl;
            printf("Case #%d: impossible\n", Case);
        } else {
            int t = 0;
            while (p < q) {
                p *= 2;
                t += 1;
            }
 //           cout << t << endl;
            printf("Case #%d: %d\n", Case, t);
        }
    }
}
