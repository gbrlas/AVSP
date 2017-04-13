#include<iostream>
#include<algorithm>
#define MAXN 1050
using namespace std;
int main()
{
    freopen("2010e.in","r",stdin);
    freopen("2010e.out","w",stdout);
    int t;
    long long a,b,c,d,tmp,k,ans;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++){
        cin>>a>>b>>c;
        ans=0;
        while(b>a*c){
            ans++;
            c=c*c;
        }
        printf("Case #%d: ",cases);
        cout<<ans;
        printf("\n");
    }
    return 0;
}
        
        
    
