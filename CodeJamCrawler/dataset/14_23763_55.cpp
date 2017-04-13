#include<cstdio>
#include<algorithm>
using namespace std;
double Naomi[1005];
double Ken[1005];
int N;
bool check(int st)
{
    int i,j;
    for(i=st; i<=N; i++)
    {
        if(!(Naomi[i]>Ken[i-st+1]))  return false;
    }
    return true;
}
int main()
{
    int i,j,T,it,ken,naomi;
    int opt,dec;
    //freopen("D-large.in","r",stdin);
    //freopen("Deceit.out","w",stdout);
    scanf("%d",&T);
    for(it=1; it<=T; it++)
    {
        scanf("%d",&N);
        for(i=1; i<=N; i++)  scanf("%lf",&Naomi[i]);
        for(i=1; i<=N; i++)  scanf("%lf",&Ken[i]);
        sort(Naomi+1,Naomi+1+N);
        sort(Ken+1,Ken+1+N);
        /*for(i=1; i<=N; i++) printf(" %.3lf",Naomi[i]);
        puts("");
        for(i=1; i<=N; i++) printf(" %.3lf",Ken[i]);
        puts("");*/
        ken=0;
        for(i=1,j=1; i<=N && j<=N; i++,j++)
        {
           while(j<=N && Naomi[i]>Ken[j]) j++;
           if(j<=N)
           {
               //printf("i:%d j:%d\n",i,j);
               ken++;
           }
        }
        opt=N-ken;

        ken=0;naomi=0;
        int st=1;
        while(st<=N && !check(st))
        {
           st++;
        }
        //printf("%d\n",st);
        dec=N-st+1;
        printf("Case #%d: %d %d\n",it,dec,opt);

    }
    return 0;
}
