#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("D-large-in.txt", "r", stdin);
    freopen("D-large-out.txt", "w", stdout);
    int nCases, _case = 1;
    int n;
    double num1[1001], num2[1001];
    int rank1[1001];
    int tmp, ans1, ans2;
    scanf("%d", &nCases);
    while(_case <= nCases){
        scanf("%d",&n);
        for(int i = 1; i <= n;i++){
            scanf("%lf", &num1[i]);
        }
        for(int i = 1; i <= n;i++){
            scanf("%lf", &num2[i]);
        }
        sort(num1+1, num1+n+1);
        sort(num2+1, num2+n+1);
        tmp = 1;
        for(int i = 1; i <= n; i++){
            while(tmp <= n && num1[tmp] < num2[i]){
                tmp++;
            }
            rank1[i] = tmp-1;
        }
        ans1 = 0;
        for(int i = 1; i <= n; i++){
            if(rank1[i]+1-i > ans1){
                ans1 = rank1[i]+1-i;
            }
        }
        ans1 = n-ans1;
        ans2 = rank1[1]>1?1:rank1[1];
        for(int i = 2; i <= n; i++){
            if(rank1[i] > ans2){
                ans2++;
            }
        }
        ans2 = n-ans2;

        printf("Case #%d: %d %d\n", _case++, ans1, ans2);
        /*for(int i = 1; i <= n; i++){
            printf("%.5lf\t", num2[i]);
        }
        printf("\n");
        for(int i = 1; i <= n; i++){
            printf("%d\t", rank1[i]);
        }
        printf("\n");*/
    }
    return 0;
}
