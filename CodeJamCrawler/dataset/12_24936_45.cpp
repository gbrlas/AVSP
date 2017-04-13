#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long i64;

int v[20];
int p10[20];

int val(int nd){
    int d = 0;
    for(int i = 0; i < nd; i++)
        d = d*10 + v[i];
    return d;
}
int count(int n, int B){
    
    int nd = 0;
    int n2 = n;
    while(n2){
        v[nd++] = n2 % 10;
        n2 /= 10;
    }
    for(int i = 0; i < nd/2; i++)
        swap(v[i], v[nd - 1 - i]);
    int cnt = 0;
    n2 = n;
    for(int i = 0; i < nd; i++){
        n2 = (n2 - p10[nd-1]*v[i])*10 + v[i];
        if(n2 > n && n2 <= B) cnt++;
    }
    return cnt;
}

int main (){

    p10[0] = 1;
    for(int i = 1; i<10; i++)
        p10[i] = p10[i-1]*10;

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int cnt = 0;
        int A, B;
        cin >> A >> B;
        for(int i = A; i <= B; i++)
            cnt += count(i, B);
        printf("Case #%d: %d\n", t+1, cnt);
    }

    return 0;
}
