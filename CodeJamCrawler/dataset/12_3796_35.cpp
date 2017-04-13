# include <stdio.h>

char map[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main(void)
{
    //var 
    int t, n, a, b;
    int temp,temp1,temp2;

    //loop
    int i,j,k,l;

    //string
    char temparr[102];


    scanf("%d ",&t);

    for(i=0;i<t;i++)
    {
        fgets(temparr,102,stdin);

        // Solve
        for(j=0;j<102;j++)
        {
            if ((temparr[j] <= 'z') && (temparr[j] >= 'a'))
                temparr[j] = map[temparr[j] - 'a'];
            else if ((temparr[j] <= 'Z') && (temparr[j] >= 'A'))
                temparr[j] = map[temparr[j] - 'A'] - 'a' + 'A';
        }

        // output print
        printf("Case #%d: ",i+1);
        printf("%s",temparr); 
     }

    return 1;
}

