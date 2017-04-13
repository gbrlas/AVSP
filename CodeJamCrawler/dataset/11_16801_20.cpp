#include <stdio.h>

float avg_w(int*a,int i,int j,int n){
    int t=0,w=0;
    for(int val=0;val<n;val++){
        if(val == i || val == j) continue;
        if( a[val]!= -1){
            ++t;
            if(a[val])
                ++w;
        }
    }
    if(!t) t=1;
    return float(w)/t;
}

int main(){
    freopen("input","rt",stdin);
    freopen("out","wt",stdout);

    int cases;
    scanf("%d",&cases);

    for(int iCase=0;iCase<cases;++iCase){
        int teams;
        scanf("%d",&teams);
        char *buf = new char[teams];
        int **table = new int*[teams];
        int* wins = new int[teams];
        int *totals = new int[teams];
        float *WP = new float[teams];
        float *OWP = new float[teams];
        float *OOWP = new float[teams];
        for(int iTeams=0;iTeams<teams;++iTeams){
            table[iTeams]=new int[teams];
            scanf("%s",buf);
            int games = 0, win = 0;
            for(int i=0;i<teams;i++){

                switch(buf[i]){
                case '0':
                    table[iTeams][i] = 0;
                    games+=1;
                    break;
                case '1':
                    table[iTeams][i] = 1;
                    games+=1;
                    win+=1;
                    break;
                default:
                    table[iTeams][i] = -1;
                }
            }
            if(games>0)
            WP[iTeams] = float(win)/games;
            else WP[iTeams] = 0.0;
            wins[iTeams] = win;
            totals[iTeams] = games;
        }

        for(int i=0;i<teams;i++){
            int total = 0;
            float sum = 0.0;
            for(int j=0;j<teams;j++){
                if(table[i][j] != -1){
                    total += 1;
                    sum += float(wins[j]-table[j][i])/(totals[j]-1);
                }
            }
            if(total>0)
            OWP[i] = sum/total;
            else OWP[i] =0.0;

        }
        printf("Case #%d:\n",iCase+1);
        for(int i=0;i<teams;i++){
            int total = 0;
            float sum = 0.0;
            for(int j=0;j<teams;j++){
                if(table[i][j] != -1){
                    total += 1;
                    sum += OWP[j];
                }
            }
            if(total>0)
            OOWP[i] = sum/total;
            else OOWP[i] =0.0;
            printf("%f\n",0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i]);
        }

    }
    return 0;
}
