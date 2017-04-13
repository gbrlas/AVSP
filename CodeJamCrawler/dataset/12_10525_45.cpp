#include <cstdio>
#include <cstring>

char a[]="yhesocvxduiglbkrztnwjpfmaq";

int b[30];

int main(){

    //freopen("A-small-attempt2.in","r",stdin);
   // freopen("A-small-attempt2.out","w",stdout);
    int T,Cas=1;
    scanf("%d",&T);
    getchar();
    while(T--){
        char s[200];
        gets(s);
        printf("Case #%d: ",Cas++);
        for(int i = 0; i < strlen(s); i++)
            if(s[i]!=' ')
                printf("%c",a[s[i]-'a']);
            else printf(" ");
        printf("\n");
    }
}
