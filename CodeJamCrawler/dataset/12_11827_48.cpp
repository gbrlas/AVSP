#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 2000
#define eps (1e-9)

typedef long long int lld;
struct point{
        lld r;
};

struct point2{
        lld x,y;
        int o;
}que[maxn*maxn];

lld w,l;

struct box{
        point2 p;
        lld r;
        int num;
        bool overlap(box& a){
                // printf("(aaa %lld %lld %lld %lld,%lld %lld)\n",p.x,p.y,a.p.x,a.p.y,r,a.r);                                


                if(p.x-r>=a.p.x+a.r||p.y-r>=a.p.y+a.r)
                        return 0;
                if(a.p.x-a.r>=p.x+r||a.p.y-a.r>=p.y+r)
                        return 0;

                return 1;
        }
}p[maxn];

bool cmp(box a,box b){
        return a.r>b.r;
}
bool cmp2(box a,box b){
        return a.num<b.num;
}


int i,j,k,n,m;




int main(){
        int ii,nn;
        scanf("%lld",&nn);
        for(ii=1;ii<=nn;ii++){
                printf("Case #%d:",ii);
                scanf("%lld %lld %lld",&n,&w,&l);
                for(i=1;i<=n;i++){
                        scanf("%lld",&p[i].r);
                        // p[i].r+=p[i].r;
                        p[i].num=i;
                }
                sort(&p[1],&p[1+n],cmp);
                m=1;
                que[1].x=que[1].y=0;
                que[1].o=-1;
                for(i=1;i<=n;i++){
                        for(j=m;j;j--){
                                p[i].p=que[j];
                                if(que[j].o==0){
                                        p[i].p.x+=p[i].r;
                                }else if(que[j].o==1){
                                        p[i].p.y+=p[i].r;
                                }
                                if(p[i].p.x>w||p[i].p.y>l)
                                        continue;
                                for(k=1;k<i;k++){
                                        if(p[i].overlap(p[k]))
                                                break;
                                }
                                if(k==i)
                                        break;
                        }
                        if(j==0){
                                printf("Error\n");
                        }
                        if(p[i].p.x+p[i].r<=w){
                        m++;
                        que[m]=p[i].p;
                        que[m].x+=p[i].r;
                        que[m].o=0;
                        }
                        if(p[i].p.y+p[i].r<=l){
                        m++;
                        que[m]=p[i].p;
                        que[m].y+=p[i].r;
                        que[m].o=1;
                        }
                }
                sort(&p[1],&p[1+n],cmp2);
                for(i=1;i<=n;i++){
                        printf(" %lld %lld",p[i].p.x,p[i].p.y);
                }
                printf("\n");

        }
        
        return 0;
}
