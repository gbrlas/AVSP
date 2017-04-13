#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int w[18];
int a[5][5];
int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        memset(w,0,sizeof(w));
        int row;
        scanf("%d",&row);
        for (int i=1;i<=4;i++)
            for (int j=1;j<=4;j++)
                scanf("%d",&a[i][j]);
        for (int i=1;i<=4;i++) w[a[row][i]]++;
        scanf("%d",&row);
        for (int i=1;i<=4;i++)
            for (int j=1;j<=4;j++)
                scanf("%d",&a[i][j]);
        for (int i=1;i<=4;i++) w[a[row][i]]++;
        int cnt=0,po;
        for (int i=1;i<=16;i++)
            if (w[i]>=2)
            {
                cnt++;
                po=i;
            }
        printf("Case #%d: ",cas);
        if (cnt>1) printf("Bad magician!\n");
        else if (cnt==1) printf("%d\n",po);
        else printf("Volunteer cheated!\n");
    }
    return 0;
}
