#include <stdio.h>
#include <string.h>

int kase,kk,n,m;
char map[300][300];
bool map2[300][300];
char ts[200];
char res[200];
int len;

int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&kase);
    while(kase--) {
        memset(map,0,sizeof(map));
        memset(map2,false,sizeof(map2));
        scanf("%d",&m);
        while (m--) {
            scanf("%s",ts);
            map[ts[0]][ts[1]]=map[ts[1]][ts[0]]=ts[2];
        }
        scanf("%d",&m);
        while (m--) {
            scanf("%s",ts);
            map2[ts[0]][ts[1]]=map2[ts[1]][ts[0]]=true;
        }
        scanf("%d%s",&n,ts);
        memset(res,0,sizeof(res));
        res[0]=ts[0];
        len=1;
        for (int i=1;i<n;i++) {
            if (len>0&&map[ts[i]][res[len-1]]!='0'&&map[ts[i]][res[len-1]]) {
                res[len-1]=map[ts[i]][res[len-1]];
            }
            else {
                bool pd=true;
                for (int j=0;j<len;j++) {
                    if (map2[res[j]][ts[i]]) {
                        len=0;
                        memset(res,0,sizeof(res));
                        pd=false;
                        break;
                    }
                }
                if (pd) {
                    res[len++]=ts[i];
                }
            }
        }
        printf("Case #%d: [",++kk);
        for (int i=0;i<len;i++) {
            if (i) printf(", ");
            printf("%c",res[i]);
        }
        printf("]\n");
    }
    return 0;
}
