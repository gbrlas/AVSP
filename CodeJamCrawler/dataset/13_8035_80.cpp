#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ull unsigned long long

int T;

bool isFair(char st[]);
void conv(ull bil, char st[]);

int main() {
    //freopen("C.txt","r",stdin);
    //freopen("C.out","w",stdout);
    
    scanf("%d",&T);
    for (int t = 0; t < T; t++) {
        ull A, B;
        scanf("%llu %llu",&A,&B);
        char st[20];
        int ans = 0;
        //*
        for (ull i = A; i <= B; i++) {
            conv(i, st);
            //printf("ST = %s\n",st);
            if ( isFair(st) ) {
                ull temp = (ull) sqrt(i);
                if (temp*temp == i) {
                    conv(temp,st);
                    //printf("Temp = %d\n", temp);
                    if (isFair(st)) ans++;
                }
            }
        }//*/
        printf("Case #%d: %d\n", t+1, ans);
    }
    return 0;
}

bool isFair (char st[]) {
    int len = strlen(st);
    for (int i = 0; i < len/2; i++)
        if (st[i] != st[len-i-1]) return false;
    return true;
}
void conv(ull bil, char st[]) {
    ull temp = bil;
    int round = 0;
    while(temp) {
        temp /= 10;
        round++;
    }
    temp = 1;
    for (int i = 0; i < round-1; i++)
        temp*=10;
    for (int i = 0; i < round; i++) {
        st[i] = bil/temp + '0';
        bil = bil%temp;
        temp /= 10;
    }
    st[round]='\0';
}
