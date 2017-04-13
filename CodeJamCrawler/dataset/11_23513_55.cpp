#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 1002

using namespace std;

vector<int>  visitou(MAXN);
vector<int>  doces;
int n;
int cmax;
int sum1, sum2, real_sum;

int check()
{
    int sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(visitou[i])
            sum1 ^= doces[i];
        else
            sum2 ^= doces[i];
    }
    
    if(sum1 == sum2 && sum1)
    {
        double real_sum = 0;
        
        for(int i = 0; i < n; ++i)
            if(visitou[i])
                real_sum += doces[i];
                
        return real_sum;
    }
    else
        return 0;
}

void solve(unsigned cur)
{   
    int res = check();
    if(res > cmax) cmax = res;
    if( cur >= doces.size() ) return;
    
    if(!visitou[cur])
    {
        solve(cur + 1);
        
        visitou[cur] = true;
        solve(cur + 1);
        visitou[cur] = false;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; ++t)
    {
        scanf("%d", &n);
        
        fill(&visitou[0], &visitou[n], 0);
        doces.clear();
        
        for(int i = 0; i < n; ++i)
        {
            int doce;
            scanf("%d", &doce);
            doces.push_back(doce);
        }
        
        cmax = 0;
        solve(0);
        
        if(cmax > 0)
            printf("Case #%d: %d\n", t, cmax);
        else
            printf("Case #%d: NO\n", t);
    }
    
    return 0;
}
