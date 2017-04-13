#include <iostream>
#include <vector>
#include <string>
#include <map>

// assume correct input

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int count;
        std::map<std::string, int> engines;
        std::string name;

        std::cin >> count;
        std::getline(std::cin, name); // skip extra newline
        for (int j = 0; j < count; ++j) {
            std::getline(std::cin, name);
            engines[name] = j;
        }

        int switches = 0;
        int searches;

        std::cin >> searches;
        std::getline(std::cin, name); // skip extra newline
        std::vector<bool> used(count, false);
        int use_count = 0;
        for (int j = 0; j < searches; ++j) {
            std::getline(std::cin, name);
            int e = engines[name];
            if (!used[e]) {
                used[e] = true;
                if (++use_count == count) {
                    ++switches;
                    used.assign(count, false);
                    used[e] = true;
                    use_count = 1;
                }
            }
        }

        std::cout << "Case #" << i << ": " << switches << std::endl;
    }
}
