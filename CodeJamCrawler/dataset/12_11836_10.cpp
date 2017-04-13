#include<stdio.h>
#include<algorithm>
using namespace std;
struct point{
        int a,b,num;
}p[10000];

int i,j,n,m;

bool cmp(point a,point b){
        // if(a.a*a.b==b.a*b.b)
        //         return a.num<b.num;
        // return a.a*a.b>b.a*b.b;
        if(a.b==b.b)
                return a.num<b.num;
        return a.b>b.b;

}



int main(){
        int ii,nn;
        scanf("%d",&nn);
        for(ii=1;ii<=nn;ii++){
                printf("Case #%d:",ii);
                scanf("%d",&n);
                for(i=1;i<=n;i++){
                        scanf("%d",&p[i].a);
                }
                for(i=1;i<=n;i++){
                        scanf("%d",&p[i].b);
                        p[i].num=i;
                }
                sort(&p[1],&p[1+n],cmp);
                for(i=1;i<=n;i++){
                        printf(" %d",p[i].num-1);
                }
                printf("\n");
        }
                              
        return 0;
}
          
