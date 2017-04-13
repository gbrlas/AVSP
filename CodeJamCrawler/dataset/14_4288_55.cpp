#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int testcases, i;
    long double farm_price, rate, farm_rate, total_cookies, time;
    
    cin >> testcases;
    for(i = 1; i <= testcases; i++)
    {
        cin >> farm_price >> farm_rate >> total_cookies;
        rate = 2.0;
        time = 0.0;
        
        while(1)
        {
            if(farm_price/rate + total_cookies/(rate+farm_rate) < total_cookies/rate)
            {
                time += farm_price/rate;
                rate += farm_rate;
            }
            else
            {
                time += total_cookies/rate;
                break;
            }
        }
        
        printf("Case #%d: %.7Lf\n", i, time);
    }
}
