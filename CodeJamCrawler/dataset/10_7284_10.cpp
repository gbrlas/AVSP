#include <iostream>
#include <iomanip>
#include <list>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#define MAXN 100000000
using namespace std;



int main(){
    int T;
    int k;
    int N;
    int R;
  queue<int> fila;
    int i,j;
    int w;
    int euro;

    scanf("%d",&T);

    for(i=0;i<T;i++){
        scanf("%d%d%d",&R,&k,&N);
        while(fila.empty()==false)
            fila.pop();
        for(j=0;j<N;j++){
            int v;
            scanf("%d",&v);
           // printf("\n%d\n",v);
            fila.push(v);
        }
        euro=0;
        for(j=0;j<R;j++){
            int size=0;
            int top=fila.front();
            if(top>k)
                continue;
            for(w=0;w<N && size<k;w++){
                top=fila.front();
                if(top<=(k-size)){
                    size+=top;
                    fila.pop();
                    fila.push(top);
                }
             //   printf("\n%d",size);
            }
            euro+=size;
        }
        printf("Case #%d: %d\n",i+1,euro);
    }
    return 0;
}


















