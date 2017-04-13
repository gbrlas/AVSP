#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MAXN 105
using namespace std;
int m;
char seq[MAXN];
int to[MAXN];
int pos[2];
int lv[2];
int kk;

int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int T,cas=0;
    int ans;
    char ss[10];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%s%d",ss,&to[i]);
            seq[i]=ss[0];
        }
        pos[0]=pos[1]=1;
        lv[0]=lv[1]=0;
        for(int i=1;i<=m;i++){
            if(seq[i]=='O'){
                lv[0]=abs(pos[0]-to[i]);
                break;
            }
        }
        for(int i=1;i<=m;i++){
            if(seq[i]=='B'){
                lv[1]=abs(pos[1]-to[i]);
                break;
            }
        }
        //printf("lv[0]=%d\tlv[1]=%d\n",lv[0],lv[1]);
        ans=0;
        kk=1;
        while(kk<=m){
            if(seq[kk]=='O'){
                ans+=lv[0]+1;
                lv[1]-=min(lv[1],lv[0]+1);
                pos[0]=to[kk];
                lv[0]=0;
                for(int i=kk+1;i<=m;i++){
                    if(seq[i]=='O'){
                        lv[0]=abs(pos[0]-to[i]);
                        break;
                    }
                }
            }
            else{
                ans+=lv[1]+1;
                lv[0]-=min(lv[1]+1,lv[0]);
                pos[1]=to[kk];
                lv[1]=0;
                for(int i=kk+1;i<=m;i++){
                    if(seq[i]=='B'){
                        lv[1]=abs(pos[1]-to[i]);
                        break;
                    }
                }
            }
            //printf("%c\t%d\nlv[0]=%d\tlv[1]=%d\n",seq[kk],to[kk],lv[0],lv[1]);
            kk++;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    //while(2);
    return 0;
}
        
                
