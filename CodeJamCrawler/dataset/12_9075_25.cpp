#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

string a="yhesocvxduiglbkrztnwjpfmaq";

char s[2005];

int main()
{
    int T;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    getchar();
    for(int ca=1;ca<=T;ca++)
    {       
       gets(s);
       printf("Case #%d: ",ca);
       int l=strlen(s);
       for(int i=0;i<l;i++)
         if(s[i]==' ') printf(" ");
         else printf("%c",a[s[i]-'a']);
       printf("\n");
    }
}
