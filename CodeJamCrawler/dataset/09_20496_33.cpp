#include <stdio.h>
#include <string.h>

int main() {
    char words[5000][16];
    int pattern[26][16];
    char pat[1000],*hlp;
    char t;
    int i;
    int l,d,n;
    int x,y;
    int cnt,inc;
    
    scanf("%d %d %d",&l,&d,&n);
    
    for (i=0;i<d;i++)
        scanf("%s",words[i]);
    for (i=1;i<=n;i++) {
        for (x=0;x<26;x++)
            for (y=0;y<16;y++)
                    pattern[x][y]=0;
        scanf("%s",pat);
        hlp = pat;
        y=0;
        while(hlp[0]!='\0') {
            cnt = 0;
            if (hlp[0]=='(') {
                hlp++;
                while ( (t=hlp[0]) != ')' ) {
                    pattern[t-'a'][y] = 1;
                    hlp++;
                }
                hlp++;
            } else {
                pattern[hlp[0]-'a'][y]=1;
                hlp++;
            }
            y++;
        }
        
        for (x=0;x<d;x++) {
            inc = 1;
            for (y=0;y<l;y++)
                if (pattern[words[x][y]-'a'][y]==0)
                    inc = 0;
            cnt += inc;
        }
        printf("Case #%d: %d\n",i,cnt);
    }

    //system("pause");
}
