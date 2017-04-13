using namespace std;
#include<iostream>
#include<cstdio>
int main()
{   int i,T,j,N,cases=0;
    long long K,P;
    scanf("%d",&T);
    while(T--)
    {   cases++; P=1;
        scanf("%d %lld",&N,&K);
        for(j=0;j<N;j++) P*=2;
        K%=P;
        printf("Case #%d: ",cases);
        if(K==P-1)
          printf("ON\n");
        else
          printf("OFF\n");
    }
    return 0;
}           
               
           
