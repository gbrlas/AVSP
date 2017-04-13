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
#define MAXN 110
using namespace std;

int abs(ll a){ return a>=0? a: -1*(a);}
int maior(ll a,ll b){ return a>b? a: b;}
int menor(ll a,ll b){ return a<b? a: b;}
  int N;
  double WP[MAXN];
    double OWP[MAXN];
    double OOWP[MAXN];
    double R[MAXN];
    double J[MAXN];
    double V[MAXN];
    char M[MAXN][MAXN];
void calcWP(int i){
    double jo=0;
    double v=0;
    J[i]=V[i]=0;
    for(int j=0;j<N;j++){
        if(M[i][j]=='1'){
            v+=1;
            jo+=1;
            V[i]+=1;
            J[i]+=1;
        }
        else if(M[i][j]=='0'){
            jo+=1;
            J[i]+=1;
        }
    }
   // printf("wP %d %lf %lf\n",i,v,jo);
    WP[i]=v/jo;

}

void calcOWP(int i){
    double jo=0;
    double s=0;
    for(int j=0;j<N;j++){
        if(M[i][j]!='.'){
            jo+=1;
            if(M[i][j]=='0'){
                s+=(V[j]-1)/(J[j]-1);
            }
            else{
                s+=(V[j])/(J[j]-1);
            }
        }
    }
  //  printf("OOP %d %lf %lf\n",i,s,jo);
    OWP[i]=s/jo;


}
void calcOOWP(int i){
    double jo=0;
    double s=0;
    for(int j=0;j<N;j++){
        if(M[i][j]!='.'){
            jo+=1;
            s+=OWP[j];
        }
    }
    OOWP[i]=s/jo;

}

int main(int argc,char *argv[]){


    int i,j,k;
    int T;

    scanf("%d",&T);

    for(k=0;k<T;k++){
        scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%s",M[i]);
        }
        for(i=0;i<N;i++){
        calcWP(i);
            //printf("WP %d %lf\n",i,WP[i]);
        }
        for(i=0;i<N;i++){
            calcOWP(i);
          //  printf("OWP %d %lf\n",i,OWP[i]);
        }
        for(i=0;i<N;i++){
            calcOOWP(i);
        //    printf("OOWP %d %lf\n",i,OOWP[i]);
        }
        printf("Case #%d:\n",k+1);
        for(i=0;i<N;i++){
            R[i]=WP[i]/4.0 + OWP[i]/2.0 + OOWP[i]/4.0;
             printf("%lf\n",R[i]);
        }


    }



    return 0;
}
