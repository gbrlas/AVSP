#include <math.h>
#include <stdio.h>


    int t, n, val;

    int store[50][50];
    int red[50][50][4];
    int blue[50][50][4];

    char input[100];

    void reset() {

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                store[i][j] = 0;

                red[i][j][0] = 0;
                red[i][j][1] = 0;
                red[i][j][2] = 0;
                red[i][j][3] = 0;

                blue[i][j][0] = 0;
                blue[i][j][1] = 0;
                blue[i][j][2] = 0;
                blue[i][j][3] = 0;
            }
        }
    }

void print() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d", store[i][j]);
        }
        puts("");
    }
}

void populate(int ind) {

    int max = n, cur = n-1;

    while(max>0) {
        if(input[max-1] != '.') {
            if(input[max-1] == 'B') {
                store[cur][ind] = 1;
                cur--;
            }
            else if(input[max-1] == 'R') {
                store[cur][ind] = 2;
                cur--;
            }
        }
        max--;
    }
}

main () {
    

     scanf(" %d", &t);

    for(int i=0; i<t; i++) {

        int redMax = 0, blueMax = 0;

        scanf(" %d %d", &n, &val);

        reset();


        for(int j=0; j<n; j++) {
            scanf(" %s", input);

            populate(n-j-1);
        }
        //print();

    for(int k=n-1; k>=0; k--) {

        for(int j=0; j<n; j++) {

            if(store[k][j] == 1) {

                blue[k][j][0] = 1;
                blue[k][j][1] = 1;
                blue[k][j][2] = 1;
                blue[k][j][3] = 1;


                if(blueMax < 1)
                    blueMax = 1;

                if(j-1 >= 0) {
                    blue[k][j][0] = blue[k][j-1][0]+1;
                    if(blueMax < blue[k][j][0])
                        blueMax = blue[k][j][0];
                }

                if(j-1 >= 0 && k+1 < n) {
                    blue[k][j][1] = blue[k+1][j-1][1]+1;
                    if(blueMax < blue[k][j][1])
                        blueMax = blue[k][j][1];
                }

                if(k+1 < n) {
                    blue[k][j][2] = blue[k+1][j][2]+1;
                    if(blueMax < blue[k][j][2])
                        blueMax = blue[k][j][2];
                }

                if(k+1 < n && j+1 < n) {
                    blue[k][j][3] = blue[k+1][j+1][3]+1;
                    if(blueMax < blue[k][j][3])
                        blueMax = blue[k][j][3];
                }
            }

            if(store[k][j] == 2) {
                red[k][j][0] = 1;
                red[k][j][1] = 1;
                red[k][j][2] = 1;
                red[k][j][3] = 1;

                if(redMax < 1)
                    redMax = 1;

                if(j-1 >= 0) {
                    red[k][j][0] = red[k][j-1][0]+1;
                    if(redMax < red[k][j][0])
                        redMax = red[k][j][0];
                }

                if(j-1 >= 0 && k+1 < n) {
                    red[k][j][1] = red[k+1][j-1][1]+1;
                    if(redMax < red[k][j][1])
                        redMax = red[k][j][1];
                }

                if(k+1 < n) {
                    red[k][j][2] = red[k+1][j][2]+1;
                   // printf("k %d j %d, red %d : %d down\n", k, j, red[k][j][2], red[k+1][j][2]);
                    if(redMax < red[k][j][2])
                        redMax = red[k][j][2];
                }

                if(k+1 < n && j+1 < n) {
                    red[k][j][3] = red[k+1][j+1][3]+1;
                    if(redMax < red[k][j][3])
                        redMax = red[k][j][3];
                }
            }
        }
    }

    //printf("blue %d red %d\n", blueMax, redMax);

        if(blueMax >= val && redMax >= val) {
            printf("Case #%d: Both\n", i+1);
        }

        else if(blueMax >= val && redMax < val) {
            printf("Case #%d: Blue\n", i+1);
        }

        else if(blueMax < val && redMax >= val) {
            printf("Case #%d: Red\n", i+1);
        } else {
            printf("Case #%d: Neither\n", i+1);
        }

  }
}
