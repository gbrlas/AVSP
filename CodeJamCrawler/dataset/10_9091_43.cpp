#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    long t,n,k;
    scanf("%ld",&t);
    for(int i=1;i<=t;i++){
        scanf("%ld%ld",&n,&k);
        printf("Case #%d: ",i);
        if(k%(1<<n)==(1<<n)-1)
            printf("ON\n");
        else
            printf("OFF\n");
    }
    return 0;
}
