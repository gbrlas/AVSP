#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

long long bases[3000000][10];

int main() {
    long n,i,j,k;
    long t,p,q,x,y;
    long a[10],b[10];
    
    cin >> n;
    
    for (i=1;i<=n;i++) {
        cin >> t;
        p = t;
        for (j=0;j<10;j++)
            a[j]=0;
        while (p) {
            a[p%10]++;
            p/=10;
        }
        //printf("a: %ld %ld %ld %ld %ld %ld\n",a[1],a[2],a[3],a[4],a[5],a[6]);
        while (1) {
            t++;
            p = t;
            for (j=0;j<10;j++)
                b[j]=0;
            while (p) {
                b[p%10]++;
                //printf("%ld b[1]:%ld\n",p%10,b[2]);
                p/=10;
            }
        //printf("%ldb: %ld %ld %ld %ld %ld %ld\n",t,b[1],b[2],b[3],b[4],b[5],b[6]);
            k=1;
            for (j=1;j<10;j++) {
               k = k && (a[j] == b[j]);
               //printf("%d=%d\n",a[j],b[j]);
            }
            if (k)
                break;
            //system("pause");
        }
        printf("Case #%ld: %ld\n",i,t);
    }
    
    //system("pause");
}
