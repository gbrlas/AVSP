#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
struct walk {int size; int speed; double time; };
bool operator < (walk a, walk b)
{
	return a.speed < b.speed;
}
walk W[10000];
bool wypel[1000005];
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int X, S, R, N;
		double czas;
		int ind = 0;
		scanf("%d %d %d %lf %d", &X, &S, &R, &czas, &N);
		for(int i = 0; i <= X; i++) wypel[i] = 0;
		for(int i = 0; i < N; i++)
		{
			int begin, end, vel;
			scanf("%d %d %d", &begin, &end, &vel);
			W[ind].size = end-begin;
			W[ind].speed = vel;
			ind++;
			for(int j = begin; j < end; j++) wypel[j] = 1;
		}
		for(int i = 0; i < X; i++)
		{
			if(!wypel[i])
			{
				int begin = i;
				while(!wypel[i] && i < X)
					i++;
				W[ind].size = i-begin;
				W[ind].speed = 0;
				ind++;
			}
		}
		sort(W, W+ind);

		double TIME = 0;
		for(int ktory = 0; ktory < ind; ktory++)
		{
			if(W[ktory].size <= czas*(W[ktory].speed+R))
			{
				W[ktory].time = (double)W[ktory].size/(W[ktory].speed+R);
				czas -= W[ktory].time;
				TIME += W[ktory].time;
			}
			else
			if(czas > 0)
			{
				W[ktory].time = czas + (double)(W[ktory].size - (R+W[ktory].speed)*czas)/(W[ktory].speed+S);
				czas = 0;
				TIME += W[ktory].time;
			}
			else
				TIME += (double)W[ktory].size/(W[ktory].speed+S);
		}


		printf("Case #%d: %lf\n", t, TIME);
	}
	return 0;
}
