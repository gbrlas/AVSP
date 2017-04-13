#include <math.h>
#include<string.h>
#include <stdio.h>

int counter;

int check(char max[20000][101], int cur, char temp[1000]) {

    char newTemp[1000];

    for(int i=0; i<cur; i++) {
        //printf("%s max %d : temp %s\n", max[i], i+1, temp);
        if(strcmp(max[i], temp) == 0) {
            return cur;
        }
    }

    int len = strlen(temp);
    strcpy(newTemp, temp);

    for(int i=len-1; i >= 0; i--) {
        if(newTemp[i] == '/') {
            if( i != 0)
                newTemp[i] = '\0';
            else
                newTemp[i+1] = '\0';
            break;
        }
    }

    cur = check(max, cur, newTemp);

    strcpy(max[cur], temp);
    counter++;

    return cur+1;
       
}

main () {
    
    int t, n, m;

    scanf(" %d", &t);

    for(int j=0; j<t; j++) {

        counter = 0;
        scanf(" %d %d", &n, &m);

        char max[20000][101], temp[1000];;
        int cur = 1;

        strcpy(max[0], "/");

        for(int i=0; i<n; i++) {
            scanf(" %s", temp);
            strcpy(max[cur], temp);
            cur++;
        }

        for(int i=0; i<m; i++) {

            scanf(" %s", temp);
            cur = check(max, cur, temp);

        }


        printf("Case #%d: %d\n", j+1, counter);
    }
}
