#include <cstdio>
#include <cstdlib>
#include <cmath>

int recyled(int n, int b){
    int dummy = n;
    int digits = log10(n);
    int p = pow (10, digits);
    int ans = 0;
    int newnumber = 0;
    while (1) {
       if ( dummy %10 == 0) {
            int c = 100;
            while (dummy % c == 0)
               c = c * 10;
            newnumber = (dummy % c) * (p * 10 /c) + dummy / c;
            if ( (newnumber > n) && (newnumber <= b)) ans ++;
            if ( newnumber == n) return ans;
            dummy = newnumber;
       }
       else {
           newnumber = (dummy%10) * p + dummy/10;
           if ( (newnumber > n) && (newnumber <= b)) ans ++;
           if ( newnumber == n) return ans;
           dummy = newnumber;
       }
    }
}

main () {
  //  freopen ("input.txt", "r", stdin);
  //  freopen ("output.txt", "w", stdout);


    int t;
    scanf ("%d", &t);
    for ( int i = 1; i <= t; i++){
        int a, b;
        scanf ("%d %d", &a, &b);
        int ans = 0;
        for ( int j = a; j <= b; j++){
            ans += recyled(j,b);
        }
        printf ("Case #%d: %d\n", i, ans);
    }
}
