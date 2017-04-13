#include<cstdio>

#include<algorithm>
using namespace std;
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("1.out","w",stdout);
    int T,a,b;
    int box[5][5],bj[9];
    scanf("%d",&T);
    int first;
    for(int n = 1; n <= T; n++)
    {
        first = 1;
        scanf("%d",&a);
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++)
            {
                scanf("%d",&box[i][j]);
                if(i==a)
                    bj[first++] = box[i][j];
            }
        scanf("%d",&b);
        for(int i=1; i<=4; i++)
            for(int j=1; j<=4; j++)
            {
                scanf("%d",&box[i][j]);
                if(i==b)
                    bj[first++] = box[i][j];
            }
        sort(bj+1,bj+9);
        int test=0;
        int logo=0;
        for(int i=1;i<8;i++)
        {
            if(bj[i]==bj[i+1])
               {
                   test++;
                   logo = bj[i];
               }
        }
        printf("Case #%d: ",n);
        if(test==1)
            printf("%d\n",logo);
        if(test>1)
            printf("Bad magician!\n");
        if(test<1)
            printf("Volunteer cheated!\n");
    }
}
