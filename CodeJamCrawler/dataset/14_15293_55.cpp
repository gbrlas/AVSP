#include <cstdio>

using namespace std;

int A[20];

void solve(int case_)
{
    int before, after;
    scanf("%d", &before);
    for (int i=1; i<=4; i++)
    {
        for (int j=1; j<=4; j++)
        {
            int a;
            scanf("%d", &a);
            if (i==before) A[a]=case_;
        }
    }

    int out=0;
    int ans=0;

    scanf("%d", &after);

    for (int i=1; i<=4; i++)
    {
        for (int j=1; j<=4; j++)
        {
            int a;
            scanf("%d", &a);
            if (A[a]==case_ && i==after)
            {
                ans++;
                out=a;
            }

        }
    }

    if (ans==1) printf("Case #%d: %d\n", case_, out);
    if (ans==0) printf("Case #%d: Volunteer cheated!\n", case_);
    if (ans>1) printf("Case #%d: Bad magician!\n", case_);
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int t=1; t<=T; t++)
    {
        solve(t);
    }
}
