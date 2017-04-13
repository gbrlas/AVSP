#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX 1000+10

using namespace std;

int main(){
    FILE *fp = fopen("out.txt","w");
    int T,n;
    double x[MAX],y[MAX];
    scanf("%d",&T);
    for (int k = 1; k<=T; k++){
        scanf("%d",&n);
        for (int i=0; i<n; i++)
            scanf("%lf",&x[i]);
        for (int i=0; i<n; i++)
            scanf("%lf",&y[i]);
        sort(x,x+n);
        sort(y,y+n);
        int u = 0,v = 0,c1 = 0,c2 = 0;
        while (u<n && v<n){
            if (x[u] >= y[v]){
                u++;
                v++;
                c1++;
            }
            else  u++;
        }
        u = 0;
        v = 0;
        while (u<n && v<n){
            if (y[v] >= x[u]){
                u++;
                v++;
                c2++;
            }
            else v++;
        }
   // printf("%d  %d\n",c1,n-c2);
    fprintf(fp,"Case #%d: %d %d\n",k,c1,n-c2);
    }
    return 0;
}




