#include <iostream>
#include <map>
#include <string.h>

using namespace std;

int main( ) {
    int n, s, q;
    char S[110][110], Q[1010][110];
    int cnts[1000][100];

    scanf(" %d", &n);

    for(int i=1; i<=n; i++) {

        scanf(" %d", &s);
        getchar();
        for(int j=0; j<s; j++) {
            scanf("%[^\n]", S[j]);
            getchar();
        }
        /*
        for(int j=0; j<s; j++) {
            printf("%s\n", S[j]);
        }
        printf("DONE\n");
        */
        scanf(" %d", &q);
        getchar();
        for(int j=0; j<q; j++) {
            scanf("%[^\n]", Q[j]);
            if(j+1 != q)
                getchar();
        }
        /*
        for(int j=0; j<q; j++) {
            printf("%s\n", Q[j]);
        }
        printf("DONE\n");
        */

        for(int j=1; j<=q; j++) {
            int match=-1;
            for(int k=0; k<s; k++) {
                if(strcmp(S[k], Q[j-1]) == 0) {
                 //   printf("%s match %d %d\n", S[k], j, k);
                    match = k;
                    break;
                }
            }
            if(match >= 0) {
                int count = cnts[j-1][match]+1;
                cnts[j][match] = cnts[j-1][match]+2;

                for(int k=0; k<s; k++) {
                    if(k != match)
                        cnts[j][k] = cnts[j-1][k];
                //printf("%d - %d : count %d\n", cnts[j][k], cnts[j-1][k], count);
                    if(k != match && cnts[j][k] > count) {
                        cnts[j][k] = count;
                    }
                }
            } else {
                for(int k=0; k<s; k++)
                        cnts[j][k] = cnts[j-1][k];
            }
        }


        int min = q;

        for(int j=0; j<s; j++) {
            if( min > cnts[q][j])
                min = cnts[q][j];
        }

        printf("Case #%d: %d\n", i, min);

        for(int j=0; j<=q; j++) {
            for(int k=0; k<=s; k++) {
                //printf("%d ", cnts[j][k]);
                cnts[j][k] = 0;
            }
            //printf("\n");
        }
    }
}
