#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("B-small-attempt0.in");
ofstream fout("water.out");

int deltay[]={-1, 0, 0, 1};
int deltax[]={0, -1, 1, 0};

int T,H,W;
int P[110][110];
int foter[10012];
char mark[10012];

int _find(int i){
    int a;
    if (foter[i]<0) return i;
    a = _find(foter[i]);
    foter[i] = a;
    return a;
}

void _union(int a, int b){
    a = _find(a);
    b = _find(b);
    if (a==b) return;

    if (foter[a]<foter[b]) {
        foter[a] = foter[a] + foter[b];
        foter[b] = a;
    } else {
        foter[b] = foter[b] + foter[a];
        foter[a] = b;
    }
}

int main(){
    fin>>T;
for( int q=0;q<T;q++){
    fin>>H>>W;

    for(int i=0;i<H*W+10;i++) {
        foter[i] = -1;
        mark[i] = '_';
    }

    for(int i=0;i<H+5;i++){
        for(int j=0;j<W+5;j++) P[i][j]=50000;
    }

    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++) fin>>P[i][j];
    }

    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            int mini=20000;
            for(int k=0;k<4;k++) mini= min(mini, P[i+deltay[k]][j+deltax[k]]);//fout<<"MIN: "<<mini<<endl;
            if (mini >= P[i][j]) continue;
            for(int k=0;k<4;k++) if(P[i+deltay[k]][j+deltax[k]] == mini){
                _union((i-1)*W+j, (i+deltay[k]-1)*W+j+deltax[k]);
                break;
            }

        }
    }
/*
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            fout<<P[i][j];
            if(j!=W) fout<<" ";
        }
        fout<<endl;
    }
*/

    fout<<"Case #"<<q+1<<":"<<endl;

    char mm = 'a';
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(mark[_find((i-1)*W+j)] == '_'){
                mark[_find((i-1)*W+j)] = mm;
                mm++;
            }

            fout<<mark[_find((i-1)*W+j)];
            //fout<<_find((i-1)*W+j);
            if(j!=W) fout<<" ";
        }
        fout<<endl;
    }
/*
    for(int i=1;i<=H*W;i++) {
        fout<<foter[i]<<" ";
    }fout<<endl;
*/
}
}
