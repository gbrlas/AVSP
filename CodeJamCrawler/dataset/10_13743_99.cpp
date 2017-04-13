#include <stdio.h>

int v[1000],g[1000],N,i,j,t,T,R,k;
int qhead,period,psgr;
long long curmoney,tot;
long long money[1001];
int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    scanf("%d",&T);
    money[0] = 0;
    for(t=1;t<=T;t++){
        scanf("%d %d %d",&R,&k,&N);
        for(i=0;i<N;i++)scanf("%d",&g[i]);
        for(i=0;i<N;i++)v[i] = 0;
        qhead = 0;
        curmoney = 0;
        for(i=0;i<R;i++){
            if(v[qhead]!=0){
                break;
            }
            //v[qhead] = 1;
            psgr = 0;
            for(j=qhead;;){
                psgr += g[j];
                if(psgr>k)break;
                curmoney += g[j];
                j++;
                if(j==N)j=0;
                if(j==qhead)break;
            }
            qhead = j;
            //money[i+1] = curmoney;
        }
        //period = i;
        //tot = money[period]*(R/period) + money[R%period];
        printf("Case #%d: %I64d\n",t,curmoney);
    }
}

