#include <iostream>
#include<cstring>
using namespace std;
#include<stdio.h>
int main() {
	freopen("B.txt","r",stdin);
	freopen("output5.txt","w",stdout);
	int k;
	scanf("%d",&k);
    for(int t=1;t<=k;t++)
    {
    	int count1=0;
        printf("Case #%d: ",t);
        int A,B,K;
        scanf("%d %d %d",&A,&B,&K);
        for(int i=0;i<A;i++)
        {
        	for(int j=0;j<B;j++)
        	if((i & j) <K) count1++;
        }
        printf("%d\n",count1);
    }
	return 0;
}
