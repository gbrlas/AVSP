#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>

using namespace std;


void ReadAndSolve(FILE* fin, FILE* fout){

    int T;
    double C, F, X;

    fscanf(fin, "%d", &T);
    int r, x;
    int a[4], b[4];
    for(int ca=1; ca<=T; ca++){
        fscanf(fin, "%d", &r);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                fscanf(fin, "%d", &x);
                if(r == i+1) a[j] = x;
            }
        }

        fscanf(fin, "%d", &r);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                fscanf(fin, "%d", &x);
                if(r == i+1) b[j] = x;
            }
        }

        int state = 0;
        int ans;
        sort(a, a+4);
        sort(b, b+4);
        int i=0, j=0;
        while(i<4 && j<4){
            if(a[i] == b[j]) {state++; ans = a[i]; i++, j++;}
            else if(a[i] < b[j]) i++;
            else j++;
        }
        fprintf(fout, "Case #%d: ", ca);
        if(state == 0) fprintf(fout, "Volunteer cheated!\n");
        else if(state == 1) fprintf(fout, "%d\n", ans);
        else fprintf(fout, "Bad magician!\n");
    }
}

int main(){
    FILE* fin = fopen("A.in", "r");
    FILE* fout = fopen("A.out", "w");
    ReadAndSolve(fin, fout);
    //ReadAndSolve(stdin, stdout);
    return 0;
}
