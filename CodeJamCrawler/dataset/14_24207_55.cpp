#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    double c, f, x;
    int t;
    scanf("%d",&t);
    int cal=0;
    while(t--)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        int n=1;
        double Max = x/2;
        double t=0;
        while(true)
        {
            t+=c/(2+f*(n-1));
            if(t+x/(2+f*n)<Max)
                Max = t+x/(2+f*n);
            else
                break;
            n++;
        }
        printf("Case #%d: %.7f\n",++cal,Max);
    }
    return 0;
}
