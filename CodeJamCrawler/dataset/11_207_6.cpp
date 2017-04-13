#include <cstdlib>
#include <cstdio>
#include <iostream>
#define lli long long

int fac[8] = {1, 2, 4, 5, 10, 20, 50, 100};

int main()
{
    FILE * in = fopen("A-small-attempt0.in","r");
    FILE * out = fopen("ans.txt","w+");
    int t, d, g;
    lli n;
 //   scanf("%d", &t);
    fscanf(in,"%d", &t);
    for(int i = 1;i <= t;i++){
        bool ok = false;
     //   scanf("%I64d %d %d", &n, &d, &g);
        fscanf(in,"%I64d %d %d", &n, &d, &g);
        for(int j = 0;j < 8 && fac[j] <= n && !ok;j++)
            if(d % (100 / fac[j]) == 0) ok = true;
        if((g == 0 && d != 0) || (g == 100 && d != 100)) ok = false;
        printf("Case #%d: %s",i,ok ? "Possible\n" : "Broken\n");
        fprintf(out, "Case #%d: %s",i,ok ? "Possible\n" : "Broken\n");
    }
    system("PAUSE");
    return 0;;
}
