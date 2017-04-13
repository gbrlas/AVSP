#include <stdio.h>
#include <stdlib.h>

int compare ( const void * a, const void *b) {
    return ( *((int*)b) - *((int*)a));
}


main () {

    int n, p, k, l;
    long long int v1[1100], sum;
    scanf(" %d", &n);
    for(int i=0; i<n; i++) {

      scanf(" %d %d %d", &p, &k , &l);

      if( p*k >= l) {

        for(int j=0; j<l; j++) {
            scanf(" %lld", &v1[j]);
         //  printf("%d ", v1[j]);
        }
        //puts("");

        qsort(v1, l, sizeof(long long int),  compare);

        for(int j=0; j<l; j++) {
            //printf("%d ", v1[j]);
        }
        //puts("");

        sum = 0;
        int o=0;
        for(int j=0; j<p; j++) {
            for(int m=0; m<k; m++) {
                sum += (long long int)v1[o]*((long long int)j+1);
               // printf(" %lld %lld %d %d %d\n", sum, v1[o], j+1, o, l);
                o++;
                if(o >= l)
                    break;
            }
                if(o >= l)
                    break;
  //          printf("%lld: %lld %lld\n", sum, v1[j], v2[n-1-j]);
        }
            printf("Case #%d: %lld\n", i+1, sum);
      }
      else {
        for(int j=0; j<l; j++) {
            scanf(" %d", &v1[j]);
        }
            printf("Case #%d: Impossible\n", i+1);
      }
    }
}
