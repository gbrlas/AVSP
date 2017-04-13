#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(long long x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x%10);
        x /= 10;
    }
    for (size_t i = 0; i < digits.size(); ++i)
        if (digits[i] != digits[digits.size() - i - 1])
            return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long A, B;
        cin >> A >> B;
        int count = 0;
        for (long long x = 1; ; ++x) {
            long long sq = x*x;
            if (sq < A)
                continue;
            if (sq > B)
                break;
            if (isPalindrome(x) && isPalindrome(sq))
                ++count;
        }
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
