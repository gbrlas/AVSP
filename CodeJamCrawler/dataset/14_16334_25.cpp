#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
using namespace std;

double myMin(double a, double b){return a<b?a:b;}

int main() {
    ifstream in("B-large.in");
    //ofstream out("cookies.out");
    freopen("cookies.out","w",stdout);
    int nrt;
    double x, c, f;
    
    in>>nrt;
    for (int it=1;it<=nrt;it++) {
        in>>c>>f>>x;
        
        double ans = x/2;
        double t = 0;
        double p = 2;
        for (int i=0;;i++) {
            t+=c/p;
            p+=f;
            if (t>ans)
                break;
            ans = myMin(ans, t+x/p);
        }
        //out<<"Case #"<<it<<": "<<setprecision(7)<<ans<<"\n";
        printf("Case #%d: %.7lf\n", it, ans);
    }
    return 0;
}