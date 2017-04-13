#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <cstring>  //for C++
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <sstream>
//#include <string> for C

using namespace std;

int decreaseBlock(const void *elem1, const void *elem2){
    float pv1 = *((double*)elem1);
    float pv2 = *((double*)elem2);
    if(pv1<pv2){
        return 1;
    } else if (pv1==pv2){
        return 0;
    } else {
        return -1;
    }
}

int increaseBlock(const void *elem1, const void *elem2){
    float pv1 = *((double*)elem1);
    float pv2 = *((double*)elem2);
    if(pv1>pv2){
        return 1;
    } else if (pv1==pv2){
        return 0;
    } else {
        return -1;
    }
}

int T, N;


double B1[1000], B2[1000];

int War(double *B1, double *B2, int N){
    int count=0;
    qsort(B1, N, sizeof(double), increaseBlock);
    qsort(B2, N, sizeof(double), increaseBlock);
    
    int c1, c2;
    c1 = c2 = 0;
    while(c2!=N){
        if(B1[c1]<B2[c2]){
            c1++;
            c2++;
            count++;
        }
        else{
            c2++;
            if(B1[c1]<B2[c2] && c2!=N){
                c1++;
                c2++;
                count++;
            }
        }
    }
    
    return N-count;
}

int DWar(double *B1, double *B2, int N){
    int count=0;
    qsort(B1, N, sizeof(double), decreaseBlock);
    qsort(B2, N, sizeof(double), decreaseBlock);
    
    int c1, c2;
    c1 = c2 = 0;
    while(c2!=N){
        if(B1[c1]>B2[c2]){
            c1++;
            c2++;
            count++;
        }
        else{
            c2++;
            if(B1[c1]>B2[c2] && c2!=N){
                c1++;
                c2++;
                count++;
            }
        }
    }
    
    return count;
}

int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        for(int j=0; j<2; j++){
            for(int k=0; k<N; k++){
                if(j==0){
                    cin>>B1[k];
                }
                else{
                    cin>>B2[k];
                }
            }
        }
        
        printf("Case #%d: %d %d\n", i+1, DWar(B1, B2, N), War(B1, B2, N));
        
    }
}
