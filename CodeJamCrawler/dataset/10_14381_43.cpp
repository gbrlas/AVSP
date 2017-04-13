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
    freopen("A-large.in","rt",stdin);
    freopen("A-large.out","w",stdout);
    
    int t,N,K,c;
    scanf("%d",&t);
    for(int te=1;te<=t;++te)
    {
            scanf("%d%d",&N,&K);
            c=0;
            for(int i=0;i<N;++i) 
            {
                    
                    if(K&(1<<i))
                    {
                                //cout<<i<<endl;
                                c++;
                    }
            }
            if(c==N)printf("Case #%d: ON\n",te);
            else printf("Case #%d: OFF\n",te);
    }
}
