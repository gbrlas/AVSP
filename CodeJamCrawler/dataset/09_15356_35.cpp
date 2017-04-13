#include <cstdio>
#include <algorithm>
using namespace std;

int l,n,t;
char a[30];
bool add;

int main(){
    scanf("%d", &l); gets(a);
    for (int k=1; k<=l; k++){
        n = -1;
        printf("Case #%d: ", k);
        gets(a);
        while (a[++n]);
        add = true;
        for (int i=0; i<n-1; i++) {
            if (a[i] < a[i+1]) add = false;
            }
        if (not add) {
                next_permutation(a, a + n);
                printf("%s\n", a);
        }
        else {
             t = n-1;
             int c = 0;
             while (a[t] == '0') {
                   c++;
                   t--;
             }
             printf("%c", a[t]);
             for (int i=0; i<=c; i++)
                 printf("0");
             for (int i=t-1; i>=0; i--)
                 printf("%c", a[i]);
             printf("\n");
        }
        }
    return 0;
}
