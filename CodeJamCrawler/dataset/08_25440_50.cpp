#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

struct data{
    int start,arrive,state;
}p[1000];

multiset<int>f[2];
int n,m,ans[2];

bool cmp(const data& a,const data& b) {
    return a.start<b.start;
}

void done() {

    int i;
    multiset<int>::iterator iter;
    for (i=1;i<=n+m;i++) {
        if (f[p[i].state].size()==0) {
            ans[p[i].state]++;
            f[1-p[i].state].insert(p[i].arrive);
        }else{
            if (*(f[p[i].state].begin())<=p[i].start) {
                f[1-p[i].state].insert(p[i].arrive);
                f[p[i].state].erase(f[p[i].state].begin());
            } else {
                ans[p[i].state]++;
                f[1-p[i].state].insert(p[i].arrive);        
            } 
        }
//        printf("******%d\n",i);
//        for(iter=f[0].begin();iter!=f[0].end();iter++) printf("    %d:%d    ",*iter/60,*iter%60);
//        printf("\n");
//        for(iter=f[1].begin();iter!=f[1].end();iter++) printf("    %d:%d    ",*iter/60,*iter%60);
//        printf("\n");
    }
}

int main() {

    int test,i,time;
    freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&test);
    for (int ttest=1;ttest<=test;ttest++) {
        scanf("%d",&time);
        scanf("%d %d",&n,&m);
        int h1,m1,h2,m2;
        for (i=1;i<=n;i++) {
            scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
            p[i].start=h1*60+m1;
            p[i].arrive=h2*60+m2+time;
            p[i].state=0;
        }
        for (i=1;i<=m;i++) {
            scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
            p[i+n].start=h1*60+m1;
            p[i+n].arrive=h2*60+m2+time;
            p[i+n].state=1;
        }    
        ans[0]=ans[1]=0;
        f[0].clear(); f[1].clear();
        sort(p+1,p+n+m+1,cmp);
        done();       
        printf("Case #%d: %d %d\n",ttest,ans[0],ans[1]);      
    }

}
