#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void) {
	// your code goes here
	int T,k,N,count,i,j,count1;
	float A[1000],B[1000];
	scanf("%d",&T);
	k=T;
	while(T--)
	{
		count=0;
		count1=0;
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%f",&A[i]);
		}
		for(i=0;i<N;i++)
		{
			scanf("%f",&B[i]);
		}
		sort(A,A+N);
		sort(B,B+N);
		for(i=N-1,j=N-1;i>=0;i--)
		{
			if(A[i]>B[j])
			{
				count++;
			}
			else
			j--;
		}
		for(i=N-1,j=N-1;i>=0;i--)
		{
			while(j>=0)
			{
				if(A[i]>B[j]) {count1++;
				j--;
				break;}
				else j--;
			}
		}
		printf("Case #%d: %d %d\n",k-T,count1,count);
	}
	return 0;
}
