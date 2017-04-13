#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#pragma warning (disable:4996)

const int MAX = 1000;
const int LEN = 150;

char searchEngine[MAX][LEN];
char query[LEN];
int switchCount[MAX];

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int main()
{
	int t;
	int S, Q, T;
	int i;
	
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	scanf("%d", &T);
	
	for( t=1; t<=T; t++ )
	{
		scanf("%d \n", &S);
		
		for(i=0; i<S; i++)
		{
			fgets( searchEngine[i], LEN, stdin );
			searchEngine[i][strlen(searchEngine[i])-1] = 0;
			switchCount[i] = 0;
		}
		qsort(searchEngine, S, LEN, compare);
		
		scanf("%d \n", &Q);
		for(i=0; i<Q; i++)
		{
			fgets( query, LEN, stdin );
			query[strlen(query)-1] = 0;
			
			char *se = (char *)bsearch(query, searchEngine, S, LEN, compare);
			int pos;

			if(se != 0)
			{
				pos = ((int)se - (int)searchEngine) / LEN;
				int minValue = -1;
				
				// find minimum switch Count
				for(int j=0; j<S; j++)
					if(switchCount[j] != -1 && (minValue == -1 || minValue > switchCount[j]))
						minValue = switchCount[j];

				for(int j=0; j<S; j++)
					if(switchCount[j] == -1)
						switchCount[j] = minValue + 1;
				switchCount[pos] = -1;
			}
		}

		int minCount = -1;
		for(int j=0; j<S; j++)
			if(switchCount[j] != -1 && (minCount == -1 || switchCount[j] < minCount))
				minCount = switchCount[j];
		printf("Case #%d: %d\n", t, minCount);
	}

	return 0;
}
