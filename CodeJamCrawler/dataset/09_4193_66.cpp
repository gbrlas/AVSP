#include <iostream>
#include <stdio.h>

int n, h,w;
int in[100][100];

char recurse(int x, int y, char out[100][100]) {

    if(out[x][y] >= 'a' && out[x][y] <= 'z')
        return out[x][y];

    int sx = x, sy = y;

    if( x>0 && in[x-1][y] < in[sx][sy]) {
        sx = x-1;
        sy = y;
    } 
    if( y>0 && in[x][y-1] < in[sx][sy]) {
        sx = x;
        sy = y-1;
    } 
    if( y+1<w && in[x][y+1] < in[sx][sy]) {
        sx = x;
        sy = y+1;
    } 
    if( x+1<h && in[x+1][y] < in[sx][sy]) {
        sx = x+1;
        sy = y;
    } 

    out[x][y] = recurse(sx, sy, out);

    return out[x][y];
}

int main() {

    scanf(" %d", &n);

    for(int i=0; i<n; i++) {

        scanf(" %d %d", &h, &w);

        for(int j=0; j<h; j++) {
            for(int k=0; k<w; k++) {
                scanf(" %d", &in[j][k]);
            }
        }

        char out[100][100] = {0} , curSink = 'a';

        for(int j=0; j<h; j++) {
            for(int k=0; k<w; k++) {
                if(     ( k+1>=w || in[j][k] <= in[j][k+1]) &&
                        ( k<1 || in[j][k] <= in[j][k-1]) &&
                        ( j<1 || in[j][k] <= in[j-1][k]) &&
                        ( j+1>=h || in[j][k] <= in[j+1][k])) {

                    out[j][k] = curSink;
                    curSink += 1;
                }

            }
        }

        for(int j=0; j<h; j++) {
            for(int k=0; k<w; k++) {
                if(out[j][k] == 0) {
                    out[j][k] = recurse(j, k, out);
                }
            }
        }

        // map here
        char vals[30] = {0};
        int ind=0;
        for(int j=0; j<h; j++) {
            for(int k=0; k<w; k++) {
                if(vals[out[j][k]-'a'] == 0) {
                    vals[out[j][k]-'a'] = 'a'+ind;
                    ind++;
                }
            }
        }

        for(int j=0; j<h; j++) {
            for(int k=0; k<w; k++) {
                out[j][k] = vals[out[j][k]-'a'];
            }
        }


        printf("Case #%d:\n", i+1);

        for(int j=0; j<h; j++) {
            printf("%c", out[j][0]);
            for(int k=1; k<w; k++) {
                printf(" %c", out[j][k]);
            }
            printf("\n");
        }
    }
}
