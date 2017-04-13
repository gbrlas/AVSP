#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("temp.txt","w",stdout);
	
	int t,c=1,n,k,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			if(!(k&(1<<i)))
				break;
		printf("Case #%d: ",c++);
		if(i==n)
			printf("ON\n");
		else printf("OFF\n");
	}
}
