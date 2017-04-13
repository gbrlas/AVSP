#include <iostream>
#include <stdio.h>

int n;
char str[1000];
char subs[] = "welcome to code jam";

int main() {

    scanf(" %d", &n);

    getchar();

    for(int i=0; i<n; i++) {

        int sum=0, len=0;
        char c;

        while((c=getchar()) != '\n') {
            str[len] = c;
            len++;
        }

        int arr[501][20] = {0};

        for(int j=len-1; j>=0; j--) {

            for(int k=0; k<19; k++) {

                arr[j][k] = arr[j+1][k];

                //printf("%c %c: jk %d %d ", str[j], subs[18-k], j, k);
                if(str[j] == subs[18-k]) {

                    if(k>0) {

                        arr[j][k] += arr[j+1][k-1];

                    } else {

                        arr[j][k] += 1;
                    }

                    arr[j][k] %= 10000;
                }
                //printf(" : %d\n", arr[j][k]);
            }
        }


        printf("Case #%d: %d%d%d%d\n", i+1, arr[0][18]/1000, (arr[0][18]%1000)/100, (arr[0][18]%100)/10, arr[0][18]%10);

    }

}
