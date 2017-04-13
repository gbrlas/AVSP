#include <cstdio>
#include <algorithm>
using namespace std;


long double cost, final, spawn;


void solve(int case_)
{
    long double base_time=0.0;
    scanf("%llf %llf %llf", &cost, &spawn, &final);

    long double out=0.0;
    out=final/2.0;
    long double current_rate=2.0;
    long double base_amount=0.0;

    while (base_amount<=final/cost)
    {
        if (base_time<out)
        {
            base_amount+=1.0;
            base_time+=(cost/current_rate);
            current_rate+=spawn;
            out=min(out, base_time+(final/current_rate));
        }
    }
    printf("Case #%d: %llf\n", case_, out);


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
