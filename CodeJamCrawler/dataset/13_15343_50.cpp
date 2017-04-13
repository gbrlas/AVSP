#include <iostream>
#include <vector>

bool isPalindrome(int n) {
    int r = 0;
    int o = n;

    while (o > 0) {
        r = r*10 + (o%10);
        o /= 10;
    }

    if (n == r)
        return true;

    return false;
}

int main() {
    int numCases;
    int a, b;
    int total = 0;
    std::vector<int> v(1001,0);

    for (int i = 1; i*i <= 1000; ++i) {
        if (isPalindrome(i)) {
            int j = i*i;

            if (isPalindrome(j))
                v[j] = 1;
        }
    }

    std::cin >> numCases;

    for (int i = 0; i < numCases; ++i) {
        total = 0;
        std::cin >> a >> b;

        for (int j = a; j <= b; ++j) {
            total += v[j];
        }

        std::cout << "Case #" << i+1 << ": " << total << "\n";
    }

    return 0;
}
