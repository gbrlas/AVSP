#include <fstream>

int main(int argc, char *argv[]) {
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);
    
    int cases = 0;
    in >> cases;
    int n = 0, s = 0, p = 0;
    int buckets[31];
    for (int i = 1; i <= cases; i++) {
        for (int j = 0; j < 31; j++) {
            buckets[j] = 0;
        }
        in >> n >> s >> p;
        for (int j = 0; j < n; j++) {
            int point;
            in >> point;
            buckets[point]++;
        }
        int maximum_num = 0;
        if (p > 1) {
            int threshold1 = p+p-1+p-2;
            int threshold2 = p+p-2+p-2;

            for (int j = 30; j > threshold1; j--) {
                maximum_num += buckets[j];
            }

            if (threshold1 > threshold2) {
                maximum_num += std::min(s, buckets[threshold1]+buckets[threshold2]);
            }            
        } else if (p == 1) {
            for (int j = 30; j > 1; j--) {
                maximum_num += buckets[j];
            }
        } else {
            maximum_num = n;
        }
        out << "Case #" << i << ": " << maximum_num << std::endl;
    }
    return 0;
}
