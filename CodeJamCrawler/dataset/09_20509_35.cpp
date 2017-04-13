#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int cmp(const void *a,const void *b) {
    return *(char *)a - *(char *)b;
}

int main() {
    long n,i,j,k;
    long t,p,q,x,y;
    long a[10],b[10];
    char in[21];
    char swap;
    
    cin >> n;
    
    for (i=1;i<=n;i++) {
        for (j=0;j<21;j++)
            in[j] = '\0';
        cin >> in;
        j=strlen(in);
        j--;
        while (1) {
            if (j==0) break;
            if (in[j-1]<in[j])
                break;
            else
                j--;
        }
        if (j!=0) {
            k = j;
            for (t=j+1;t<strlen(in);t++)
                if (in[t]>in[j-1] && in[t]<in[k])
                    k = t;
            swap = in[k];
            in[k] = in[j-1];
            in[j-1] = swap;
            qsort(in+j,strlen(in)-j,sizeof(char),cmp);
        } else {
            qsort(in,strlen(in),sizeof(char),cmp);
            in[strlen(in)] = '\0';
            for (j=strlen(in);j>1;j--)
                in[j] = in[j-1];
            in[1] = '0';
            j = 0;
            while (in[j]=='0' && j<strlen(in))
                j++;
            if (j!=strlen(in))
                swap = in[0];
                in[0] = in[j];
                in[j] = swap;
        }
        
        
        printf("Case #%ld: %s\n",i,in);
    }
    
    //system("pause");
}
