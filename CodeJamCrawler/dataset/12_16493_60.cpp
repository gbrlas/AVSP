#include<stdio.h>
#include<string.h>
main(){
    freopen("A-small-attempt.in","r",stdin);
    freopen("A-small-attempt.out","w",stdout);
    char s[1001];
    char a[31]="yhesocvxduiglbkrztnwjpfmaq";
    int T,len,i,c;
    scanf("%d",&T);
    char tmp=getchar();
    for(c=1;c<=T;c++){
        gets(s);
        len=strlen(s);
        printf("Case #%d: ",c);
        for(i=0;i<len;i++){
            if(s[i]==32) printf(" ");
            else printf("%c",a[s[i]-'a']);
        }
        printf("\n");
    }
}
