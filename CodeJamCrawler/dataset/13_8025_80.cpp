#include<stdio.h>

int T, N, M;
int arr[110][110];      //lawn
int pat[110][110];      //pattern
int hor[110], ver[110]; //i dan j

bool cek() {
    for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
        if (arr[i][j]!=pat[i][j])
            return false;
    return true;
}

int main() {
    //freopen("B.txt","r",stdin);
    //freopen("B.out","w",stdout);
    
    scanf("%d",&T);
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 110; i++) {
            hor[i] = ver[i] = 0;
            for (int j = 0; j < 110; j++) {
                arr[i][j] = 100;
                pat[i][j] = 0;
            }
        }
        
        scanf("%d %d",&N,&M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d",&pat[i][j]);
                if (pat[i][j] > hor[i]) hor[i] = pat[i][j];
            }
        }
        for (int j = 0; j < M; j++)
        for (int i = 0; i < N; i++)
            if (pat[i][j] > ver[j]) ver[j] = pat[i][j];
        /*
        for (int i = 0; i <= N+1; i++)
        for (int j = 0; j <= M; j++)
            if (j==M) printf("| %d\n", hor[i]);
            else if (i==N+1) printf("%d ", ver[j]);
            else if (i==N) printf("--");
            else printf("%d ", pat[i][j]);
        puts("");//*/
        for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (arr[i][j] > hor[i]) arr[i][j] = hor[i];
        for (int j = 0; j < M; j++)
        for (int i = 0; i < N; i++)
            if (arr[i][j] > ver[j]) arr[i][j] = ver[j];
        /*
        for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d ",arr[i][j]);
            printf("\n");
        }   printf("\n");//*/
        printf("Case #%d: ", t+1);
        if (cek()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
