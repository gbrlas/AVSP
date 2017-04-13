#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int n;

int main() {

    scanf(" %d", &n);

    for(int c=0; c<n; c++) {
        int bases[100], curbase = 1, len;
        char chars[100];

        scanf(" %s", chars);

        len = strlen(chars);

        bases[0] = 1;

        for(int i=1; i<len; i++) {

            int found=-1;

            for(int j=0; j<i; j++) {
                if(chars[i] == chars[j]) {
                    found = j;
                }
            }

            if(found >= 0) {
                bases[i] = bases[found];
            } else {
                curbase++;
                if(curbase == 2) {
                    bases[i] = 0;
                } else {
                    bases[i] = curbase-1;
                }
            }
        }

        if(curbase < 2)
            curbase = 2;

        long long int val = 0, mult = 1;

        for(int i=len-1; i>=0; i--) {
            val += bases[i]*mult;
            mult *= curbase;

           // printf("%d %lld (%d)\n", bases[i], val, i);
        }

        printf("Case #%d: %lld\n", c+1, val);
    }
}
