#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int max1, k, q, t, s, m, n, l, a[10010];
bool b[101];

int main(){
    scanf("%d\n", &l);
    for (int h=1; h<=l; h++) {
        max1 = 2147483647;
        k = 1;
        printf("Case #%d: ", h);
        scanf("%d%d", &m, &n);
        q = 1;
        for (int i=1; i<=n; i++)
            q = q * i;
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            a[i] = a[i] -1;
        }
        do {
            s = 0;
            for (int i=0; i<102; i++)
                b[i] = true;
            for (int j=0; j<n; j++)
            {
                b[a[j]] =false;
                for (int i=a[j]-1; i>=0; i--)
                    if (b[i]) s++; else break;
                for (int i=a[j]+1; i<m; i++)
                    if (b[i]) s++; else break;
            }
            if (s<max1 ) max1 = s; 
            next_permutation (a ,a+n);
            k++;
        }
        while (k<=q);
        printf("%d\n", max1);
    }
    return 0;
}
