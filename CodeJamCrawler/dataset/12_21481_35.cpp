#include <fstream>
#include <cmath>
#include <string.h>
#include <set>

int power_of_10[7] ={1, 10, 100, 1000, 10000, 100000, 100000};

int get_recycled_num(int num, int num_of_digits, int shift) {
    int ret = 0;
    ret = num/power_of_10[shift] + (num%power_of_10[shift])*power_of_10[num_of_digits-shift];
}

int get_num_of_digits(int num) {
    return std::log10(num)+1;
}

int main(int argc, char *argv[]) {
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);
    
    int cases = 0;
    in >> cases;
    for (int i = 1; i <= cases; i++) {
        int begin = 0, end = 0;
        in >> begin >> end;
        int num_of_digits = get_num_of_digits(begin);
        int total_size = 0;
        for (int num = begin; num <= end; num++) {
            std::set<int> recycle_set;
            for (int shift = 1; shift < num_of_digits; shift++) {
                int cycled_num = get_recycled_num(num, num_of_digits, shift);
                if (cycled_num <= end && cycled_num > num) {
                    recycle_set.insert(cycled_num);
                }
            }
            total_size += recycle_set.size();
        }
        out << "Case #" << i << ": " << total_size << std::endl;
    }
    return 0;
}
