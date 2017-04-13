#include <iostream>

int main() {
    int numCases;
    int m, n;
    int minHeight = 100;
    int lawn[100][100];
    bool possible = true;

    std::cin >> numCases;

    for (int i = 0; i < numCases; ++i) {
        std::cin >> m >> n;

        std::cout << "Case #" << i+1 << ": ";

        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                std::cin >> lawn[j][k];
                if (lawn[j][k] < minHeight)
                    minHeight = lawn[j][k];
            }
        }

        if (m == 1 || n == 1) {
            std::cout << "YES\n";
            continue;
        }

        for (int j = 0; j < m; ++j) {
            if (possible) {
                for (int k = 0; k < n; ++k) {
                    if (lawn[j][k] == minHeight) {
                        bool b = true;
                        bool c = true;
                        for(int z = 0; z < m; ++z) {
                            if (lawn[z][k] != minHeight)
                                b = false;
                        }
                        for (int z = 0; z < n; ++z) {
                            if (lawn[j][z] != minHeight)
                                c = false;
                        }

                        if(!b && !c)
                            possible = false;
                    }
                }
            } else {
                break;
            }
        }

        if (possible)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";

        possible = true;
        minHeight = 100;
    }

    return 0;
}
