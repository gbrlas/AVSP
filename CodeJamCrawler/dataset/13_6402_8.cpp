#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <queue>
#include<vector>
using namespace std;

int constant(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 0;
    return 1;
}
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    char s[1000005];
    int T,n;
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        printf("Case #%d: ",t);
        scanf("%s",s);
        scanf("%d",&n);
        int count=0;
        long long result = 0;
        int len=0;
        for(int i=0;s[i]!='\0';i++) len++;
        for(int j=0;j<=len-n;j++) {
            for(int k=j+n;k<=len;k++) {
                count = 0;
                for(int i=j;i<k;i++) {
                    if(constant(s[i])) {
                        count++;
                        if(count >= n) {
                            result++;
                            break;
                        }
                    }
                    else {
                        count = 0;
                    }
                }
                if(count==n) {
                   // break;
                }
            }
        }
        printf("%lld\n",result);
    }
}
