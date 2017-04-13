#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits.h>
#include <ctype.h>
#include <math.h>

#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <complex>
#define ll long long
#define MAXN 100
using namespace std;

int abs(ll a){ return a>=0? a: -1*(a);}
int maior(ll a,ll b){ return a>b? a: b;}
int menor(ll a,ll b){ return a<b? a: b;}

ll mdc(ll a,ll b){
    if(b==0)
        return a;
    return mdc(b,a%b);
}
ll n,P1,P2;
int M,N;
char mtz[100][100];

void exp(int x,int y){
    int c=0;
    int i,j;
    if(x<0 || x > N-1 || y<0 || y > M-1)
        return;
    for(i=x;i<=x+1 && i<N;i++){
        for(j=y;j<=y+1 && j<M;j++){
            if(mtz[i][j] == '#')
                c++;
        }
    }
    //printf("%d %d, %d\n",x,y,c);
    if(c==4){
        mtz[x][y]='/';
        mtz[x][y+1]='\\';
        mtz[x+1][y]='\\';
        mtz[x+1][y+1]='/';
        exp(x+2,y+2);
        exp(x+2,y);
    }


}

int main(int argc,char *argv[]){
    int T;
    int i,j;

    cin>>T;

    int k;

    for(k=1;k<=T;k++){
        scanf("%d %d",&N,&M);

        for(i=0;i<N;i++){
            scanf("%s",mtz[i]);

        }
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                if(mtz[i][j]=='#')
                    exp(i,j);
            }
        }
        bool b=true;
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                if(mtz[i][j]=='#'){
                    b=false;
                    break;
                }

        printf("Case #%d:\n",k);
        if(b){
            for(i=0;i<N;i++)
                printf("%s\n",mtz[i]);

        }
        else{
            printf("Impossible\n");
          /*  for(i=0;i<N;i++)
                printf("%s\n",mtz[i]);
                */
        }

    }
    return 0;

}
