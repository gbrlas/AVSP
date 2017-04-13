#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;
const int N = 2000;
double mass[2][N];
int answer,top,n;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cases = 1 ; cases <= T ; ++cases) {
        scanf("%d",&n);
        for(int i = 0 ; i < 2; ++i) {
            for(int j = 0 ; j < n ; ++j) {
                scanf("%lf",&mass[i][j]);
            }
        }
        sort(mass[0],mass[0]+n);
        sort(mass[1],mass[1]+n);
        mass[0][n] = mass[1][n] = 1e100;
        printf("Case #%d: ",cases);
        top = n-1;
        answer = 0;
        for(int i = 0 ; i < n ; ++i) {
            for(int j = n-1 ; j >= i ; --j) {
                if(mass[0][j]<mass[1][top-(n-1-j)])goto NEXT;
            }
            answer = n-i;
            break;
            NEXT:
            --top;
        }
        printf("%d ",answer);
        top = 0;
        answer = 0;
        for(int i = 0 ; i < n ; ++i) {
            while(mass[1][top] < mass[0][i])++top;
            if(top == n) {
                answer = n-i;
                break;
            }
            else {
                ++top;
            }
        }
        printf("%d\n",answer);
    }
}
