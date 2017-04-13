#include<stdio.h>
#include<stdlib.h>

int main()
{
	int T, N;
	int P[100];
	char R[100];
	char string[1000];
	int o_index=1, b_index=1;
	int o_temp=0, b_temp=0;
	int o_check=0, b_check=0;
	int result = 0;

	scanf("%d", &T);
	for(int i=0; i<T; i++)
	{
		scanf("%d", &N);
		for(int j=0; j<N; j++)
		{
			scanf("%s", string);
			R[j] = string[0];
			scanf("%s", string);
			P[j] = atoi(string);
		}
		for(int j=0; j<N; j++)
		{
			if(R[j] == 'O')
			{
				if(o_check)
					o_temp++;
				o_temp += abs(o_index-P[j]);
				o_index = P[j];
				o_check = 1;
			}
			else
			{
				if(b_check)
					b_temp++;
				b_temp += abs(b_index-P[j]);
				b_index = P[j];
				b_check = 1;
			}

			if(o_check && b_check)
			{
				if(R[j] == 'O')
				{
					result += b_temp + 1;
					if(b_temp + 1 > o_temp)
						o_temp = 0;
					else
						o_temp -= b_temp +1;
					b_temp = 0;					
					b_check = 0;
				}
				else
				{
					result += o_temp + 1;
					if(o_temp + 1 > b_temp)
						b_temp = 0;
					else
						b_temp -= o_temp +1;
					o_temp = 0;					
					o_check = 0;
				}
			}
		}
		if(o_check)
			result += o_temp+1;
		else
			result += b_temp+1;

		printf("Case #%d: %d\n", i+1, result);
		result = 0;
		o_temp = 0;
		b_temp = 0;
		o_check = 0;
		b_check = 0;
		o_index = 1;
		b_index = 1;
	}

	return 0;
}