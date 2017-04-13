#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
    double C;
    double F;
    double X;
    int QTD_CASES;
    double cRate;
    double totalTime;
    int cases = 1;

    scanf("%d",&QTD_CASES);

    while(QTD_CASES--){
        scanf("%lf %lf %lf",&C,&F,&X);
        cRate = 2.0;
        totalTime = 0.0;

        while( ((C/cRate) + (X/(cRate+F))) < (X/cRate)  ){
            totalTime += C/cRate;
            cRate += F;
        }
        totalTime += X/cRate;
        printf("Case #%d: %.7lf\n",cases,totalTime);
        cases++;
    }

return 0;
}
