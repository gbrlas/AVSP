#include<cstdio>
#include<algorithm>
using namespace std;
struct box
{
    double zhl;
    int flag;
}a[2020];
bool compare(box a,box b)
{
    return a.zhl<b.zhl;
}
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("4.out","w",stdout);
    int T,N;
    int hou,qian;
    scanf("%d",&T);
    for(int n = 1; n <= T; n++)
    {
        scanf("%d",&N);
        for(int i = 1; i <= N; i++)
            {
                scanf("%lf",&a[i].zhl);
                a[i].flag=0;
            }
        for(int i = 1; i <= N; i++)
            {
                scanf("%lf",&a[N+i].zhl);
                a[N+i].flag=1;
            }
        sort(a+1,a+1+N+N,compare);


        int test1 = 0;
        hou = 0;
        qian = 0;
        for(int i = N+N; i >= 1; i--)
        {
            if(a[i].flag==0)
            {
                if(test1 >= 0)
                    hou++;
                else
                    test1++;
            }
            else
            {
                test1--;
            }
        }
        int f = 0;
        int k = 0;
        for(int i = 1; i <= N+N; i++)
        {
            if(a[i].flag==1)
            {
                f++;
                if((N-k>0)&&(N-k>=f))
                    qian++;
            }
            else
            {
                k++;
                if(f>0)
                    f--;
            }
        }
        printf("Case #%d: %d %d\n",n,qian,hou);
    }
    return 0;
}
