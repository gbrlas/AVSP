#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int numset[5] = {1,4,9,121,484};
int main()
{
	freopen("D:\\data.in","r",stdin);
	freopen("D:\\data.out","w",stdout);
	int count = 0;
	cin >> count;
	for (int c = 1; c<=count;c++)
	{
		int start = 0;
		int end = 0;
		int r = 0;
		cin >> start >> end;
		for (int i = 0; i < 5; i++)
		{
			if (start <= numset[i] && end >= numset[i])
			{
				r++;
			}
		}
		printf("Case #%d: %d\n",c,r);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}