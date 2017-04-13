#include <iostream>
#include <string>

#ifndef TREE_H
#define TREE_H

#include <vector>
#include <functional>

template <class T, class Plus = std::plus<T> >
struct tree {
    tree(unsigned n)
        : table(n, T())
        {
        }

    void clear()
        {
            table.assign(table.size(), T());
        }

    void add(unsigned begin, T x)
        {
            if (begin == 0 && table.size() > 0) {
                table[0] = plus(table[0], x);
                return;
            }

            while (begin < table.size()) {
                table[begin] = plus(table[begin], x);
                unsigned lsb = begin & (-begin);
                begin += lsb;
            }
        }

    T get(unsigned index)
        {
            if (index > table.size() - 1)
                index = table.size() - 1;

            T r = table[index];
            unsigned m = ~1;
            while (index) {
                unsigned new_index = index & m;
                if (new_index != index) {
                    index = new_index;
                    r = plus(r, table[index]);
                }
                m <<= 1;
            }
        }

    std::vector<T> table;
    Plus plus;
};

#endif // TREE_H

const std::string welcome = "welcome to code jam";
const int welcome_len = welcome.size();

struct pl {
    int operator()(int a, int b)
        {
            return (a + b) % 1000;
        }
};

int main()
{
    int N;
    std::cin >> N;
    std::string line;
    std::getline(std::cin, line);
    for (int cs = 1; cs <= N; ++cs) {
        std::getline(std::cin, line);
        int len = line.size();
        tree<int, pl> t0(len + 1);
        tree<int, pl> t1(len + 1);
        tree<int, pl>* src = &t0;
        tree<int, pl>* dst = &t1;
        dst->add(0, 1);
        for (int i = 0; i < welcome_len; ++i) {
            tree<int, pl>* tmp = src;
            src = dst;
            dst = tmp;
            dst->clear();
            for (int j = i; j <= len - welcome_len + i; ++j) {
                if (line[j] == welcome[i])
                    dst->add(j + 1, src->get(j));
            }
        }
        std::cout << "Case #" << cs << ": ";
        int x = dst->get(len);
        if (x < 10)
            std::cout << '0';
        if (x < 100)
            std::cout << '0';
        if (x < 1000)
            std::cout << '0';
        std::cout << x << std::endl;
    }
}
