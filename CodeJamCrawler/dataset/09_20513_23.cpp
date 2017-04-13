#include <stdio.h>
#include <stream.h>

using namespace std;

int cmp(const void *a,const void *b) {
    return *(char *)b - *(char *)a;
}

int main() {
    char num[62],nc[62];
    int chars[256];
    long long i,n,j,c,t,res,base;
    
    cin >> n;
    for (i=1;i<=n;i++) {
        for (j=0;j<256;j++)
            chars[j]=-1;
        for (j=0;j<62;j++) {
            num[j]='\0';
            nc[j]='\0';
        }
        cin >> num;
        strcpy(nc,num);
        qsort(nc,strlen(nc),sizeof(char),cmp);
        c = 1;
        for (j=1;j<strlen(nc);j++)
            if (nc[j-1]!=nc[j]) c++;
        if (c==1)
            c++;
        chars[num[0]]=1;
        t = 0;
        for (j=1;j<strlen(num);j++) {
            if (t==1) t++;
            if (chars[num[j]]==-1) {
                chars[num[j]]=t;
                t++;
            }
        }
        base = 1;
        res = 0;
        for (j=strlen(num)-1;j>=0;j--) {
            res += base*chars[num[j]];
            base *= c;
            //cout << res << " " << chars[num[j]] << endl;
        }
        cout << "Case #" << i << ": " << res << endl;
    }
}
