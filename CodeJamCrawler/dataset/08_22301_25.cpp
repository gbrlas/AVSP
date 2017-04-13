/*
    Author: Marcin Sasinowski
*/
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

#define SZ(a) ((a).size())
#define PB push_back
#define ALL(x) (x).begin(),(x).end()

int t,n;
int q,s;
int cas = 1;
int tab[1000][1000];
string eng[1000];

int main()
{
    scanf("%d\n", &t);
    while(t--)
    {
        for(int i=0;i<1000;++i)
            for(int j=0;j<1000;++j)
                tab[i][j] = 0;
        scanf("%d\n", &q);
        for(int i=0;i<q;++i)
        {
            string r;
            char kl;
            while( kl=getchar(), kl!='\n')
                r += kl;
            eng[i] = r;
        }

        scanf("%d\n", &s);
        for(int i=0;i<1001;++i)
            tab[0][i] = 0;
        for(int j=1;j<=s;++j)
        {
            string r;
            char kl;
            while(kl=getchar(), kl!='\n')
                r+=kl;

            for(int i=0;i<q;++i)
            {
                tab[j][i] = tab[j-1][i];

                if(r == eng[i])
                {
                    int minn = 10000;
                    for(int k=0;k<q;++k)
                        if(i!=k)
                            if(tab[j-1][k]+1<minn)
                                minn = tab[j-1][k]+1;
                    tab[j][i] = minn;
                }
                else
                {
                    for(int k=0;k<q;++k)
                        if(i!=k)
                            if(tab[j-1][k]+1<tab[j][i])
                                tab[j][i] = tab[j-1][k]+1;
                }
            }
        }

        int minn = 10000;
        for(int i=0;i<q;++i)
            if(minn>tab[s][i])
                minn = tab[s][i];

        printf("Case #%d: %d\n", cas++,minn);

    }
    return 0;
}