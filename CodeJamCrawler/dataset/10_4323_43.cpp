#include <stdio.h>

using namespace std;

main () {
    int t;

    scanf(" %d", &t);

    for(int i=0; i<t; i++) {
        int r, k, n, vals[2000], sum[2000], jump[2000];
        scanf(" %d %d %d", &r, &k, &n);

        for(int j=0; j<n; j++) {
            scanf(" %d", &vals[j]);
        }

        int tempSum, tempInd;
        for(int j=0; j<n; j++) {
            tempInd = j;
            tempSum = vals[tempInd++];

            tempInd = tempInd%n;

            while(1) {

                if( tempInd != j && tempSum + vals[tempInd] <= k) {
                    tempSum += vals[tempInd++];
                    tempInd = tempInd%n;
                } else {
                    break;
                }
            }
            sum[j] = tempSum;
            jump[j] = tempInd;
        }

        long int revenue = 0;
        int curStart = 0;
        for(int j=0; j<r; j++) {
            revenue += sum[curStart];
            //printf("%d : %d old, %d new, %d this, %d jump\n", j, revenue-sum[curStart], revenue, sum[curStart], jump[curStart]);
            curStart = jump[curStart];
        }

        printf("Case #%d: %d\n",i+1, revenue);
    }

}
