#include <stdio.h>
#include <memory.h>
#include <string.h>
#define MAXCHARS 256
#define UCHAR unsigned char

using namespace std;


static UCHAR map[MAXCHARS+1];

void init() {
    int i, j, len;
    memset(map, 0, 128);
    //
    char *a[3], *b[3];
    a[0] = (char*)"ejp mysljylc kd kxveddknmc re jsicpdrysiqz";
    b[0] = (char*)"our language is impossible to understandzq";
    a[1] = (char*)"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    b[1] = (char*)"there are twenty six factorial possibilities";
    a[2] = (char*)"de kr kd eoya kw aej tysr re ujdr lkgc jv";
    b[2] = (char*)"so it is okay if you want to just give up";
    //
    for(i = 0; i != 3; i++) {
        len = strlen(a[i]);
        for(j = 0; j != len; j++)
            map[ (int)a[i][j] ] = b[i][j];
    }
    for(i = 1, j = MAXCHARS+1; i != j; i++)
        if(map[i]==0) map[i] = (char)i;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t = 1, i, len;
    char input[101];
    init();
    // for(i = 0; i != MAXCHARS; i++) printf("%c=%c\n", i, map[i]);

    scanf("%d", &T); getchar();
    while (T--) {
        gets(input); len = strlen(input);
        for(i = 0; i != len; i++)
            input[i] = map[ (int)input[i] ];
        printf("Case #%d: %s\n", t++, input);
    }

    fclose(stdout);

    return 0;
}
