#include<stdio.h>

main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d",&t);
    for( int k = 1; k<= t; k++){
        int n;
        scanf("%d", &n);
        char value[n][n];
        int matches[n];
        for( int i = 0; i < n; i++)
            matches[i] = 0;
        double wp[n];
        double owp[n];
        double oowp[n];

        for(int i = 0;i < n; i++){
                double wins = 0.0;
                scanf("%s", &value[i]);
                for(int j = 0; j<n;j++){
                    if(value[i][j] == '1') {
                        matches[i]++;
                        wins++;
                    }
                    if( value[i][j] == '0')
                        matches[i]++;
                }
                wp[i] = wins/(matches[i]);
        }

        for( int i = 0; i< n; i++){
            double x = 0.0;
            for( int j= 0; j< n; j++){
                if(value[i][j] == '.') continue;
                x= x+(wp[j]*matches[j]-(value[j][i]-'0'))/(matches[j]-1);
            }
            owp[i] = x/matches[i];
        }

        for( int i = 0; i< n; i++){
            double x = 0.0;
            for( int j= 0; j< n; j++){
                if(value[i][j] == '.') continue;
                x= x+owp[j];
            }
            oowp[i] = x/matches[i];
        }

        printf("%s%d%s\n","Case #",k,":");
        for( int i = 0; i< n; i++)
            printf("%.12g\n",(0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]));
    }
}
