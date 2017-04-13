#include <cstdio>
char kto[1000];
int gdzie[1000];
int max(int a, int b) { return a>b ? a : b; }
int abs(int a) {return a>0 ? a : -a; }
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int n, poz[2] = {1,1}, sek = 0, ocz[2] = {0,0};
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			char robot;
			int dest;
			scanf(" %c %d", &robot, &dest);
			if(robot == 'O') robot = 0; else robot = 1;
			int plus = max((abs(dest-poz[robot]))-ocz[robot], 0) + 1;
			poz[robot] = dest;
			ocz[robot] = 0;
			ocz[!robot] += plus;
			sek += plus;
		}
		printf("Case #%d: %d\n", t, sek);
	}
}

