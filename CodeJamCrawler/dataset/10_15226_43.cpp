#define _IFS_ "C-small.in"
#define _OFS_ "C-small.out"

#include <fstream>

using namespace std;

int main (int argc, char** argv) {
    ifstream ifs (_IFS_);
    ofstream ofs (_OFS_);
    int T, R, k, c, N, p, size;
    ifs >> T;
    for (int i = 1; i <= T; ++i) {
        ifs >> R >> k >> N;
        p = 0;
        c = 0;
        int q [N];
        size = 0;
        for (int j = 0; j < N; ++j) {
            ifs >> q[j];
            size += q[j];
        }
        int index = 0;
        for (int j = 0; j < R; ++j) {
            if (size > k) {
                while (c + q[index] <= k) {
                    c+= q[index];
                    if (index == N-1)
                        index = 0;
                    else 
                        ++index;
                }
                p += c;
                c = 0;
            } else
                p += size;
        }
        ofs << "Case #" << i << ": " << p << '\n';
    }
    ofs.close();
    return 0;
}
