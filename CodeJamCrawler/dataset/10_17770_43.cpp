#include <iostream>
using namespace std;

int main()
{
	int T, N, K;

	scanf("%d", &T);
	bool yes;
	for(int i = 1; i <= T; i++)
	{
		scanf("%d%d", &N, &K);
		if(((K+1)&(-K-1))>=(1<<N))
		{
			yes = true;
		}
		else
		{
			yes = false;
		}
		
		printf("Case #%d: ", i);
		if(yes)
			printf("ON\n");
		else
			printf("OFF\n");
	}
}
