#include <cstdlib>
#include <cstdio>

int main()
{
    FILE * in = fopen("D-large.in","r");
    FILE * out = fopen("out.txt","w+");
    int t;
    fscanf(in,"%d",&t);
  //  scanf("%d",&t);
    for(int count = 1;count <= t;count++){
        int n;
        fscanf(in,"%d",&n);
      //  scanf("%d",&n);
        int num[n], c = 0;
        for(int i = 0;i < n;i++){
            fscanf(in,"%d",&num[i]);
         //   scanf("%d",&num[i]);
            if(num[i] == i + 1) c++;
        }
        printf("Case #%d: %d.000000\n",count,n - c);
        fprintf(out,"Case #%d: %d.000000\n",count,n - c);
    }
    system("PAUSE");
    return 0;
}
