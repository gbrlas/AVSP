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
    for(int ca=1; ca<=T; ca++){
        fscanf(fin, "%lf%lf%lf", &C, &F, &X);
        double t = 0;
        for(int i=0; ;i++){
            if(  X/(2+i*F) < C/(2+i*F) + X/(2+(i+1)*F) ){
                t += X/(2+i*F); break;
            }
            t += C/(2+i*F);
        }
        fprintf(fout, "Case #%d: %.7f\n", ca, t);
    }
}

int main(){
    FILE* fin = fopen("B.in", "r");
    FILE* fout = fopen("B.out", "w");
    ReadAndSolve(fin, fout);
    return 0;
}
