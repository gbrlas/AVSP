#include <stdio.h>
#include <strings.h>
#include <string.h>

hash(char c){
    switch(c){
    case 'a':	return 'y';
    case 'b':	return 'h';
    case 'c':	return 'e';
    case 'd':	return 's';
    case 'e':	return 'o';
    case 'f':	return 'c';
    case 'g':	return 'v';
    case 'h':	return 'x';
    case 'i':	return 'd';
    case 'j':	return 'u';
    case 'k':	return 'i';
    case 'l':	return 'g';
    case 'm':	return 'l';
    case 'n':	return 'b';
    case 'o':	return 'k';
    case 'p':	return 'r';
    case 'q':	return 'z';
    case 'r':	return 't';
    case 's':	return 'n';
    case 't':	return 'w';
    case 'u':	return 'j';
    case 'v':	return 'p';
    case 'w':	return 'f';
    case 'x':	return 'm';
    case 'y':	return 'a';
    case 'z':	return 'q';
    default:    return ' ';
    }
}

int main(void){
    int n, i;
    char c[101];
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        int j, t;
        char r[101];
        scanf(" %[^\n]", c);
        t=strlen(c);
        for(j=0;j<t;j++) r[j] = hash(c[j]);
        r[j] = 0;
        printf("Case #%d: %s\n",i, r);
    }
}
