#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    
    for(int k = 1; k<=T; k++){
        unsigned long long r,t;
        scanf("%llu %llu", &r, &t);

        unsigned long long ret = 0; 
        r = r+1;
        while(t >= 2*r-1){
            ret++;
            t -= 2*r-1;
            r += 2;
        }

        printf("Case #%d: %llu\n", k, ret);
    }

    return 0;
}
