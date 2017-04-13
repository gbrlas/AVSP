#include <cstdio>
#include <cstdlib>

main(){

  // freopen ("input.txt", "r", stdin);
 //  freopen ("output.txt", "w", stdout);

   int t;
   scanf ("%d", &t);
   for ( int i = 1; i <= t; i++ ){
      int a, b;
      scanf ("%d %d", &a, &b);

      float p[a + 1];
      p[0] = 0.0;

      scanf ("%f", &p[1]);
      float x;
      for ( int j = 1; j < a; j++){
        scanf ("%f", &x);
        p[j+1] = p[j] * x;
      }

      double expected[a+2];
      for ( int j = 0; j <= a; j++) {
         int key = j + j +  b - a + 1;
         expected[j] = p[a-j] * key + (1 - p[a-j]) * ( key + b + 1);
      }
      expected[a+1] = b + 2;

      double min = expected[0];
      for ( int i = 1; i <= (a+1); i++)
         if ( expected[i] < min)
             min = expected[i];
      printf ("Case #%d: %.6f\n", i, min);
   }
}
