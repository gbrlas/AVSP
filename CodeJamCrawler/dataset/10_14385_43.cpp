#include<iostream>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<sstream>
#include<iomanip>
#include<cassert>
using namespace std;

int main()
{
    freopen("C-small-attempt0.in","rt",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    
    int t,R,N,K,n,total,c,sz,s;
    scanf("%d",&t);
    for(int te=1;te<=t;++te)
    {
            scanf("%d%d%d",&R,&K,&N);
            queue <int> Q;
            for(int i=0;i<N;++i)
            {
                    scanf("%d",&n);
                    Q.push(n);
            }
            sz=Q.size();
            total=0;
            for(int i=1;i<=R;++i)
            {
                    c=0;
                    s=0;
                    while(1)
                    {
                             
                             n=Q.front();
                             if((c+n)<=K  && s<sz )
                             {
                                     c+=n;
                                     s++;
                                     Q.pop();
                                     Q.push(n);
                             }
                             else break;
                    }
                    total+=c;
            }
            printf("Case #%d: %d\n",te,total);
    }
}  
            
            
