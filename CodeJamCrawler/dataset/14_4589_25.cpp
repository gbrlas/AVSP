#include<stdio.h>
#define FOR(a,b,c) for(a = b;a < c;a++)
#define REP(a,b) FOR(a,0,b)

int main()
{
	int arr[16] = {0}, arrc[16];
	int i,j,k,row,test,l,m,t;
	
	scanf("%d", &test);t = test;
	while(test--)
	{
		REP(i,16)
			arrc[i] = 0;
		scanf("%d", &row);
		l = (row - 1) * 4;
		m = l + 4;
		REP(i,16)
		{
			scanf("%d", &arr[i]);
			if(i >= l && i < m)
				arrc[arr[i]-1]++;
		}
		scanf("%d", &row);
		l = (row - 1) * 4;
		m = l + 4;
		REP(i,16)
		{
			scanf("%d", &arr[i]);
			if(i >= l && i < m)
				arrc[arr[i]-1]++;
		}
		
		j = 0;
		k = 0;
		REP(i,16)
		{
			if(arrc[i] == 2)
			{
				j++;
				k = i + 1;
			}
		}
		printf("Case #%d: ", t - test);
		if(j == 0)
			printf("Volunteer cheated!\n");
		else if(j == 1)
			printf("%d\n",k);
		else
			printf("Bad magician!\n");
	}
	return 0;
}