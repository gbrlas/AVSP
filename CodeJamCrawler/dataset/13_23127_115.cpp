// c_large.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>

//First generate all fair square numbers within 10^14 and store in an Array :)
unsigned __int64 arr[]={1,4,9,121,484,
	10201,12321,14641,40804,44944,
	1002001,1234321,4008004,
	100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,
	10000200001,10221412201,12102420121,12345654321,40000800004,
	1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,
	1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};


int _tmain(int argc, _TCHAR* argv[])
{
		freopen("input_large.in","r",stdin);
	freopen("output.out","w",stdout);
	int T,t;
	unsigned __int64 A,B;
	int i,count;
	scanf("%d",&T);
	t=0;
	while(T--)
	{
		t++;
		count=0;
		scanf("%llu %llu",&A,&B);
		for(i=0;i<39;i++)
			if(arr[i]>=A&&arr[i]<=B)count++;
		printf("Case #%d: %d\n",t,count);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

