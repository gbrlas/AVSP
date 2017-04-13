#include <stdio.h>
#include <string.h>

#define ABS(x) (x)>0?(x):-1*(x)

struct Node
{
    char c;
    int cnt;
}node[101][101];
int node_len[101];

int main()
{
    int T;
    scanf("%d", &T);
    int t,i,j;
    for(t=1;t<=T;t++)
    {
        memset(node_len, 0, sizeof(node_len));
        char str[101];
        int N;
        scanf("%d", &N);
        for(i=0;i<N;i++)
        {
            scanf("%s", str);
            char pre=0;
            for(j=0;str[j];j++)
                if(pre != str[j])
                {
                    node[i][node_len[i]].c=str[j];
                    node[i][node_len[i]].cnt=1; 
                    node_len[i]++;
                    pre=str[j];
                }
                else
                    node[i][node_len[i]-1].cnt++;
        }
        int ans=1<<30;
        int flag=1;
        for(i=0;i<N&&flag;i++)
        {
            if(node_len[i] != node_len[0])
            {
                flag=0;
                break;
            }
            for(j=0;j<node_len[0];j++)
                if(node[i][j].c != node[0][j].c)
                {
                    flag=0;
                    break;
                }
        }
        if(flag)
        {
            int cur=0;
            for(i=0;i<node_len[0];i++)
            {
                int sum=0;
                for(j=0;j<N;j++)
                    sum+=node[j][i].cnt;
                int avg=sum/N;
                for(j=0;j<N;j++)
                    cur += ABS(node[j][i].cnt - avg);
            }
            ans=cur;
        }
        printf("Case #%d: ", t);
        if(flag)
            printf("%d\n", ans);
        else
            printf("Fegla Won\n");
    }
    return 0;
}
