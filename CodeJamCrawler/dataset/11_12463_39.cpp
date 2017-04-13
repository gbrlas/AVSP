#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


const double eps=1e-8;
const int MaxN=555;
int n,m,d;
double a[MaxN][MaxN],midi,midj,sumi,sumj;
int ans;


int main()
{    
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    
    int Testnum;
    cin>>Testnum;
    for (int Test=1; Test<=Testnum; ++Test) 
    {
        printf("Case #%d: ",Test);
        scanf("%d %d %d\n",&n,&m,&d);
        for (int i=1; i<=n; ++i) 
        {
            for (int j=1; j<=m; ++j) 
            {
                char c;
                scanf("%c",&c);
                a[i][j]=double(c-'0');
            }
            scanf("\n");
        }
     
        ans=0;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j)
            {
                int pp;
                pp=min(n,m);
                for (int len=3; len<=pp; ++len) 
                {
                    if ((i+len-1>n)||(j+len-1>m)) continue;
                    midi=double(i+i+len-1)/2;
                    midj=double(j+j+len-1)/2;
                    sumi=0;
                    sumj=0;
                    for (int ii=i; ii<=i+len-1; ++ii)
                        for (int jj=j; jj<=j+len-1; ++jj) 
                        {
                            if (ii==i&&jj==j) continue;
                            if (ii==i&&jj==j+len-1) continue;
                            if (ii==i+len-1&&jj==j) continue;
                            if (ii==i+len-1&&jj==j+len-1) continue;
                            sumi+=(ii-midi)*a[ii][jj];
                            sumj+=(jj-midj)*a[ii][jj];
                        }
                    if ((abs(sumi)<eps)&&(abs(sumj)<eps)) ans=max(ans,len);
                }
            }
                
        if (!ans) printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }    
    return 0;
}
