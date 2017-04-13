#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

void solveCase()
{
	vector<int> orig, sorted;
	int N, i, r, count=0;
	
	scanf("%d", &N);
	for (i=0; i<N; i++)
	{
		scanf("%d", &r);
		orig.push_back(r);
		sorted.push_back(r);
	}
	
	sort (sorted.begin(), sorted.end());
	
	for (i=0; i<N; i++)
	{
		if (sorted[i] != orig[i])
			count++;
	}
	
	printf("%.6f\n", (double)count);
}

int main()
{
	int T, i;
	
	scanf("%d", &T);
	for (i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		solveCase();
	}
	
	return 0;
}
