#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>

using namespace std;

int num[2][5][5];

int main()
{
//    cout << "Hello world!" << endl;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int one, two, t;
    scanf("%d",&t);
    int cal=1;
    while(t--)
    {
        scanf("%d",&one);
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
                scanf("%d",&num[0][i][j]);
        }
        scanf("%d",&two);
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
                scanf("%d",&num[1][i][j]);
        }
        int ans=0;
        int same=0;
        bool visit[20];
        memset(visit, 0, sizeof(visit));
        one--;
        two--;
        for(int i=0; i<4; i++)
        {
            visit[num[0][one][i]]=true;
        }
        for(int i=0; i<4; i++)
        {
            if(visit[num[1][two][i]])
            {
                ans++;
                same = num[1][two][i];
            }
        }
        printf("Case #%d: ",cal++);
        if(ans==0)
            printf("Volunteer cheated!\n");
        else
        if(ans==1)
        printf("%d\n",same);
        else
            printf("Bad magician!\n");
    }
    return 0;
}
