#include<cstdio>
#include<cstring>
#include<cmath>
#define MAX 100

int main(){
    int T;
    double C,F,X;
    FILE *fp = fopen("out.txt","w");
    scanf("%d",&T);
    for (int k = 1; k<=T; k++){
        double res,r = 2;
        scanf("%lf%lf%lf",&C,&F,&X);
        if (X <= C)
            res = X / 2.0;
        else{
            res = C / 2.0;
            while (1){
                if ((X-C) / r > X / (r+F)){
                    res += C / (r+F);
                    r += F;
                }
                else{
                    res += (X - C) / r;
                    break;
                }
            }
        }
    fprintf(fp,"Case #%d: %.7lf\n",k,res);
    }
    return 0;
}




