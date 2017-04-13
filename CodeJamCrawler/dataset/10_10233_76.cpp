#include <iostream>
using namespace std;
#include <stdio.h>
__int64 P[40];
int main()
{
    int N,T,i;
    __int64 K;
	freopen("A-large.in","r",stdin);
	freopen("B.out","w",stdout);
    scanf("%d",&T);
    for(i=1,N=2;i<=30;i++,N*=2) P[i]=N;
    for(i=1;i<=T;i++)
    {
		printf("Case #%d: ",i);
		scanf("%d%I64d",&N,&K);
		if((K+1)%P[N]==0) printf("ON\n");
		else printf("OFF\n");
    }
    return 0;
}
