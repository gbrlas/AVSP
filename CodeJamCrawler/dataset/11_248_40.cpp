#include <cstdlib>
#include <cstdio>
#include <cstring>
#define lli long long int

int main()
{
    FILE * in = fopen("C-small-attempt1.in","r");
    FILE * out = fopen("out.txt","w+");
    int t;
    fscanf(in,"%d", &t);
   // scanf("%d", &t);
    for(int tt = 1;tt <= t;tt++){
        int n;
        bool ok[10001];
        memset(ok, true, sizeof(ok));
        lli l, h;
        fscanf(in,"%d %I64d %I64d", &n, &l, &h);
     //   scanf("%d %I64d %I64d", &n, &l, &h);
        int note[n];
        for(int i = 0;i < n;i++){
            fscanf(in,"%d", &note[i]);
            //scanf("%d", &note[i]);
            if(i > 0) for(int j = l;j <= h;j++){
                if(ok[j] && !((j % note[i - 1] == 0 || note[i - 1] % j == 0) && (j % note[i] == 0 || note[i] % j == 0)))
                    ok[j] = false;
        //        fprintf(out,"ok[%d] = %d\n",j,ok[j]);
           //     printf("ok[%d] = %d\n",j,ok[j]);
            }
        }
        bool exist = false;
        int tar;
        for(int j = l;j <= h;j++) if(ok[j]){
            exist = true;
            tar = j;
            break;
        }
        fprintf(out,"Case #%d: ", tt);
    //    printf("Case #%d: ", tt);
        if(exist){
            fprintf(out,"%d\n", tar);
        //    printf("%d\n", tar);
        }else{
            fprintf(out,"NO\n");
       //     printf("NO\n");
        }
    }
//    system("PAUSE");
    return 0;
}
