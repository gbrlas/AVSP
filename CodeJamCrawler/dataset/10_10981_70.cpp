#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

map <string,bool> has;

int kase,n,m,res;
char str[200],tmp[200];
string tmps;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&kase);
    for (int i=1;i<=kase;i++) {
        scanf("%d%d",&n,&m);
        res=0;
        has.clear();
        for (int j=0;j<n;j++) {
            scanf("%s",str);
            for (int k=1;k<strlen(str);k++) {
                if (str[k]=='/') {
                    strcpy(tmp,str);
                    tmp[k]=0;
                    tmps=tmp;
                    has[tmps]=true;
                }
            }
            tmps=str;
            has[tmps]=true;
        }
        for (int j=0;j<m;j++) {
            scanf("%s",str);
            for (int k=1;k<strlen(str);k++) {
                if (str[k]=='/') {
                    strcpy(tmp,str);
                    tmp[k]=0;
                    tmps=tmp;
                    //printf("--------%s\n",tmp);
                    if (has.count(tmps)==0) {
                        //printf("-----has not %s\n",tmp);
                        has[tmps]=true;
                        res++;
                    }
                }
            }
            tmps=str;
            //printf("------%s\n",str);
            if (has.count(tmps)==0) {
                has[tmps]=true;
                res++;
            }
        }
        printf("Case #%d: %d\n",i,res);
    }
    return 0;
}
