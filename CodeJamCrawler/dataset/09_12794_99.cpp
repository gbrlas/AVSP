#include<stdio.h>
#define smalleq(a,b,c,d,e) ((a)<(b) && (a)<=(c) && (a)<=(d) && (a)<=(e))

typedef struct _land {int h; struct _land *basin; char c;} land;
int main(){
    int n, i, j;
    int T, H, W;
    land a[102][102];
    land *_stack1[10000], **stack1;
    land *_stack2[10000], **stack2;
    int top1, top2;
    char c;
    stack1 = _stack1;
    stack2 = _stack2;

    scanf("%d ", &T);
    for(n=0;n<T;n++)
    {
        c='a';
        scanf("%d %d ", &H, &W);
        for(i=1;i<=H;i++)
        {
            for(j=1;j<=W;j++)
            {
                scanf("%d ", &a[i][j].h);
            }
        }

        /* around wall */
        j=H+2;
        for(i=0;i<j;i++) { a[i][0].h=10000; a[i][W+1].h=10000; }
        j=W+2;
        for(i=0;i<j;i++) { a[0][i].h=10000; a[H+1][i].h=10000; }

        top1=0;
        for(i=1;i<=H;i++)
        {
            for(j=1;j<=W;j++)
            {
                a[i][j].c='\0';
                a[i][j].basin =
                    smalleq(a[i-1][j].h, a[i][j].h, a[i][j-1].h, a[i][j+1].h, a[i+1][j].h) ? &a[i-1][j] :
                    smalleq(a[i][j-1].h, a[i][j].h, a[i-1][j].h, a[i][j+1].h, a[i+1][j].h) ? &a[i][j-1] :
                    smalleq(a[i][j+1].h, a[i][j].h, a[i][j-1].h, a[i-1][j].h, a[i+1][j].h) ? &a[i][j+1] :
                    smalleq(a[i+1][j].h, a[i][j].h, a[i][j-1].h, a[i][j+1].h, a[i-1][j].h) ? &a[i+1][j] :
                    &a[i][j];
                if(a[i][j].basin != &a[i][j])
                    stack1[top1++] = &a[i][j];
            }
        }
        while(top1--)
        {
            while(stack1[top1]->basin->basin != stack1[top1]->basin)
            {
                stack1[top1]->basin = stack1[top1]->basin->basin;
            }
        }
        printf("Case #%d:\n", n+1);
        for(i=1;i<=H;i++)
        {
            for(j=1;j<=W;j++)
            {
                if(a[i][j].basin->c == '\0')
                    a[i][j].basin->c = c++;
                printf("%c ", a[i][j].basin->c);
            }
            puts("");
        }
    }
    return 0;
}
