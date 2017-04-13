#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXL 20
#define MAXD 5005
using namespace std;
#define REP(i,n) for(int i =0;i<n;i++)
#define FOREACH(it,c) for(__typeof(c.begin())it=c.begin();it!=c.end();it++)

int L, D, N;
char dict[MAXD][MAXL];
vector<char> current[MAXL];

int main() {
    FILE *fin = fopen("alien.in", "r"), *fout = fopen("alien.out", "w");

    fscanf(fin, "%d %d %d", &L, &D, &N);
    REP(i, D)
        fscanf(fin, "%s", dict[i]);

    REP(i, N) {
        char word[1000]; fscanf(fin, "%s", word);
        int slot = 0;
        current[0] = vector<char>();
        for(int index = 0, open = 0; word[index]; index++) {
            if (word[index] == '(') open = 1;
            else if (word[index] == ')') {
                slot++;
                current[slot] = vector<char>();
                open = 0;
            }
            else {
                current[slot].push_back(word[index]);
                if (!open) {
                    slot++;
                    current[slot] = vector<char>();
                }
            }
        }

        int res = 0;
        REP(j, D) {
            bool ok = true;
            REP(c, L) {
                if (find(current[c].begin(), current[c].end(), dict[j][c]) 
                        == current[c].end())
                    ok = false;
            }
            if (ok) res++;
        }
        fprintf(fout, "Case #%d: %d\n", i+1, res);
    }
    return 0;
}
