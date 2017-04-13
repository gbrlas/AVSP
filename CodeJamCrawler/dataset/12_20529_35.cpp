#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;
char str[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char s[500];
int main()
{
    int t,k,tc,i,j;

    freopen("A-small-attempt17.in","r",stdin);
    freopen("A-small-attempt17.out","w",stdout);

    scanf("%d",&t);
    tc=0;
    gets(s);
    while(tc<t)
    {
        tc++;
        gets(s);
        k=strlen(s);

        for(i=0;i<k;i++)
        {
            if(s[i]==' ')
                continue;
            j=s[i]-'a';
            s[i]=str[j];
        }

        printf("Case #%d: %s\n",tc,s);
    }
    return 0;
}
