#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define eps 1e-10
#define inf 0x3f3f3f3f

#define fr(x,y,z) for(int x = (y); x < (z); x++)

#define console cout
#define dbg(x) console << #x << " == " << x << endl
#define print(x) console << x << endl

int T,R,K,N;
long long g[1001];
long long sum[1001];

long long soma(int ini, int fim){
    if(ini == fim) return sum[N-1];
    if(ini < fim) return sum[fim] - sum[ini] + g[ini];
    else{
        return sum[N-1] - sum[ini] + g[ini] + sum[fim];
    }
}

int bb(int ind){
    int ini = 0, fim = N - 1, meio;
    
    while(fim - ini > 1){
        meio = (fim+ini)/2;
        if(soma(ind,(ind+meio)%N) <= K) ini = meio;
        else fim = meio;
    }
    
    if(soma(ind,(ind+fim)%N) <= K) return (ind+fim)%N;
    else return (ind+ini)%N;
}

int main(){
    long long fat,ind_atual,last_group;
    
    freopen("C-small-attempt0.in","r",stdin);
    freopen("saida.txt","w",stdout);
    
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        
        scanf("%d %d %d",&R,&K,&N);
        fat = 0;
        
        for(int j = 0; j < N; j++){
            scanf("%d",&g[j]);
            if(j > 0) sum[j] = sum[j-1] + g[j]; 
            else sum[j] = g[j];
        }
        ind_atual = 0;
        for(int r = 0; r < R; r++){
            //printf("NEW INDICE %d\n",ind_atual);
            last_group = bb(ind_atual);
            //printf("FIM %d\n",last_group);
            //printf("SOMA %d\n",soma(ind_atual,last_group));
            
            if(ind_atual == last_group){
                
                if(sum[N-1] <= K) fat += sum[N-1];
                else if(g[ind_atual] <= K){
                    fat += g[ind_atual];
                    ind_atual = (ind_atual + 1)%N;
                }
            }
            else{
               fat += soma(ind_atual,last_group);
               ind_atual = (last_group + 1)%N;    
            }
            
        }
        
        printf("Case #%d: %lld\n",i+1,fat);
        
    }
    
    return 0;
}
