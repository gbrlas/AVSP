#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <iostream>
using namespace std;

#define PI 3.141592653589793
#define INF 2123456789
#define NUL 0.0000001

#define SZ ize()
#define CS c_str()
#define PB push_back
#define INS insert
#define EMP empty()
#define CLR clear()
#define LEN length()
#define ull unsigned long long

int main(){
    FILE *fin = fopen("B-large.in", "r");
    FILE *fout = fopen("B-large.out", "w");

int T; fscanf(fin, "%d", &T);
for (int t = 1; t <= T; t++){
    int n, s, p; fscanf(fin, "%d%d%d", &n, &s, &p);

    int a[105];
    for (int i = 1; i <= n; i++) fscanf(fin, "%d", &a[i]);

    int sol = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] < 2){
            if (a[i] >= p) sol++;
        }
        else if (a[i] > 28){
            sol++;
        }
        else if (a[i] % 3 == 0){
            if (a[i] / 3 >= p) sol++;
            else if (a[i] / 3 == p-1 && s){
                sol++; s--;
            }
        }
        else if (a[i] % 3 == 1){
            if (a[i] / 3 + 1 >= p) sol++;
        }
        else if (a[i] % 3 == 2){
            if (a[i] / 3 + 1 >= p) sol++;
            else if (a[i] / 3 + 1 == p-1 && s){
                sol++; s--;
            }
        }

    fprintf(fout, "Case #%d: %d\n", t, sol);
}

    fclose(fin); fclose(fout);
    return 0;
}
