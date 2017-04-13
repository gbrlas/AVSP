#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

long long bases[100000][10];

int main() {
    long long n,i,j,k;
    long long t,p,q,x,y;
    int a[10];
    
    cin >> n;
    for (i=1;i<100000;i++)
        for (j=2;j<=10;j++) {
            if (i==1) {
                bases[i][j] = 1;
            } else {
                x = i;
                y = 0;
                //printf("%d\n",i);
                while (y<100) {
                    p = 0;
                    while (x>0) {
                        p += (x%j)*(x%j);
                        x /= j;
                    }
                    x = p;
                    if (x==1)
                        break;
                    y++;
                }
                if (x==1)
                    bases[i][j] = 1;
                else
                    bases[i][j] = 0;
            }
        }
        
    //printf("f(%d,%d)=%d\n",3,3,bases[3][3]);
    for (i=1;i<=n;i++) {
        k = 1;
        scanf("%d",&a[0]);
        while(getchar()!='\n') {
            scanf("%d",&a[k++]);
        }
        j = 2;
        while (1) {//bases[j][t]==0 || bases[j][p]==0)
            p = 1;
            for (t=0;t<k;t++)
                p = p && (bases[j][a[t]]==1);
            if (p==1)
                break;
            j++;
        }
        cout << "Case #" << i << ": " << j << endl;
    }
    system("pause");
}
