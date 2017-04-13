#include <cstdio>
#include <algorithm>
#include <vector>
#define f first
#define s second
using namespace std;
pair<pair<int,int>, pair<int,int> > lud[1005];
void show(int i){
	printf("S(%d,%d) r=%d\n", lud[i].s.f, lud[i].s.s, lud[i].f.f);
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int N, W, L;
		scanf("%d %d %d", &N, &W, &L);
		for(int i = 0; i < N; i++)
		{
			lud[i].f.s = i;
			scanf("%d", &lud[i].f.f);
		}
		sort(lud, lud+N);
		
		int kier = 1;
		int pocz = 0;
		for(int i = N-1; i >= 0; i--)
		{
			int R = lud[i].f.f;
			if(pocz == 0) pocz = -R;
			if(pocz == W) pocz = W+R;

			if(pocz+lud[i].f.f > W)
			{
				pocz = W+R;
				kier = -1;
			}
			else if(pocz-R < 0)
			{
				pocz = -R;
				kier = 1;
			}
//			printf("KIER: %d\n", kier);
			int poziom = -R;
			for(int j = N-1; j > i; j--)
			{
				int bpocz = pocz;
				if(kier == -1)
					bpocz-=2*R;
				if(lud[j].s.f-lud[j].f.f < bpocz+2*R && lud[j].s.f+lud[j].f.f > bpocz)
				{
					poziom = max(poziom, lud[j].s.s+lud[j].f.f);
//					show(j);
//					printf("Poziom: %d\n", poziom);
				}
			}
			lud[i].s.f = pocz+kier*R;
			lud[i].s.s = poziom+R;
//			printf("wpisano: ");
//			show(i);
			pocz += kier*2*R;
//			printf("-> nowy pocz: %d\n", pocz);
		}
		for(int i = 0; i < N; i++)
			lud[i].f.f = lud[i].f.s;
		sort(lud, lud+N);
		printf("Case #%d: ", t);
		for(int i = 0; i < N; i++)
			printf("%d.0 %d.0 ", lud[i].s.f, lud[i].s.s);
		printf("\n");
	}
	return 0;
}
