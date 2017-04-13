#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#pragma warning (disable:4996)

const int MAX = 10001;

class FREQ
{
public:
	int letter;
	int count;
}freq[MAX];

int compare(const void *aa, const void *bb)
{
	const FREQ * a = (const FREQ * )aa;
	const FREQ * b = (const FREQ * )bb;
	return b->count - a->count;
}

int main()
{
	int t, T;
	int i, P, K, L;
	int count;
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("asmall.out", "w", stdout);

	scanf("%d", &T);
	
	for( t=1; t<=T; t++ )
	{
		scanf("%d %d %d", &P, &K, &L);
		for(i=0; i<L; i++)
		{
			scanf("%d", &count);
			freq[i].letter= i;
			freq[i].count = count;
		}
		qsort(freq, L, sizeof(FREQ), compare);
		
		__int64 press = 0;
		__int64 key = 1;
		__int64 pp = 1;

		for(i=0; i<L; i++)
		{
			press += pp * freq[i].count;
			if(key < K)
				key++;
			else
			{
				key = 1;
				pp++;
			}
		}

		printf("Case #%d: %I64d\n", t, press);
	}

	return 0;
}
