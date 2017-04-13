#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int mm[10005][10005];
bool jum[10005][10005];
int d[10005];
int l[10005];
int r,n,t;
bool ch(int h1,int h2)
{
        if(mm[h1][h2]==r) return jum[h1][h2];
        mm[h1][h2]=r;
        if(h2==n+1)
        {
                jum[h1][h2]=1;
                return 1;
        }
        jum[h1][h2]=0;
        //case 1
        if(d[h2]-d[h1]<=l[h2])
        {
                for(int i=h2+1;i<=n+1;i++)
                {
                        if(d[h2]+d[h2]-d[h1]>=d[i] && ch(h2,i))
                        {
                                jum[h1][h2]=1;
                                return 1;
                        }
                }
                return 0;
        }
        //case 2
        for(int i=h2+1;i<=n+1;i++)
        {                        
                if(d[h2]+l[h2]>=d[i] && ch(h2,i))
                {
                        jum[h1][h2]=1;
                        return 1;
                }
        }
        return 0;
}
main()
{
        freopen("Ain.txt","r",stdin);
        freopen("Aout.txt","w",stdout);
        scanf("%d",&t);
        for(r=1;r<=t;r++)
        {
                scanf("%d",&n);
                for(int i=1;i<=n;i++)
                {
                        scanf("%d %d",&d[i],&l[i]);
                }
                scanf("%d",&d[n+1]);
                printf("Case #%d: ",r); 
                if(ch(0,1)) printf("YES\n");
                else printf("NO\n");
        }
                //system("pause");
}
