#include<stdio.h>
#include<string.h>
#include<math.h>
int bigsort(const void *a,const void *b) {
    return *(int *)b-*(int *)a;
}

int smallsort(const void *a,const void *b) {
    return *(int *)a-*(int *)b;
}

int main(void) {
    FILE* out=fopen("e:/out","w");
    int a[10],b[10];
    int t,n,i,j,c=0;
    scanf("%d",&t);
    while(t-->0) {
        c++;
        scanf("%d",&n);
        for(i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++) {
            scanf("%d",&b[i]);
        }
        qsort(a,n,sizeof(int),bigsort);
        qsort(b,n,sizeof(int),smallsort);
        int s1=0,s2=0;
        for(i=0;i<n;i++) {
            s1+=a[i]*b[i];
            s2+=a[n-1-i]*b[n-1-i];
        }
        fprintf(out,"Case #%d: %d\n",c,s1<s2?s1:s2);
    }
    system("pause");
    return 0;
}
