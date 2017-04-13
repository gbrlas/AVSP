#include<cstdio>
using namespace std;
main(){
    int t;
    double c,f,x;
    //freopen("F:\\B-small-attempt0.in","r", stdin);
    //freopen("F:\\OUTPUTB.txt", "w", stdout);
    scanf("%d",&t);
    int tmp=1;
    while(t--){
        scanf("%lf%lf%lf",&c,&f,&x);
        double ans=0.0;
        int a=0;
        double tmpx=x/((double)a*f+2),tmpcx=c/((double)a*f+2)+x/((double)a*f+2+f);
        while(tmpx>tmpcx){
            ans+=c/((double)a*f+2);
            a++;
            tmpx=x/((double)a*f+2),tmpcx=c/((double)a*f+2)+x/((double)a*f+2+f);
        }
        ans+=tmpx;
        printf("Case #%d: %.8f\n",tmp++,ans);
    }
}
