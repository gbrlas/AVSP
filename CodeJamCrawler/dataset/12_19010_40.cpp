#include "stdio.h"
#include "string.h"

int main( void )
{
    int i,j,nCase;
    char input[101];
    char map[26]={
        'y',    /*a*/
        'h',    /*b*/
        'e',    /*c*/
        's',    /*d*/
        'o',    /*e*/
        'c',    /*f*/
        'v',    /*g*/
        'x',    /*h*/
        'd',    /*i*/
        'u',    /*j*/
        'i',    /*k*/
        'g',    /*l*/
        'l',    /*m*/
        'b',    /*n*/
        'k',    /*o*/
        'r',    /*p*/
        'z',    /*q*/
        't',    /*r*/
        'n',    /*s*/
        'w',    /*t*/
        'j',    /*u*/
        'p',    /*v*/
        'f',    /*w*/
        'm',    /*x*/
        'a',    /*y*/
        'q'     /*z*/
        };
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    gets(input);
    sscanf(input, "%d", &nCase);
    j = 1;
    while(j <= nCase){
        printf("Case #%d: ",j);

        gets(input);
        i = 0;
        while(input[i]){
            printf("%c",input[i]== ' '? ' ':map[input[i]-97]);
            i++;
        }

        if(j<nCase)   printf("\n");
        j++;
    }
    return 1;
}
