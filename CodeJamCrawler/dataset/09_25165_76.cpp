
#include<iostream>
using namespace std;
int l , d , n;
int date[20][2];
int datel ;
char ct[20];
int ans = 0;
char ck[5010][18];
char cc[100000];
void date_in()
{
    int i;
    for( i = 0 ; i < d ; ++i)
    {
            scanf("%s",ck[i]);
    }
    datel = 0;
    int j;
    for( i =1 ; i <= n ; ++i)
    {
        printf("Case #%d: ",i);
        scanf("%s",cc);
        int len = strlen( cc);
       // cout << cc << endl;
        memset( date , 0 , sizeof(date));
        datel = 0;
        ans = 0;
        for(j = 0 ;j < len ; )
        {
            if( cc[j] != '(')
            {
                date[datel][0] = date[datel][1] = j;
                datel ++;
                j ++;
            }
            else
            {
                int s;
                for( s = j + 1 ;s < len  ;++s)
                {
                    if( cc[s] == ')') break;
                }
                s --;
                date[datel][0] = j + 1 ;
                date[datel][1] = s;
                j = s + 2;
                datel ++;
            }
        }

        int r,t,k;

        for( r = 0 ; r < d ; ++r)
        {
            for( t = 0 ; t < l ; ++t)
            {
                for( k = date[t][0] ; k <= date[t][1] ; ++k)
                {
                    if( cc[k] == ck[r][t]) break;
                }
                if( k == date[t][1] + 1) break;
            }
            if( t == l) ans ++;
        }
        printf("%d\n",ans);
    }
}
int main()
{
    while( scanf("%d %d %d\n",&l,&d,&n) != EOF)
    {
        date_in();
    }
    return 0;
}
