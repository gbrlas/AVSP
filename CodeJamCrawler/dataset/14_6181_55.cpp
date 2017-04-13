#include <iostream>
#include<iomanip>
#include<cstdio>
using namespace std;

int main()
{
    int T;
    freopen("B-large.in", "r", stdin);
freopen("B-large.out", "w", stdout);
    cin>>T;

    for(int i=0; i<T;)
    {
        double prev_time,cur_time;
        double farm_cost=0.0;
        double rate=2.0;
        double C,F,X;

        cin>>C>>F>>X;

        cur_time=X/rate;
        prev_time=cur_time+1;
        while(cur_time<prev_time)
        {
            prev_time=cur_time;
            farm_cost+=C/rate;
            rate+=F;
            cur_time=farm_cost+X/rate;
        }

        cout<<"Case #"<<++i<<": "<<std::fixed<<std::setprecision(7)<<prev_time<<"\n";
}
    }

