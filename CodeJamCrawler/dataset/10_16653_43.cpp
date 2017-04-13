#include<stdio.h>
#include<stdlib.h>
int T,N,K,out;
int main()
{   int q,w,e;
    freopen("A-large.in.txt","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for(q=0;q<T;q++)
    {  scanf("%d%d",&N,&K);
       for(w=0,e=1;w<N;w++,e<<=1);
       K=K%e;
       printf("Case #%d: ",q+1);
       if(K==e-1) printf("ON\n");
       else printf("OFF\n");
    }
    //system("pause");
    return 0;
}
/*
4
1 0
1 1
4 0
4 47
*/
