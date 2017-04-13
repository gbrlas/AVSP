#include<stdio.h>
double c,f,x,g;
double r;
double ans;
void proc(int xx){
    r=2.0;
    ans=0;
    scanf("%lf %lf %lf",&c,&f,&x);
    g = x / r;
    while(1){
        if(ans+(c/r)+(x/(r+f))<g){
            g=ans+(c/r)+(x/(r+f));
            ans+=c/r;
            r+=f;
        }
        else{
            break;
        }
        //printf("w %.7llf\n",g);
    }
    printf("Case #%d: %.7llf\n",xx,g);
}
int main(){
    int tt;
    int i;
    scanf("%d",&tt);
    for(i=0;i<tt;i++)proc(i+1);
    return 0;
}
