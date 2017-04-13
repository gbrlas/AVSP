#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MAXN 500
using namespace std;
char base[30]={'Q','W','E','R','A','S','D','F'};
int ref[300];
int opp[500][500],form[500][500];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int num=8;
    for(int i=0;i<26;i++){
        char now='A'+i;
        bool flag=false;
        for(int j=0;j<8;j++)
            if(base[j]==now)
                flag=true;
        if(!flag)
            base[num++]=now;
    }
    for(int i=0;i<26;i++)
        ref[base[i]]=i;
    int c,d,len;
    char ss[MAXN];
    int top,stack[MAXN];
    int T,cas=0;
    int u,v,w;
    scanf("%d",&T);
    while(T--){
        memset(opp,-1,sizeof(opp));
        memset(form,-1,sizeof(form));
        scanf("%d",&c);
        while(c--){
            scanf("%s",ss);
            u=ref[ss[0]];
            v=ref[ss[1]];
            w=ref[ss[2]];
            form[u][v]=w;
            form[v][u]=w;
            //printf("form[%c][%c]=%c",base[u],base[v],base[form[v][u]]);
        }
        scanf("%d",&d);
        while(d--){
            scanf("%s",ss);
            u=ref[ss[0]];
            v=ref[ss[1]];
            opp[u][v]=opp[v][u]=1;
        }
        scanf("%d%s",&len,ss);
        top=0;
        for(int i=0;i<len;i++){
            u=ref[ss[i]];
            if(!top)
                stack[++top]=u;
            else{
                v=stack[top];
                if(form[u][v]!=-1)
                    stack[top]=form[u][v];
                else{
                    bool flag=false;
                    for(int j=1;j<=top;j++){
                        v=stack[j];
                        if(opp[u][v]!=-1){
                            flag=true;
                            break;
                        }
                    }
                    if(flag)
                        top=0;
                    else
                        stack[++top]=u;
                }
            }
            //printf("ss[%d]=%c\tstack[%d]=%c\n",i,ss[i],top,base[stack[top]]);
        }
        printf("Case #%d: [",++cas);
        for(int i=1;i<=top;i++){
            printf("%c",base[stack[i]]);
            if(i<top)
                printf(", ");
        }
        printf("]\n");
    }
    //while(1);
    return 0;
}
                    
        
    
