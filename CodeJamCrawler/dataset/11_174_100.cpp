#include <cstdlib>
#include <cstdio>

int main()
{
    FILE * in = fopen("B-small-attempt2.in","r");
    FILE * out = fopen("out.txt","w+");
    int t, count = 1;
  //  scanf("%d",&t);
    fscanf(in,"%d",&t);
    while(count <= t){
        int comb,opp,l, c[26][26];
        bool o[26][26];
        for(int i = 0;i < 26;i++){
            for(int j = 0;j < 26;j++){
                c[i][j] = -1;
                o[i][j] = false;
            }
        }
   //     scanf("%d",&comb);
        fscanf(in,"%d",&comb);
        for(int i = 0;i < comb;i++){
            char s[4];
            fscanf(in,"%s",s);
     //       scanf("%s",s);
            c[s[0] - 65][s[1] - 65] = s[2] - 65;
            c[s[1] - 65][s[0] - 65] = s[2] - 65;
        }
    //    scanf("%d",&opp);
        fscanf(in,"%d",&opp);
        for(int i = 0;i < opp;i++){
            char s[4];
        //    scanf("%s",s);
            fscanf(in,"%s",s);
            o[s[0] - 65][s[1] - 65] = true;
            o[s[1] - 65][s[0] - 65] = true;
        }
    //    scanf("%d",&l);
        fscanf(in,"%d",&l);
        int stack[l + 2],stp = 0;
        char list[l + 2],nl[l + 2];
        for(int i = 0;i < l + 2;i++) stack[i] = -1;
   //     scanf("%s",list);
        fscanf(in,"%s",list);
        for(int i = 0;i < l;i++){
            stack[stp] = list[i] - 65;
            while(stp > 0 && (c[stack[stp]][stack[stp - 1]] != -1)){
                stack[stp - 1] = c[stack[stp]][stack[stp - 1]];
          //          printf("stack[%d] = c[%d][%d] = %d\n",stp - 1,stack[stp],stack[stp - 1],c[stack[stp]][stack[stp - 1]]);
                stp--;
            }
            for(int i = stp - 1;i >= 0 ;i--){
                if(o[stack[i]][stack[stp]]){
                    stp = -1;
                    break;
                }
            }
            stp++;
       /*     for(int j = 0;j < stp;j++){
                printf("%c",stack[j] + 65);
            }
            printf("\n");*/
        }
        printf("Case #%d: [",count);
        fprintf(out,"Case #%d: [",count);
        for(int i = 0;i < stp;i++){
            printf("%c",stack[i] + 65);
            fprintf(out,"%c",stack[i] + 65);
            if(i < stp - 1){
                printf(", ");
                fprintf(out,", ");
            }
        }
        printf("]\n");
        fprintf(out,"]\n");
        count++;
    }
    system("PAUSE");
    return 0;
}
