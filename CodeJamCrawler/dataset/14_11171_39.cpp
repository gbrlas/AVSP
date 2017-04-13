#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long int t;
    double c,f,x;
    double store,rate,time;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>c>>f>>x;
        rate=2.000;
        time=0.0000;
        store = ((c-x)/rate)+(x/(rate+f));
        while(store<0.0000000)
        {
            time = time + (c/rate);
            rate+=f;
            store = ((c-x)/rate)+(x/(rate+f));
        }
        time= time + (x/rate);
        printf("Case #%d: %.7lf\n",k,time);

    }
    return 0;
}
