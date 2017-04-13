#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXN = 111;

int T, N, S, P, scores[MAXN];

int main()
{
	FILE * w = fopen("b.in", "r");

	fscanf(w, "%d", &T);
	for(int t = 1; t <= T; t++)
	{
		fscanf(w, "%d %d %d", &N, &S, &P);
		for(int i = 0; i < N; i++)
			fscanf(w, "%d", &scores[i]);
		sort(scores, scores + N);
		int answer = 0;
		for(int i = N - 1; i >= 0; i--)
		{
			if(scores[i] > 30)
				continue;
			if(P + 2 * max(P - 1, 0) <= scores[i])
				answer++;
			else if(P + 2 * max(P - 2, 0) <= scores[i] && S > 0)
			{
				answer++;
				S--;
			}
		}
		printf("Case #%d: %d\n", t, answer);
	}

	return 0;
}
