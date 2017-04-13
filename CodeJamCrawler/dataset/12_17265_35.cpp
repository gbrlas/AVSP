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

#define SZ size()
#define CS c_str()
#define PB push_back
#define INS insert
#define EMP empty()
#define CLR clear()
#define LEN length()
#define ull unsigned long long

string a[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string b[] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};

int main(){
    FILE *fin = fopen("A-small-attempt0.in", "r");
    FILE *fout = fopen("A-small-attempt0.out", "w");

    map <char, char> m; m.CLR;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < a[i].LEN; j++) m[ a[i][j] ] = b[i][j];
    m['q'] = 'z'; m['z'] = 'q';

    //for (char i = 'a'; i <= 'z'; i++) printf("%c -> %c\n", i, m[i]);
    int n; fscanf(fin, "%d\n", &n);
    for (int i = 1; i <= n; i++){
        char s[105]; fgets(s, 1000, fin);
        for (int j = 0; j < strlen(s); j++) s[j] = m[ s[j] ];

        fprintf(fout, "Case #%d: %s\n", i, s);
    }

    fclose(fin); fclose(fout);
    return 0;
}
