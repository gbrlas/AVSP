#include <cstdlib>
#include <cstdio>

int main()
{
    FILE * in = fopen("A-small-attempt0.in","r");
    FILE * out = fopen("out.txt","w+");
    int t;
    fscanf(in,"%d", &t);
  //  scanf("%d", &t);
    for(int tt = 1;tt <= t;tt++){
        int r, c;
        fscanf(in,"%d %d", &r, &c);
     //   scanf("%d %d", &r, &c);
        char map[r + 1][c + 1];
        for(int i = 0;i < r;i++){
            fscanf(in,"%s", map[i]);
          //  scanf("%s", map[i]);
            if(i > 0) for(int j = 0;j < c - 1;j++){
                if(map[i][j] == '#' && map[i][j + 1] == '#' && map[i - 1][j] == '#' && map[i - 1][j + 1] == '#'){
                    map[i][j + 1] = map[i - 1][j] = '/';
                    map[i][j] = map[i - 1][j + 1] = '\\';
                }
            }
        }
        fprintf(out,"Case #%d:\n", tt);
        printf("Case #%d:\n", tt);
        bool ok = true;
        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
                if(map[i][j] == '#'){
                    ok = false;
                    break;
                }
        if(ok) for(int i = 0;i < r;i++){
            printf("%s\n", map[i]);
            fprintf(out,"%s\n", map[i]);
        }else{
            printf("Impossible\n");
            fprintf(out,"Impossible\n");
        }
    }
    system("PAUSE");
    return 0;
}
