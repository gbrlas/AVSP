#include<cstdio>
#include<cstring>
int map[128];
int t[30]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
void init()
{
    for(int i='a',j=0;i<='z';i++,j++)
        map[i]=t[j];
}
char s[1000010];
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int n;
    init();
    scanf("%d",&n);
    gets(s);
    for(int i=1;i<=n;i++)
    {

        gets(s);
        int l=strlen(s);
         printf("Case #%d: ",i);
        for(int j=0;j<l;j++)
            if(s[j]>='a'&&s[j]<='z')
                putchar(map[s[j]]);
            else
                putchar(s[j]);
        printf("\n");
    }

}