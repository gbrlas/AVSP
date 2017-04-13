#include <cstdio>
#include <cstdlib>

main() {
 //  freopen ("input.txt", "r" , stdin);
 //  freopen ("output.txt", "w" , stdout);

   int t;
   scanf ("%d", &t);
   for ( int j = 1; j <=t; j++){
      int n, s, p;
      scanf ("%d %d %d", &n, &s, &p);
      int a;
      int ans = 0;
      for ( int i = 1; i <=n; i++) {
          scanf ("%d" , &a);
          if ( a >= 3 *p -2 )
             ans ++;
          else if (( 3*p - 4 ) >0 && ( a >= 3 *p -4) ){
             if ( s > 0 ) ans ++;
             s--;
          }
      }
      printf ("Case #%d: %d\n", j, ans);
   }
}
