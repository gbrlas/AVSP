#include<stdio.h>
#define max 2000000
bool vis[max];
int main()
{
	int T = 0;
	int t = 0;
	int mapping[8] = { 0, 0, 1, 3, 6, 10, 15, 21 };
	scanf("%d", &T);
	while(t++ < T)
	{
		int pairs = 0;
		int A = 0, B = 0;
		int M = 1000000;
		int digits = 7;
		int temp = 0;
		int i = 0, j = 0;
		scanf("%d%d", &A, &B);
		while(M > A)
		{
			M /= 10;
			digits--;
		}
		for(i = digits; i > 0; i--)
			temp = temp*10+1;
		for(i = 1; i <= 9; i++)
			vis[temp*i] = 1;
		for(i = A; i <= B; i++)
		{
			if(vis[i])
				vis[i] = 0;
			else
			{
				int num = i;
				int valid = 1;
				valid = 1;
				for(j = 1; j < digits; j++)
				{
					num = (num%M)*10+num/M;
					if(num >= A && num <= B && num > i && !vis[num])
					{
						valid++;
						vis[num] = 1;
					}
				}
				pairs += mapping[valid];
			}
		}
		printf("Case #%d: %d\n", t, pairs);
	}
	return 0;
}