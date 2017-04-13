#include <iostream>
#include <cstdio>
using namespace std;

struct OB {
    char name[2];
    int bu;
}seq[102];

int o[102], b[102];

int abs(int x)
{
    return x>0?x:-x;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t, n, io, ib, total, lefto, leftb, i;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d", &n);
        io = 1;ib = 1;
        total = 0;
        lefto= leftb = 0;
        for (i = 0; i < n; i++) {
            scanf("%s%d", seq[i].name, &seq[i].bu);
        }
        for (i = 0; i < n; i++) {
            if (seq[i].name[0] == 'O') {
                if (abs(seq[i].bu - io) <= lefto) {
                    total += 1;
                    leftb += 1;
                    lefto = 0;
                    io = seq[i].bu;
                } else {
                    total += abs(seq[i].bu-io)-lefto+1;
                    leftb += abs(seq[i].bu-io)-lefto+1;
                    lefto = 0;
                    io = seq[i].bu;
                }
            } else {
                if (abs(seq[i].bu - ib) <= leftb) {
                    total += 1;
                    lefto += 1;
                    leftb = 0;
                    ib = seq[i].bu;
                } else {
                    total += abs(seq[i].bu-ib)-leftb+1;
                    lefto += abs(seq[i].bu-ib)-leftb+1;
                    leftb = 0;
                    ib = seq[i].bu;
                }
            }
        }
        printf("Case #%d: %d\n", cas, total);
    }
    return 0;
}
