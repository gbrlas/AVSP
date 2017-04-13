#include <iostream>
#include <string>
#include <vector>

int main()
{
    int L, D, N;
    std::cin >> L >> D >> N;
    std::vector<std::string> dict(D);
    for (int i = 0; i < D; ++i)
        std::cin >> dict[i];

    for (int cs = 1; cs <= N; ++cs) {
        std::vector<std::string> cur(dict);
        std::string code;
        std::cin >> code;
        int c = 0;
        for (int i = 0; i < L; ++i) {
            std::vector<bool> let(26, false);
            if (code[c] == '(') {
                while (code[++c] != ')') {
                    let[code[c] - 'a'] = true;
                }
            } else {
                let[code[c] - 'a'] = true;
            }
            ++c;
            for (int j = 0; j < cur.size(); ++j) {
                if (!let[cur[j][i] - 'a']) {
                    cur[j] = cur[cur.size() - 1];
                    cur.pop_back();
                    --j;
                    continue;
                }
            }
        }
        std::cout << "Case #" << cs << ": " << cur.size() << std::endl;
    }
}
