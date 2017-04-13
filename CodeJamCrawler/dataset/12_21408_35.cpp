//============================================================================
// Name        : Google.cpp
// Author      : Jaroslav Bucko
// Version     :
// Copyright   : Bakalarska praca
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <math.h>

int main() {

	int t=0;
	int n=0;
	int s=0;
	int p=0;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%d %d %d",&n,&s,&p);
		int total=0;
		int googler;
		int ref1=0;
		int ref2=0;
		for (int j=0;j<n;j++)
		{
			scanf("%d",&googler);
			ref1=(int)ceil(((double)googler)/3.0f);
			ref2=(int)ceil(((double)googler-ref1)/2.0f);
			//printf("Case #%d,%d: %d: %d,%d,%d",i,j,googler,ref1,ref2,ref3);
			if (ref1>=p)
			{
				total++;
			} else
			if (ref1==p-1 && ref1==ref2 && s!=0 && googler!=0)
			{
				total++;
				s--;
				//printf("*");
			}
			//printf("\n");
		}
		printf("Case #%d: %d\n",i,total);


	}


	return 0;
}
