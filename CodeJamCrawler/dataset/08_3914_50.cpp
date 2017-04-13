#include <iostream>
#include <set>
#include <stdlib.h>

using namespace std;

static int comp(const void *a, const void *b) {

    int *a1, *b1; 
    a1 = (int *) a;
    b1 = (int *) b;
    return (*a1)-(*b1);
}

main() {
    int n, n1, n2, t;

    int N1[110], N2[110];
    int out1[110], out2[110], in1[110], in2[110];
    int o1, o2, i1, i2;

    char input[4][110][2];

    scanf(" %d", &n);
    for(int i=0; i<n; i++) {

        scanf(" %d", &t);

        scanf(" %d %d", &n1, &n2);

        o1 = o2 = i1 = i2 = 0;
        for(int j=0; j<n1; j++) {
            scanf(" %d:%d %d:%d", &input[0][j][0], &input[0][j][1], &input[1][j][0],
                    &input[1][j][1]);
            out1[o1++] = (60*input[0][j][0]+input[0][j][1]);
            in2[i2++] = (60*input[1][j][0]+input[1][j][1]+t);
            //printf(" %d:%d %d:%d\n", input[0][j][0], input[0][j][1], input[1][j][0],
             //       input[1][j][1]);
        }

        for(int j=0; j<n2; j++) {
            scanf(" %d:%d %d:%d", &input[2][j][0], &input[2][j][1], &input[3][j][0],
                    &input[3][j][1]);
            out2[o2++] = (60*input[2][j][0]+input[2][j][1]);
            in1[i1++] = (60*input[3][j][0]+input[3][j][1]+t);
        }

        qsort(out1, o1, sizeof(int), comp);
        qsort(out2, o2, sizeof(int), comp);
        qsort(in1, i1, sizeof(int), comp);
        qsort(in2, i2, sizeof(int), comp);

        int counter=0;

        for(int k=0, j=0; k<o1; k++) {
            if( j >= i1) {
                counter++;
            } else if(out1[k] >= in1[j]) {
                j++;
            } else if( out1[k] < in1[j]) {
                counter++;
            }
        }

        printf("Case #%d: %d ", i+1, counter);

        counter = 0;
        for(int k=0, j=0; k<o2; k++) {
            if( j >= i2) {
                counter++;
            } else if(out2[k] >= in2[j]) {
                j++;
            } else if( out2[k] < in2[j]) {
                counter++;
            }
        }
        printf("%d\n", counter);

    }
}
