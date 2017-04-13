#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
using namespace std;


int mas[1500];

int main()
{
	int test_count;
	cin>>test_count;
	for(int test_num=0;test_num<test_count;test_num++)
	{
		int N;
		cin>>N;
		for(int i=0;i<N;i++)
			scanf("%d",&mas[i]);
		int Sum=0, Xor=0;
		for(int i=0;i<N;i++)
		{
			Sum+=mas[i];
			Xor^=mas[i];
		}
		int best;
		sort(mas,mas+N);
		if (Xor)
			best=-1;
		else
			best=Sum-mas[0];

		if (best==-1)
			printf("Case #%d: NO\n",test_num+1);
		else
			printf("Case #%d: %d\n",test_num+1,best);
	}
	return 0;
}