#include <cstdio>
#include <algorithm>
using namespace std;

double a[2000];
double b[2000];
int main()
{
    int t;
    int n;
    scanf("%d",&t);
    for (int cases = 1; cases <= t; cases ++){
        scanf("%d",&n);
        for (int i = 0; i < n; i++){
            scanf("%lf",&a[i]);
        }
        for (int i = 0; i < n; i++){
            scanf("%lf",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        int s1 = 0; int s2 = 0;
        int e1 = n-1; int e2 = n-1;
        int win1 = 0; int win2 = 0;
        for (int i = 0; i < n; i++){
            if (a[s1] > b[s2]){
                s1++;s2++;win1++;
            }else
            {
                s1++;
            }
        }
        s1 = 0; s2 = 0;
        for (int i = 0; i < n; i++){
            while(s2 < n && b[s2] <= a[i]) s2++;
            if (s2 >= n) break;
            win2++; s2++;
        }
       printf("Case #%d: %d %d\n",cases,win1,n-win2); 
    }
    return 0;
}
