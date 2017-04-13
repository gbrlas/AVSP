#include<stdio.h>

main(){
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for( int i = 1; i<=t; i++){
        int r, c;
        scanf("%d", &r);
        scanf("%d", &c);
        char matrix[r][c];
        for( int j = 0; j < r; j++ ){
            scanf("%s",&matrix[j]);
        }
        int flag = 0;
        for ( int j = 0; j < r; j++){
            for( int k = 0; k < c; k++){
                if(matrix[j][k] != '#') continue;
                if( k+1 >= c || j+1 >= r){
                    flag =1;
                    break;
                }
                if( matrix[j][k+1] == '#' && matrix[j+1][k] == '#' && matrix[j+1][k+1] == '#'){
                        matrix[j][k] = '/';
                        matrix[j][k+1] = '\\';
                        matrix[j+1][k] = '\\';
                        matrix[j+1][k+1] = '/';
                }
                else {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
        }
        printf("%s%d%s\n", "Case #", i,":");
        if(flag == 1) printf("Impossible\n");
        else{
           for( int j = 0; j< r; j++){
                for( int k = 0; k < c; k++)
                    printf("%c", matrix[j][k]);
            printf("\n");
        }

        }
    }
}
