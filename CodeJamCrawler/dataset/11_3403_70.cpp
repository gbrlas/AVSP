#include <cstdio>
#include <deque>
#include <cctype>
#include <cstring>

using namespace std;

int flag[500000];
bool dFlag[500000];
void combine(char a, char b, char c) {
    int a1 = toupper(a) - 'A';
    int b1 = toupper(b) - 'A';
    int x1 = a1 + (b1 << 6);
    int x2 = b1 + (a1 << 6);
    flag[x1] = toupper(c)-'A';
    flag[x2] = toupper(c)-'A';
}

void dcombine(char a, char b) {
    int a1 = toupper(a) - 'A';
    int b1 = toupper(b) - 'A';
    int x1 = a1 + (b1 << 6);
    int x2 = b1 + (a1 << 6);
    dFlag[x1] = 1;
    dFlag[x2] = 1;
}

int TestCombine(int a, int b) {
    return flag[a + (b << 6)];
}

bool TestD(int a, const deque<int>& Q) {
    deque<int>::size_type sz = Q.size();
    unsigned int i;
    for (i = 0; i < sz; ++i) {
        if (dFlag[Q[i] + (a << 6)]) {
            return true;
        }
    }
    return false;
}


int main(void) {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int T, C, D, N;
    scanf ("%d", &T);
    char p[5];
    char s[200];
    for (int x = 1; x <= T; ++x) {
        scanf ("%d", &C);
        memset(flag, -1, 500000 * sizeof(int));
        for (int i = 0; i < C; ++i) {
            scanf ("%s", p);
            combine(p[0], p[1], p[2]);
        }
        scanf ("%d", &D);
        memset(dFlag, 0, 500000*sizeof(bool));
        for (int i = 0; i < D; ++i) {
            scanf ("%s", p);
            dcombine(p[0], p[1]);
        }
        scanf ("%d", &N);
        scanf ("%s", s);
        deque<int> Q;
        for (int i = 0; i < N; ++i) {
            int e = toupper(s[i])-'A';
            if (Q.empty()) {
                Q.push_back(e);
                continue;
            }
            int back = Q.back();
            int x = TestCombine(back, e);
            if (x != -1) {
                Q.pop_back();
                Q.push_back(x);
                continue;
            }
            if (TestD(e, Q)) {
                Q.clear();
                continue;
            } else {
                Q.push_back(e);
            }
        }
        printf ("Case #%d: [", x);
        unsigned int i;
        deque<int>::size_type sz = Q.size();
        if (sz > 0) {
            for (i = 0; i < sz-1; ++i) {
                printf ("%c, ", Q[i]+'A');
            }
            printf ("%c", Q[sz-1]+'A');
        }
        printf ("]\n");
    }

    return 0;
}
