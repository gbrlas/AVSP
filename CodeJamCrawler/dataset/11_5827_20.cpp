#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<time.h>
using namespace std;
int main () {
    long long a [] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int t;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; ++cases) {
               long long n,pd,pg;
               scanf("%lld %lld %lld",&n,&pd,&pg);
               if ((pg == 100 && pd != 100) || (!pg && pd)) {
                    printf("Case #%d: Broken\n",cases);
                    continue;
                } 
                if (pg > 100 || pd > 100) {
                    printf("Case #%d: Broken\n",cases);
                    continue;
                } 
                int aux = 100;
                    for (int i = 0; i < 25; ++i) {
                        if (!(aux%a[i]) && !(pd%a[i])) {
                            aux /= a[i];
                            pd /= a[i];
                            --i;   
                        }   
                    }                      
                if (aux > n) {
                    printf("Case #%d: Broken\n",cases);
                    continue;   
                }
                printf("Case #%d: Possible\n",cases);
    }
    return 0;
}
