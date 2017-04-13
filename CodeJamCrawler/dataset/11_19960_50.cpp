#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;


int main() {

    int testcaseCnt;
    cin >> testcaseCnt;

    for (int i = 0; i < testcaseCnt; ++i) {
        long sum;
        int xorSum;
        int cnt;
        cin >> cnt;
        int min;
        cin >> min;
        xorSum = min;
        sum = min;

        for (int j = 1; j < cnt; ++j) {
            int k;
            cin >> k;
            xorSum = xorSum ^ k;
            sum += k;
            if (k < min) { min = k; }
        }

        if (xorSum != 0) {
            cout << "Case #" << (i + 1) << ": NO" << endl;
        } else {
            cout << "Case #" << (i + 1) << ": " << (sum - min) << endl;
        }
    }
}
