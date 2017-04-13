#include <cstdlib>
#include <cstdio>
#include <cstring>

int main()
{
    FILE * in = fopen("A-large.in","r");
    FILE * out = fopen("out.txt","w+");
    int t;
    fscanf(in,"%d", &t);
//    scanf("%d", &t);
    for(int i = 1;i <= t;i++){
        int n;
        fscanf(in,"%d", &n);
    //    scanf("%d", &n);
        double odp[n + 1], owp[n + 1], wp[n + 1];
        int win[n + 1], tot[n + 1];
        memset(odp, 0, sizeof(odp));
        memset(win, 0, sizeof(win));
        memset(tot, 0, sizeof(tot));
        memset(owp, 0, sizeof(owp));
        memset(wp, 0, sizeof(wp));
        char s[n + 1][n + 1];
        for(int j = 1;j <= n;j++){
            fscanf(in,"%s", s[j]);
           // scanf("%s", s[j]);
            for(int k = 0;k < n;k++){
                if(s[j][k] == '1' || s[j][k] == '0') tot[j]++;
                if(s[j][k] == '1') win[j]++;
            }
    //        printf("win[%d] = %d tot[%d] = %d\n",j,win[j],j,tot[j]);
            wp[j] = (double) win[j] / tot[j];
    //        printf("wp[%d] = %lf\n",j,wp[j]);
        }
        for(int j = 1;j <= n;j++){
            int cnt = 0;
            double dpo = 0;
            for(int k = 1;k <= n; k++){
                if(k == j) continue;
                if(s[k][j - 1] != '.'){
                    int temp = tot[k], temp2 = win[k];
                    tot[k]--;
                    cnt++;
                    if(s[k][j - 1] == '1') win[k]--;
           //         printf("win[%d] = %d tot[%d] = %d\n",k,win[k],k,tot[k]);
                    dpo += (double) win[k] / tot[k];
                    tot[k] = temp;
                    win[k] = temp2;
                }
            }
            owp[j] = (double) dpo / cnt;
   //         printf("owp[%d] = %lf\n",j,owp[j]);
        }
        for(int j = 1;j <= n;j++){
            int cnt = 0;
            double dpo = 0;
            for(int k = 1;k <= n; k++){
                if(k == j) continue;
                if(s[k][j - 1] != '.'){
                    dpo += owp[k];
                    cnt++;
                }
            }
            odp[j] = (double) dpo / cnt;
   //         printf("odp[%d] = %lf\n",j,odp[j]);
        }
        fprintf(out,"Case #%d:\n", i);
   //     printf("Case #%d:\n", i);
        for(int j = 1;j <= n;j++){
     //       printf("%lf\n",wp[j] * 0.25 + owp[j] * 0.5 + odp[j] * 0.25);
            fprintf(out,"%lf\n",wp[j] * 0.25 + owp[j] * 0.5 + odp[j] * 0.25);
        }
    }
//    system("PAUSE");
    return 0;
}
