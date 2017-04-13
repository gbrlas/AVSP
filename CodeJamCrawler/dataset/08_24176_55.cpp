#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// assume correct input

typedef std::vector<int> vint;

int get_time()
{
    std::string time;
    std::cin >> time;
    std::istringstream iss(time);
    int h, m;
    char c;
    iss >> h >> c >> m;
    return h * 60 + m;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int ttime;
        std::cin >> ttime;

        int na, nb;
        std::cin >> na >> nb;

        vint dep_a(na), dep_b(nb), arr_a(nb), arr_b(na);

        for (int j = 0; j < na; ++j) {
            dep_a[j] = get_time();
            arr_b[j] = get_time() + ttime;
        }

        for (int j = 0; j < nb; ++j) {
            dep_b[j] = get_time();
            arr_a[j] = get_time() + ttime;
        }

        std::sort(dep_a.begin(), dep_a.end());
        std::sort(dep_b.begin(), dep_b.end());
        std::sort(arr_a.begin(), arr_a.end());
        std::sort(arr_b.begin(), arr_b.end());

        int tr_a = 0;
        int tr_b = 0;

        int extra = 0;
        int k = 0;
        for (int j = 0; j < na; ++j) {
            while (k < nb && arr_a[k] <= dep_a[j]) {
                ++k;
                ++extra;
            }
            if (extra > 0)
                --extra;
            else
                ++tr_a;
        }

        extra = 0;
        k = 0;
        for (int j = 0; j < nb; ++j) {
            while (k < na && arr_b[k] <= dep_b[j]) {
                ++k;
                ++extra;
            }
            if (extra > 0)
                --extra;
            else
                ++tr_b;
        }

        std::cout << "Case #" << i << ": " << tr_a << " " << tr_b << std::endl;
    }
}
