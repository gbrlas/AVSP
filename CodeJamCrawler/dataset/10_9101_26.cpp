#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define MAXN 50000
#define MAXLEN 150
using namespace std;
struct{
    char name[MAXLEN];
    int next;
}node[MAXN];
int N,num,first[MAXN];
int add(int pre,char *s)
{
    N++;
    strcpy(node[N].name,s);
    node[N].next=first[pre];
    first[pre]=N;
    return N;
}
int find(int pre,char *s)
{
    for(int k=first[pre];k>=0;k=node[k].next)
        if(!strcmp(s,node[k].name))
            return k;
    return -1;
}
int main()
{
    freopen("2010.in","r",stdin);
    FILE *fout=fopen("2010.out","w");
    int idx,index,pos,n,m,t,k,ans;
    char s[MAXLEN],tmp[MAXLEN];
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++){
        scanf("%d%d\n",&n,&m);
        memset(first,-1,sizeof(first));
        num=0;
        for(int i=0;i<n;i++){
            gets(s);
            idx=0;
            pos=0;
            while(s[idx]!='\0'){
                index=1;
                while(s[index+idx]!='\0'&&s[index+idx]!='/'){
                    tmp[index-1]=s[index+idx];
                    index++;
                }
                tmp[index-1]='\0';
                k=find(pos,tmp);
                if(k>=0)
                    pos=k;
                else
                    pos=add(pos,tmp);
                //puts(tmp);
                idx+=index;
            }
        }
        ans=0;
        for(int i=0;i<m;i++){
            gets(s);
            idx=0;
            pos=0;
            while(s[idx]!='\0'){
                index=1;
                while(s[index+idx]!='\0'&&s[index+idx]!='/'){
                    tmp[index-1]=s[index+idx];
                    index++;
                }
                tmp[index-1]='\0';
                k=find(pos,tmp);
                if(k>=0)
                    pos=k;
                else{
                    pos=add(pos,tmp);
                    ans++;
                }
                //puts(tmp);
                idx+=index;
            }
        }
        fprintf(fout,"Case #%d: %d\n",cases,ans);
    }
    //while(1);
    return 0;
}
                
