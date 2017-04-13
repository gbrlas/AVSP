#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;


class Train
{
public:
	int src;
	int start;
	int end;
};

const int MAX = 1000;
Train trains[MAX];

int turnaroundTime;

class TrainPool
{
	int count;
	int time[MAX];

public:
	void reset()
	{
		count = 0;
	}

	void add(Train t)
	{
		time[count++] = t.end + turnaroundTime;
	}

	void remove(int index)
	{
		for(int i=index +1; i<count; i++)
			time[i-1] = time[i];
		count--;
	}

	bool find(int t)
	{
		for(int i=0; i<count; i++)
		{
			if(time[i] <= t)
			{
				remove(i);
				return true;
			}
		}
		return false;
	}
};

TrainPool poolA;
TrainPool poolB;

int compare(const void *aa, const void *bb)
{
	Train *a = (Train *)aa;
	Train *b = (Train *)bb;
	
	if(a->start == b->start)
		if(a->end == b->end)
			return a->src - b->src;
		else
			return a->end - b->end;
	return a->start - b->start;
}

int main()
{
	int t, i, h1, h2, m1, m2;
	int T, Na, Nb, N;

	freopen("B-large.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &T);

	for( t=1; t<=T; t++)
	{
		scanf("%d", &turnaroundTime);
		scanf("%d %d", &Na, &Nb);
		
		N = Na+Nb;

		for(i=0; i<Na; i++)
		{
			scanf("%02d:%02d %02d:%02d", &h1, &m1, &h2, &m2);
			trains[i].src = 'a';
			trains[i].start = h1 * 60 + m1;
			trains[i].end = h2 * 60 + m2;
		}
		
		for(; i<N; i++)
		{
			scanf("%02d:%02d %02d:%02d", &h1, &m1, &h2, &m2);
			trains[i].src = 'b';
			trains[i].start = h1 * 60 + m1;
			trains[i].end = h2 * 60 + m2;
		}

		qsort(trains, N, sizeof(Train), compare);
		
		int countA =0, countB = 0;
		poolA.reset();
		poolB.reset();
		
		for(i=0; i<N; i++)
		{
			if(trains[i].src == 'a')
			{
				if(poolA.find(trains[i].start) == false)
					countA++;
				poolB.add(trains[i]);
			}
			else
			{
				if(poolB.find(trains[i].start) == false)
					countB++;
				poolA.add(trains[i]);
			}
		}

		printf("Case #%d: %d %d\n", t, countA, countB	);
	}

	return 0;
}
