#include<stdio.h>
int main(void){
    int L, D, N;
    int i, j, k, n, tmp, *tmpptr;
    int a[5000][15];
    int c;
    int mask;
    int _stack1[5000], top1, *stack1;
    int _stack2[5000], top2, *stack2;
    char string[16];
    stack1 = _stack1;
    stack2 = _stack2;
    scanf("%d %d %d ", &L, &D, &N);
    n=D;
    for(i=0;i<D;i++)
    {
        for(j=0;j<L;j++)
        {
            a[i][j]= (1<<(getchar()-'a'));
        }
        getchar();
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<L;j++)
        {
            c = getchar();
            if(c == '(')
            {
                mask = 0;
                while((c = getchar()) != ')')
                    mask |= (1<<(c-'a'));
            }else{
                mask = 1<<(c-'a');
            }

            if(j==0)
            { /*first filte*/
                top1 = 0;
                for(k=0;k<D;k++)
                {
                    if(a[k][0] & mask)
                    {
                        stack1[top1++] = k;
                    }
                }
            }else
            { /*other filte*/
                top2 = 0;
                while(top1--)
                {
                    if(a[stack1[top1]][j] & mask)
                        stack2[top2++] = stack1[top1];
                }
                tmpptr = stack1; stack1 = stack2; stack2 = tmpptr;
                top1=top2;
            }
        }
        getchar();

        printf("Case #%d: %d\n", i+1, top1);
    }
    return 0;
}