#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[810],b[810];
int main()
{
//   freopen("A-small-attempt0.in","r",stdin);
//    freopen("A-small-attempt0.out","w",stdout);
    int ncase,k=0;
    scanf("%d",&ncase);
    while(k<ncase){
        k++;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
        }
        for(int i=0;i<n;i++){
            scanf("%d",b+i);
        }
        sort(a,a+n);
        sort(b,b+n);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum += a[i]*b[n-1-i];
        }
        printf("Case #%d: %I64d\n",k,sum);
    }
    return 1;
}

