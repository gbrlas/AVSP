#include <cstdlib>
#include <cstdio>

int main()
{
    FILE * in = fopen("A-small-attempt1.in","r");
    FILE * out = fopen("out.txt","w+");
    int t, count = 1;
    fscanf(in,"%d",&t);
//    scanf("%d",&t);
    while(count <= t){
        int n, o[100], b[100], ocount = 0, bcount = 0,scount = 0,seq[100][2];
      //  scanf("%d",&n);
        fscanf(in,"%d",&n);
        for(int i = 0;i < n;i++){
            char s[2];
            int p;
         //   scanf("%s %d",s,&p);
            fscanf(in,"%s %d",s,&p);
            if(s[0] == 'O'){
                o[ocount++] = p;
            }else{
                b[bcount++] = p;
            }
            seq[scount][0] = p;
            seq[scount++][1] = s[0];
        }
        int but = 0, time = 0, op = 1, bp = 1, om = 0, bm = 0;
        bool presso = true, pressb = true;
        while(but < n){
            presso = pressb = true;
            if(o[om] > op && om < ocount){
                op++;
                presso = false;
            }else if(o[om] < op && om < ocount){
                op--;
                presso = false;
            }
            if(b[bm] > bp && bm < bcount){
                bp++;
                pressb = false;
            }else if(b[bm] < bp && bm < bcount){
                bp--;
                pressb = false;
            }
            if(seq[but][1] == 'O'){
                if(seq[but][0] == op && presso){
                    but++;
                    om++;
                }
            }else if(seq[but][0] == bp && pressb){
                but++;
                bm++;
            }
            time++;
      //      printf("time = %d but = %d op = %d bp = %d\n",time,but,op,bp);
        }
        printf("Case #%d: %d\n",count,time);
        fprintf(out,"Case #%d: %d\n",count,time);
        count++;
    }
    system("PAUSE");
    return 0;
}
