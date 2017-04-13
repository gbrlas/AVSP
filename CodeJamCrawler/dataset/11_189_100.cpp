#include <cstdlib>
#include <cstdio>

int main()
{
    FILE * in = fopen("C-large.in","r");
    FILE * out = fopen("out.txt","w+");
    int t;
//    scanf("%d",&t);
    fscanf(in,"%d",&t);
    for(int i = 1;i <= t;i++){
        int n, xr = 0, min = 2147483647, sum = 0;
    //    scanf("%d",&n);
        fscanf(in,"%d",&n);
        for(int j = 0;j < n;j++){
            int temp;
        //    scanf("%d",&temp);
            fscanf(in,"%d",&temp);
            xr ^= temp;
            if(min > temp) min = temp;
            sum += temp;
        }
        printf("Case #%d: ",i);
        fprintf(out,"Case #%d: ",i);
        if(xr == 0){
            printf("%d\n",sum - min);
            fprintf(out,"%d\n",sum - min);
        }else{
            printf("NO\n");
            fprintf(out,"NO\n");
        }
    }
//    system("PAUSE");
    return 0;
}
