#include <stdio.h>
#include <algorithm>
using namespace std;

double C,F,X,answer,cost;
const double eps = 1e-6;

int main() {
    //freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int t = 1 ; t <= T ; ++t) {
        scanf("%lf%lf%lf",&C,&F,&X);
        answer = X/2;
        cost = 0;
        for(int i = 1 ; cost < answer+eps;++i) {
            cost += C/(2+(i-1)*F);
            answer = min(answer,cost+X/(2+i*F));
        }
        printf("Case #%d: ",t);
        printf("%0.7lf\n",answer);
    }
}
