#include <cstdio>
#include <iostream>

char a[5010][16];
int s,m,n,d,l;
int main(){
    scanf("%d%d%d", &m, &n, &d);
    for (int i=0; i<n; i++) 
        scanf("%s", &a[i]);
    for (int k=1; k<=d; k++){
    char b[1000];
        s = n;
        scanf("%s", &b);
        for (int i=0; i<n; i++) {
            l = 0;
            for (int j=0; j<m; j++) {
                if (a[i][j] == b[l])  l++; 
                else if (b[l] == '(' ) {
                     bool check = false;
                     while (b[l]!= ')' ) {
                           l++;
                           if (b[l] == a[i][j])
                              check = true;
                     }
                     if (!check) {s--; break; }
                     l++; }
                else if ((b[l] != a[i][j]) && (b[l] != '(')) { s--; break; }
            }
        }
        printf("Case #%d: %d\n", k, s);
    }
}
