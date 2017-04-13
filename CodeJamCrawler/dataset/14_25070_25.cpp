#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(void) {
    int t;
    cin>>t;

    for(int kase = 1; kase <= t; kase++) {
        double c, f, x;
        cin>>c>>f>>x;
        double num = 2*(x-c) + (f-2)*x;
        num /= (f*c);
        num = max(num, 0.0);
        int n = trunc(num);

        double time = 0.0;
        for(int i = 0; i < n; i++)
            time += c/(2+i*f);
        time += x/(2+n*f);

        cout<<"Case #"<<kase<<": ";
        printf("%.7f\n", time);
    }

    return 0;
}
