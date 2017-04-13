#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,cap;
int a[20000];
int main()
{
    int cases;
    int ans = 0;
    scanf("%d",&cases);
    for (int i = 1; i <= cases; i++){
        ans = 0;
        printf("Case #%d: ",i);
        scanf("%d%d",&n,&cap);
        for (int j = 0; j < n ;j++)
            scanf("%d",a+j);
        sort(a,a+n);
        int st = 0; int ed = n-1;
        while (st <= ed)
        {
            if (st == ed){
                ans ++;
                st++;ed--;
            }else 
            if(a[ed] + a[st] <= cap){
                ans++;
                ed--;st++;
            }else{
                ans++;
                ed--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
