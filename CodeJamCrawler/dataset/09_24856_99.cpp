#include <iostream>
#include <vector>
#include <map>

const int max_alt = 10000;
typedef std::vector<int> row;

int main()
{
    int T;
    std::cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        int H, L;
        std::cin >> H >> L;
        row r(L);
        std::vector<row> altitude(H, r);
        std::vector<row> grid(H, r);
        int cur = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < L; ++j) {
                std::cin >> altitude[i][j];
                grid[i][j] = cur++;
            }
        }

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < L; ++j) {
                int N = i > 0 ? altitude[i - 1][j] : max_alt;
                int W = j > 0 ? altitude[i][j - 1] : max_alt;
                int E = j < L - 1 ? altitude[i][j + 1] : max_alt;
                int S = i < H - 1 ? altitude[i + 1][j] : max_alt;
                if (N < altitude[i][j] && N <= W && N <= E && N <= S)
                    grid[i][j] = (i - 1) * L + j;
                else if (W < altitude[i][j] && W <= E && W <= S)
                    grid[i][j] = i * L + (j - 1);
                else if (E < altitude[i][j] && E <= S)
                    grid[i][j] = i * L + (j + 1);
                else if (S < altitude[i][j])
                    grid[i][j] = (i + 1) * L + j;
            }
        }

        bool change;
        do {
            change = false;
            for (int i = 0; i < H; ++i) {
                for (int j = 0; j < L; ++j) {
                    int g = grid[i][j];
                    int gi = g / L;
                    int gj = g % L;
                    if (grid[gi][gj] != g) {
                        grid[i][j] = grid[gi][gj];
                        change = true;
                    }
                }
            }
        } while (change);

        char c = 'a';
        std::map<int, char> m;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < L; ++j) {
                if (m.find(grid[i][j]) == m.end())
                    m[grid[i][j]] = c++;
            }
        }

        std::cout << "Case #" << cs << ":" << std::endl;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < L; ++j) {
                std::cout << m[grid[i][j]];
                if (j == L - 1)
                    std::cout << std::endl;
                else
                    std::cout << " ";
            }
        }
    }
}
