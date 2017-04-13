#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
double w1[MAXN];
double w2[MAXN];

int Solve1(int n){
    int is=0, ie=n-1, js=0, je=n-1;
    int ans = 0;
    while(is <= ie){
        if(w1[is] > w2[js]) is++, js++, ans++;
        else is++, je--;
    }
    return ans;
}
int Solve2(int n){
    int is=0, ie=n-1, js=0, je=n-1;
    int ans = 0;
    while(is <= ie){
        if(w1[is] > w2[js]) js++, ie--, ans++;
        else is++, js++;
    }
    return ans;
}

void ReadAndSolve(FILE *fin, FILE *fout){
    int T, N;
    fscanf(fin, "%d", &T);
    for(int ca=1; ca<=T; ca++){
        fscanf(fin, "%d", &N);
        for(int i=0; i<N; i++)
            fscanf(fin, "%lf", &w1[i]);
        sort(w1, w1+N);
        for(int i=0; i<N; i++)
            fscanf(fin, "%lf", &w2[i]);
        sort(w2, w2+N);
        fprintf(fout, "Case #%d: %d %d\n", ca, Solve1(N), Solve2(N));
    }
}

int main()
{
    FILE *fin = fopen("D.in", "r");
    FILE *fout = fopen("D.out", "w");
    ReadAndSolve(fin, fout);
    return 0;
}
